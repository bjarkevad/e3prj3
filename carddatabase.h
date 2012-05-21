#ifndef CARDDATABASE_H
#define CARDDATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QThread>


class QSqlDatabase;
class MainWindow;


class Drink : public QObject
{
    Q_OBJECT
public:
    Drink(QObject* parent = 0, int id_ = 0, int val_ = 0) : QObject(parent), id(id_), val(val_){}
    Drink(const Drink& other) : QObject(other.parent()), id(other.id), val(other.val) {}
    int id;
    int val;
};


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
    void updateCard(QObject *drink_);
    const QString lookupID(const int _id);
    const QString lookupDrink(const int _id);
    const QString lookupDrinkName(const int id);
};

#endif // CARDDATABASE_H
