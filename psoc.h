#ifndef PSOC_H
#define PSOC_H

#include <QObject>
#include <QThread>
#include <QFile>

/*
    Has its own thread which listens to the SPI driver and sends signals accordingly.
*/
class PsocReader : public QThread
{
    Q_OBJECT
public:
    PsocReader(QString device);

    void setDevice(QString device);

protected:
    void run();

private:
    volatile bool stopped;
    QString device;
    QFile psoc;

signals:
    void sendData(QString data);
};


//*********************************************

class Psoc : public QObject
{
    Q_OBJECT
public:
    explicit Psoc(QObject *parent = 0, QString device_ = "");
    void writePsoc(QString dataToWrite_);

private:

    PsocReader *readerThread;
    QString device;
    QFile psoc;
    
signals:
    //Is sent if psoc sends cupFull command
    void cupFull();
    //Is sent on commmunication errors
    void commError(QString _error);
    //See requestStatus
    void bottleStatus(int _value);
    
public slots:
    //Request status for bottle with id _id, then sends signal bottleStatus with value
    void requestStatus(int _id);
    void requestDrink(int _drinkId);
    
};

#endif // PSOC_H
