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
 * The Psoc class is used to connect to a PSoC5 device through a device node.
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
    PSOC_MEASURE = 0x4D, //!< Should be sent when we wish to measure the remaining fluid in a bottle. Should be followed by a PSOC_BOTTLE command.
    PSOC_DONETRANS = 0x51, //!< Unused in the current implementation.
    PSOC_RESET = 0x52, //!< Can be used for debugging.
    PSOC_BOTTLE = 0x40,//!< Represents the ID of a bottle, should be followed by ID(e.g. (PSOC_BOTTLE + 1) for bottle 1.
    PSOC_TEST = 0x54, //!< A test function, used to test connection to the PSoC5
};
//NOTE: These should be updated for testing with an actual PSOC
/**
 * @brief The psocRecData enum, used to make hex values readable by humans. These values are sent from the PSoC5
 */
enum psocRecData {
    PSOC_R_NOGLASS = 0x4E,//!<Is sent when no glass is present.
    PSOC_R_STARTMIX = 0x53,//<!Is sent when the PSoC5 succesfully started mixing a drink.
    PSOC_R_DONEMIX = 0x46, //<<!Is sent when the PSoC5 is done mixing a drink.
    PSOC_R_OK = 0x54,//<<!Is sent as a response to "PSOC_TEST" from the DevKit.
};

/**
 * @brief The QScopedLock class. Used to lock a QMutex only when in scope.
 */
class QScopedLock
{
public:
    /**
     * @brief Constructor, locks a QMutex when an object is initiated
     * @param mut_ << Address of the QMutex to lock
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
 * @brief The QThreadX class, this is used to make use of threads much more object oriented.
 */
class QThreadX : public QThread
{
protected:
    /**
     * @brief Reimplements run() from QThread to call exec().
     */
    void run() {this->exec();}
};

class PsocNode : public QObject
{
    Q_OBJECT
public:
    PsocNode(QObject *parent = 0, QString device_ = "");

    void setDev(QString device_)
    {
        device = device_;
    }

private:
    QString device;
    QFile psocFile;
    QMutex writeMutex;

public slots:
    //A dynamically allocated "data" must be parsed, or the program will most likely crash.
    void writePsoc(unsigned char *data, int len);

signals:
    void receivedDataSig(unsigned char* data);
    void receivedBottStatus(unsigned char* data);

};

/***************************************/
class Psoc : public QObject
{
    Q_OBJECT
public:
    explicit Psoc(QObject *parent = 0, QString device_ = "");

    ~Psoc()
    {
        delete node;
    }

public slots:
    void write(unsigned char *dataToWrite, int len);
    void receive(unsigned char* receivedData);
    void receiveBottStatus(unsigned char* receivedData);

signals:
    void noGlass();
    void mixStarted();
    void doneMixing();
    void psocOk(QString);
    void psocBottResponse(unsigned char bootleId, unsigned char value);

    void psocWrite(unsigned char*, int);

private:
    PsocNode* node;
    QString device;
    QThreadX nodeThread;


};

#endif // PSOC_H
