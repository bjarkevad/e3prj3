#ifndef RFID_H
#define RFID_H

#include <QObject>
#include "QAsyncSerial.h"


/*
  Uses its own thread to check for new ID scans, then sends signal "newID()" with
  the scanned ID as a QString
    - Posix Threads?
    - Reads the RFID node to scan for new IDs
*/

class rfid : public QObject
{
    Q_OBJECT
public:
    explicit rfid(QObject *parent = 0, QString port = "/dev/ttyO1", int baudrate = 9600);
private:
    QAsyncSerial *serial;
    QString receivedData;
    
signals:
    //Sends the newly registered ID
    void newID(QString _ID);
    
public slots:
    void receiveID(QString _ID);
    //Placeholder
    void sendRequestID();
    void sendReset();
    
};

#endif // RFID_H
