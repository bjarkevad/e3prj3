#ifndef PSOC_H
#define PSOC_H

#include <QObject>
#include <QThread>
#include <QFile>

enum psocTransmitData {
    PSOC_MEASURE = 0x4D,
    PSOC_DONETRANS = 0x51,
    PSOC_RESET = 0x52,
    PSOC_BOTTLE_A = 0x41,
    PSOC_BOTTLE_B = 0x42,
};

enum psocRecData {
    PSOC_NOGLASS = 0x4E,
    PSOC_STARTMIX = 0x53,
    PSOC_DONEMIX = 0x46,
    PSOC_BOTTLE_A_INFO = 0x41,
    PSOC_BOTTLE_B_INFO = 0x42,
};

class QThreadX : public QThread
{
protected:
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

public slots:
    void writePsoc(unsigned char *data, int len);

signals:
    void receivedDataSig(unsigned char* data, int len);

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
    void receive(unsigned char* receivedData, int len);

signals:
    void psocResponse(QString data);
    void psocWrite(unsigned char*, int);

private:
    PsocNode* node;
    QString device;
    QThreadX nodeThread;


};

#endif // PSOC_H
