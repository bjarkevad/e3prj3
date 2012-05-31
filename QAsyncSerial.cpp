/**
 * Author: Terraneo Federico, modified by Bjarke Vad Andersen
 * Distributed under the Boost Software License, Version 1.0.
 */

#include "QAsyncSerial.h"
#include "AsyncSerial.h"
#include <QStringList>
#include <QRegExp>
#include <QDebug>

/**
 * Implementation details of QAsyncSerial class.
 */
class QAsyncSerialImpl
{
public:
    CallbackAsyncSerial serial;
    QString receivedData;
};

QAsyncSerial::QAsyncSerial(): pimpl(new QAsyncSerialImpl)
{
}

QAsyncSerial::QAsyncSerial(QString devname, unsigned int baudrate)
        : pimpl(new QAsyncSerialImpl)
{
    open(devname,baudrate);
}

void QAsyncSerial::open(QString devname, unsigned int baudrate)
{
    try {
        pimpl->serial.open(devname.toStdString(),baudrate);
    } catch(boost::system::system_error&)
    {
        //Errors during open
    }
    pimpl->serial.setCallback(bind(&QAsyncSerial::readCallback,this, _1, _2));
}

void QAsyncSerial::close()
{
    pimpl->serial.clearCallback();
    try {
        pimpl->serial.close();
    } catch(boost::system::system_error&)
    {
        //Errors during port close
    }
    pimpl->receivedData.clear();//Clear eventual data remaining in read buffer
}

bool QAsyncSerial::isOpen()
{
    return pimpl->serial.isOpen();
}

bool QAsyncSerial::errorStatus()
{
    return pimpl->serial.errorStatus();
}

void QAsyncSerial::write(const char *data, size_t size)
{
    pimpl->serial.write(data, size);
}

QAsyncSerial::~QAsyncSerial()
{
    pimpl->serial.clearCallback();
    try {
        pimpl->serial.close();
    } catch(...)
    {
        //Don't throw from a destructor
    }
}

void QAsyncSerial::readCallback(const char *data, size_t size)
{

    //Auto scan - 0xAB means the start of a serial, 254 means error
		//Emits 253, this is interpreted as "card detected" later on.
    if(data[0] != 0xAB && data[0] != 254)
        emit lineReceived(QString::number(253));

    //Commands..
    else if(data[0] == 0xAB)
    {
        unsigned int size_ = data[1];

        for(unsigned int i = 3; i <= size_; i++)
        {
            emit lineReceived(QString::number(data[i]));
        }
				//End of serial
        emit lineReceived(QString::number(251));
    }
}
