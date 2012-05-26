#include "rfid.h"
#include <QDebug>

rfid::rfid(QObject *parent, QString port, int baudrate) :
    QObject(parent)
{
    serial = new QAsyncSerial(port, baudrate);

    connect(serial, SIGNAL(lineReceived(QString)),
            this, SLOT(receiveID(QString)));

    sendReset();
}

void rfid::receiveID(QString _ID)
{
    //If a card is detected, request the ID of it
    if(_ID.toInt() == 253)
    {
        sendRequestID();
    }

    //If we are in the process of receiving an ID, add it to receivedData
    else if(_ID.toInt() != 251)
    {
        if(_ID.toInt() < 10)
            receivedData += (QString::number(0) + QString::number(0) + _ID);
        else if (_ID.toInt() < 100)
            receivedData += (QString::number(0) + _ID);
        else
            receivedData += _ID;
    }

    // If we get the endofline command (251), and receivedData is not empty, emit newID.
    else if(_ID.toInt() == 251 && !receivedData.isEmpty())
    {
        emit newID(receivedData);
        //qDebug() << receivedData;
        receivedData.clear();
    }
    //Always send reset to prevent getting stuck if card is removed too quickly.. :)
    sendReset();
}

void rfid::sendRequestID()
{
    //Done this way to increase readability, could be implemented as an enum or whatnot.
    char dataToSend[3]{0xAB, 0x02, 0x02};
    serial->write(dataToSend, strlen(dataToSend));
}

void rfid::sendReset()
{
    //Done this way to increase readability, could be implemented as an enum or whatnot.
    char dataToSend[1]{0x01};
    serial->write(dataToSend, strlen(dataToSend));
}
