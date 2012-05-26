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
 *
 * Contains: \n
 * - The rfid class, which connects to an RFID scanner over a serial port.
 *
 * @endsection1
 */

#ifndef RFID_H
#define RFID_H

#include <QObject>
#include "QAsyncSerial.h"

/**
 * @brief The rfid class is used to connect to an RFID scanner.
 *
 * Connects to an external RFID scanner through a serial port, and processes data from said port before it is sent to other objects through signals.
 * Uses the QAsyncSerial class to make this more efficient.
 * As soon as the constructor is called, a connection is opened, and is first closed when the object is destroyed.
 *
 */
class rfid : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor that opens a serial port.
     *
     * Opens a connection to the RFID scanner and connects a signal from the device
     * to "receiveID()". Also sends the reset signal to the RFID device to make sure it is in the right state.
     * @param port The serial port that should be opened, e.g. "/dev/ttyO1"
     * @param baudrate The baudrate of the serial port.
     */
    explicit rfid(QObject *parent = 0, QString port = "/dev/ttyO1", int baudrate = 9600);
private:
    /**
     * @brief A pointer to a QAsyncSerial object
     *
     * This is the actual serial port connection used to communicate with the RFID scanner.
     */
    QAsyncSerial *serial;
    /**
     * @brief A QString with the received data from the RFID scanner.
     */
    QString receivedData;
    
signals:
    /**
     * @brief A signal that is sent when a new ID is received.
     *
     * This signal is what other objects needs to connect to, to get access to the received data from the serial device.
     * @param _ID The ID that is sent to other objects.
     */
    void newID(QString _ID);
    
private slots:
    /**
     * @brief Function that is called when a new ID is received from the RFID scanner.
     *
     * If the function receives the new ID detected signal, it sends out "sendRequestID()" to the RFID scanner.
     * If the function receives a part of an ID, it adds the values to receivedData, until an endofline signal is received,
     * and then emits the ID as a QString via "newID()".
     * @param _ID The received ID as a QString.
     */
    void receiveID(QString _ID);
    /**
     * @brief Sends a signal to the RFID scanner that requests the ID of a card that is in range.
     *
     * This signal changes the mode of the device, and it should be followed by a "sendReset()" call,
     * to put the RFID scanner back in its original state.
     */
    void sendRequestID();
    /**
     * @brief Sends a signal to the RFID scanner that puts it back in its original state
     *
     * When this signal is received by the scanner, it changes mode, so that it will send something
     * if an RFID card is detected, but it will not send the serial before it is requested.
     */
    void sendReset();
    
};

#endif // RFID_H
