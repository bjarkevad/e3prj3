/**
 * @file
 * @author Bjarke Vad Andersen
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 * Contains:\n
 * - The Psoc class, which is used to connect to a PSoC5 device through a PsocNode object\n
 * - The psocTransmitData and psocRecData enumerators\n
 * - The QScopedLock class, which locks a QMutex when it is in scope\n
 * - The QThreadX class, which is used to impelement threads\n
 * - The PsocNode class, which is used to communicate with a PSoC5 device through a device node\n
 * @endsection1
 */

#ifndef PSOC_H
#define PSOC_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QMutex>

/**
 * @brief The psocTransmitData enum, used the make hex values readable by humans. The values are sent to the PSoC5
 */
enum psocTransmitData {
    PSOC_MEASURE = 0x4D, //!< Is sent when the reaming fluid in a bottle is requested. Should be followed by a PSOC_BOTTLE command.
    PSOC_DONETRANS = 0x51, //!< Unused in the current implementation.
    PSOC_RESET = 0x52, //!< Is used for debugging.
    PSOC_BOTTLE = 0x40,//!< Represents the ID of a bottle, should be followed by ID(e.g. (PSOC_BOTTLE + 1) for bottle no. 1.
    PSOC_TEST = 0x54, //!< A test function, used to test connection to the PSoC5
};
//NOTE: These should be updated for testing with an actual PSOC
/**
 * @brief The psocRecData enum, used to make hex values readable by humans. These values are sent from the PSoC5
 */
enum psocRecData {
    PSOC_R_NOGLASS = 0x4E, //!< Is sent when no glass is present.
    PSOC_R_STARTMIX = 0x53,//!< Is sent when the PSoC5 succesfully started mixing a drink.
    PSOC_R_DONEMIX = 0x46, //!< Is sent when the PSoC5 is done mixing a drink.
    PSOC_R_OK = 0x54,//!< Is sent as a response to "PSOC_TEST" from the DevKit.
};

/**
 * @brief The QScopedLock class. Used to lock a QMutex only when in scope.
 */
class QScopedLock
{
public:
    /**
     * @brief Constructor, locks a QMutex when an object is initiated
     * @param mut_ Address of the QMutex to lock
     */
    QScopedLock(QMutex &mut_)
    {
        mutex = &mut_;
        mutex->lock();
    }
    /**
     * @brief Destructor, unlocks the QMutex.
     */
    ~QScopedLock()
    {
        mutex->unlock();
    }

private:
    /**
     * @brief A local copy of the address of the QMutex.
     */
    QMutex *mutex;
};

/**
 * @brief The QThreadX class, this is used to make the use of threads much more object oriented.
 *
 * Reimplements the virtual function QThread::run() to call exec().
 * This makes it possible to move any object of basetype QObject to a seperate thread,
 * by calling:\n myQObject.moveToThread(myQThreadX);
 */
class QThreadX : public QThread
{
protected:
    /**
     * @brief Reimplements run() from QThread to call exec();
     */
    void run() {this->exec();}
};

/**
 * @brief The PsocNode class connects to a PSoC5 device though a node.
 *
 *
 */
class PsocNode : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor, sets the path of the node.
     * @param device_ The path of the PSoC node, typically "/dev/psoc".
     */
    PsocNode(QObject *parent = 0, QString device_ = "");

    /**
     * @brief Sets the path of the PSoC node.
     * @param device_ The path of the PSoC node, typically "/dev/psoc".
     */
    void setDev(QString device_)
    {
        device = device_;
    }

private:
    /**
     * @brief A QString containing the path to the PSoC node which is written and read from.
     */
    QString device;
    /**
     * @brief A FILE pointer that represents the device node.
     *
     * When "fopen" is called, it returns a FILE pointer that is saved in this variable, after that it is possible to
     * read and write data directly to the device node, by using "fread()" and "fwrite()".
     * When the application is done using the node, it is closed with "fclose()".
     */
    FILE *psocFile;
    /**
     * @brief A QMutex to prevent two threads to call "writePsoc()" at once.
     *
     * This mutex is used with QScopedLock to lock the "writePsoc()" function, until it is done with the PSoC node.
     * This prevent two threads from writing or reading from the node at once, which will cause problems due to the PSoC
     * kernel module design.
     */
    QMutex writeMutex;

