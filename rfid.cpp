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
    if(_ID.toInt() == 253)
    {
        sendRequestID();
    }

    else if(_ID.toInt() != 251)
    {
        if(_ID.toInt() < 10)
            receivedData += (QString::number(0) + QString::number(0) + _ID);
        else if (_ID.toInt() < 100)
            receivedData += (QString::number(0) + _ID);
        else
            receivedData += _ID;
    }

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
    char dataToSend[3]{0xAB, 0x02, 0x02};
    serial->write(dataToSend, strlen(dataToSend));
}

void rfid::sendReset()
{
    char dataToSend[1]{0x01};
    serial->write(dataToSend, strlen(dataToSend));
}
