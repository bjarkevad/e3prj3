#ifndef CARDDATABASE_H
#define CARDDATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QThread>


class QSqlDatabase;
class MainWindow;


class CardDatabase : public QObject
{
    Q_OBJECT
public:
    explicit CardDatabase(QObject *parent = 0, QString server = "localhost",
                          QString username = "root",
                          QString password = "123123");
    ~CardDatabase();
    bool isOpen();

private:
    QSqlDatabase* db;

signals:
    void returnCredit(QString credit);

public slots:
    void updateCard(const int _id, const int _amount);
    const QString lookupID(const int _id);
    const QString lookupDrink(const int _id);
    const QString lookupDrinkName(const int id);
};

#endif // CARDDATABASE_H