public slots:
    //A dynamically allocated "data" must be parsed, or the program will most likely crash.
    /**
     * @brief Writes data to the PSoC, and awaits a response.
     *
     * Data is written to the device node, and "fread()" is called waiting for a response.
     * This will block until data is received or the node sends its timeout result.
     * The function then sends the received data as a signal, closes the device node and calls delete on "dataToSend".
     * @param data The data to be send, represented as a unsigned char*.
     * Should always be dynamically allocated, to prevent trying to write data that no longer exists.
     * @param len The length of the "data" array.
     */
    void writePsoc(unsigned char *data, int len);

signals:
    /**
     * @brief The signal that is sent when data is received.
     *
     * If only a single byte is received, this signal is sent with the received data.
     * @param data The single byte array of data received.
     */
    void receivedDataSig(unsigned char *data);
    /**
     * @brief The signal that is sent if bottle status data is received.
     *
     * If two bytes are received, this signal is sent with the received data.
     * "receivedDataSig()" and "receivedBottStatus()" are split into two signals to make it simple to connect to the Psoc class.
     * @param data The two byte long array of data received.
     */
    void receivedBottStatus(unsigned char *data);

};

/***************************************/

/**
 * @brief The Psoc class provides a simple interface for the PsocNode class.
 *
 * To make it simple to connect to a PSoC5 device, this class acts as an interface between the MainWindow
 * and PsocNode class. It runs a PsocNode in a seperate thread, which prevents the GUI from freezing.
 */
class Psoc : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor, creates a thread, nodeThread, that runs the PsocNode, and starts said thread.
     * It then connects the nodeThread to internal functions, so that when the PsocNode receives data,
     * it becomes available to the Psoc object.
     * @param device_ The path to the PSoC5 node, typically "/dev/psoc".
     */
    explicit Psoc(QObject *parent = 0, QString device_ = "");

    /**
     * @brief Destructor, waits for the nodeThread to finish, and deletes the PsocNode afterwards.
     */
    ~Psoc()
    {
        delete node;
    }

public slots:
    /**
     * @brief Write data to the PSoC5 device.
     *
     * Writes data to the PSoC5 device in the form of an "unsigned char" array.
     * @param dataToWrite The array containing the data that should be written to the device.
     * @param len The length of the "dataToWrite" array.
     */
    void write(unsigned char *dataToWrite, int len);
    /**
     * @brief The function that is called when data is received from the device.
     *
     * Processes the data received from the PSoC5 device, and emits signals accordingly.
     * If the received data has unknown characteristics, an error is sent.
     * @param receivedData The data received from the PSoC5.
     */
    void receive(unsigned char* receivedData);
    /**
     * @brief The function that is called when bottle status is received.
     *
     * Processes the bottle status data received from the PSoC5 device,
     * and emits it as a signal. Instead of sending the hex ID of the bottle,
     * the ID is converted to a number between 1 and 6. The ID is followed by the percentage of fluid left in the bottle.
     * @param receivedData
     */
    void receiveBottStatus(unsigned char* receivedData);

signals:
    /**
     * @brief Signal that is emitted when no glass is present.
     */
    void noGlass();
    /**
     * @brief Signal that is emmited when the PSoC5 signals that mixing a drink is started.
     */
    void mixStarted();
    /**
     * @brief Signal that is emmited when the PSoC5 signals that it is done mixing a drink.
     */
    void doneMixing();
    /**
     * @brief Signal that is emmited when the status of the PSoC5 is requested.
     *
     * Can return "OK" and "Error" in the current implementation,
     * this is done to enable direct use of the value in for example test labels.
     *
     * @param status the status of the PSoC5 device in a QString.
     */
    void psocOk(QString status);
    /**
     * @brief Contains the status of a bottle.
     * @param bootleId The ID of the bottle.
     * @param value The percentage of fluid left in the bottle with ID "bottleId".
     */
    void psocBottResponse(unsigned char bootleId, unsigned char value);
    /**
     * @brief A signal that is used to communicate with the nodeThread.
     *
     * Sends data to the PSoC5 thread that should be written to the device.
     * @param dataToWrite The array of data to write.
     * @param len The length of the dataToWrite array.
     */
    void psocWrite(unsigned char* dataToWrite, int len);

private:
    /**
     * @brief A PsocNode pointer
     *
     * Used to communicate with the PSoC5 device in a seperate thread.
     */
    PsocNode* node;
    /**
     * @brief The path to the PSoC5 device.
     */
    QString device;
    /**
     * @brief The thread in which communication with the device happens.
     *
     * This uses the reimplemented QThreadX class to enable "moveToThread()".
     * This makes use of threads a lot more simple and readable.
     */
    QThreadX nodeThread;


};

#endif // PSOC_H
