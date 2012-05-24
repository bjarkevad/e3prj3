#include "psoc.h"
#include <QDebug>
#include <QDataStream>



PsocNode::PsocNode(QObject *parent, QString device_)
{
}

void PsocNode::writePsoc(unsigned char* dataToSend, int len)
{
    QScopedLock slock(writeMutex);
    //unsigned char *dataToSend;
    //dataToSend = data;
    //delete data;
    //Expecting a max length of 2
    unsigned char result[2];

    //dataToSend = data;
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
    //If we receive 0x41, we know another char will follow
    //Set this to ASCII 'A'(0x41) and ASCII 'F'(0x46)
    if(result[0] >= 0xFF && result[0] <= 0x46)
    {
        fread(&result[1], 1, 1, psocFile);
        emit receivedBottStatus(result);
    }

    else
        emit receivedDataSig(&result[0]);

    fclose(psocFile);
    delete [] dataToSend;
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

    connect(node, SIGNAL(receivedDataSig(unsigned char*)),
            this, SLOT(receive(unsigned char*)));
    connect(node, SIGNAL(receivedBottStatus(unsigned char*)),
            this, SLOT(receiveBottStatus(unsigned char*)));
}

void Psoc::write(unsigned char* dataToWrite, int len)
{
    emit psocWrite(dataToWrite, len);
}

void Psoc::receive(unsigned char *receivedData)
{
    //Doing some data processing here, hiding a very ugly interface for mainwindow
    unsigned char data = *receivedData;

    switch(data)
    {
    case PSOC_R_NOGLASS:
        //'N': NO GLASS
        emit noGlass();
        break;
    case PSOC_R_STARTMIX:
        //'S': Start mix
        emit mixStarted();
        break;
    case PSOC_R_DONEMIX:
        //'F': Done mixing
      emit doneMixing();
        break;
    case PSOC_R_OK:
        qDebug() << "PSOC_R_OK received";
        emit psocOk("OK");
        break;
    default:
        emit psocOk("Error");
        qDebug() << "Received something unknown: " << data;
        break;
    }
}

void Psoc::receiveBottStatus(unsigned char *receivedData)
{
    //Emit BottleID is number from 0 and up
    emit psocBottResponse((receivedData[0]-61), receivedData[1]);
}






















