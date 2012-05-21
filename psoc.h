#ifndef PSOC_H
#define PSOC_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QMutex>


enum psocTransmitData {
    PSOC_MEASURE = 0x4D,
    PSOC_DONETRANS = 0x51,
    PSOC_RESET = 0x52,
    PSOC_BOTTLE = 0x40,
};

enum psocRecData {
    PSOC_R_NOGLASS = 0x4E,
    PSOC_R_STARTMIX = 0x53,
    PSOC_R_DONEMIX = 0x46,
};

class QScopedLock
{
public:
    QScopedLock(QMutex &mut_)
    {
        mutex = &mut_;
        mutex->lock();
    }
    ~QScopedLock()
    {
        mutex->unlock();
    }

private:
    QMutex *mutex;
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
    QMutex writeMutex;

public slots:
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
    void psocBottResponse(unsigned char bootleId, unsigned char value);

    void psocWrite(unsigned char*, int);

private:
    PsocNode* node;
    QString device;
    QThreadX nodeThread;


};

#endif // PSOC_H
