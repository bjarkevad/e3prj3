#include "psoc.h"
#include <QDebug>


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
    char receivedData[512];

    psoc.setFileName(device);
    if(!psoc.open(QIODevice::ReadOnly))
        return;

    while(!stopped)
    {
        bytesRead = psoc.read(receivedData, 512);

        emit sendData(QString::fromAscii(receivedData, sizeof(receivedData)));
        qDebug() << receivedData;
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
    char *dataToWrite;
    QByteArray tempData= dataToWrite_.toLocal8Bit();
    dataToWrite = tempData.data();

    psoc.setFileName(device);

    if(!psoc.open(QIODevice::WriteOnly))
        return;

    psoc.write(dataToWrite);
    qDebug() << dataToWrite;
    psoc.close();
}

void Psoc::requestStatus(int _id)
{

}

void Psoc::requestDrink(int _drinkId)
{

}
