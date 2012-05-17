#include "psoc.h"
#include <QDebug>
#include <QDataStream>


PsocReader::PsocReader(QString device)
{
    setDevice(device);
}

void PsocReader::setDevice(QString device_)
{
    device = device_;
}

void PsocReader::run()
{
    qint64 bytesRead;
    char receivedData[1];

    psoc.setFileName(device);
    if(!psoc.open(QIODevice::ReadOnly))
        return;

    while(!stopped)
    {
        qDebug() << "waiting..";
        bytesRead = psoc.read(receivedData, 0);

        emit sendData(QString::fromAscii(receivedData, sizeof(receivedData)));
        qDebug() << receivedData << " from psoc5";
        sleep(1);
    }
    psoc.close();
}


Psoc::Psoc(QObject *parent, QString device_) :
    QObject(parent)
{
    device = device_;

    readerThread = new PsocReader(device);
    readerThread->start();
}

void Psoc::writePsoc(QString dataToWrite_)
{
    psoc.setFileName(device);

    if(!psoc.open(QIODevice::WriteOnly))
        return;

    psoc.write(dataToWrite_.toAscii());
    qDebug() << "Data written to PSoC5: " << dataToWrite_.toAscii();
    psoc.close();
}

void Psoc::requestStatus(int _id)
{

}

void Psoc::requestDrink(int _drinkId)
{

}
