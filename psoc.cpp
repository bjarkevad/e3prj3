#include "psoc.h"
#include <QDebug>
#include <QDataStream>



PsocNode::PsocNode(QObject *parent, QString device_)
{
}

void PsocNode::writePsoc(unsigned char* data, int len)
{
    unsigned char *dataToSend;
    unsigned char result[2];

    dataToSend = data;
    FILE * psocFile;

    psocFile = fopen(device.toAscii(),"r+");

    if(psocFile == NULL)
        return;

    for(int i = 0; i < len; i++)
    {
        qDebug() << "Sending: " << dataToSend[i];
        fwrite(&dataToSend[i], 1, 1, psocFile);
    }

    fread(&result[0], 1, 1, psocFile);

    //Set this to ASCII 'A'
    if(result[0] == 0xFF)
    {
        fread(&result[1], 1, 1, psocFile);
        emit receivedDataSig(result, 2);
    }

    else
    {
        emit receivedDataSig(result, 1);
    }

    fclose(psocFile);
}

/***********************/

Psoc::Psoc(QObject *parent, QString device_) :
    QObject(parent), node(new PsocNode(this, device_))
{
    node->setDev(device_);

    node->moveToThread(&nodeThread);
    nodeThread.start();

    node->connect(this, SIGNAL(psocWrite(unsigned char*, int)),
                  SLOT(writePsoc(unsigned char*, int)));
    connect(node, SIGNAL(receivedDataSig(unsigned char*, int)),
            this, SLOT(receive(unsigned char*, int)));
}

void Psoc::write(unsigned char* dataToWrite, int len)
{
    emit psocWrite(dataToWrite, len);
}

void Psoc::receive(unsigned char *receivedData, int len)
{
    for(int i = 0; i < len; i++)
        qDebug() << "Received from Psoc: " << QString::number(receivedData[i]);
}

























