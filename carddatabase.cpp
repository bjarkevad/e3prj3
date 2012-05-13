#include "carddatabase.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QSqlError>

CardDatabase::CardDatabase(QObject *parent, QString server, QString username, QString password) :
    QObject(parent)
{
    qDebug()<< "DB constructor";
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName(server);
    db->setDatabaseName("idrink");

    db->setUserName(username);
    db->setPassword(password);

    if (!db->open())
    {
        qDebug() << db->lastError();
    }
}

CardDatabase::~CardDatabase()
{
    qDebug() << "DB destructor";
    db->close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

bool CardDatabase::isOpen()
{
    return db->isOpen();
}

const QString CardDatabase::lookupID(const int _id)
{
    if(!db->isOpen())
    {
        qDebug() << db->lastError();
        return "0";
    }

    QSqlQuery query;

    query.prepare("SELECT * FROM ids WHERE id=:ID");
    query.bindValue(":ID", QVariant(_id));
    query.exec();

    if(!query.first())
        return "0";

    return query.value(2).toString();
}

const QString CardDatabase::lookupDrink(const int _id)
{
    if(!db->isOpen())
    {
        qDebug() << db->lastError();
        return "0";
    }

    QSqlQuery query;

    query.prepare("SELECT * FROM drinks WHERE id=:ID");
    query.bindValue(":ID", QVariant(_id));
    query.exec();

    if(!query.first())
        return "0";

    return query.value(1).toString();
}

const QString CardDatabase::lookupDrinkName(const int id)
{
    if(!db->isOpen())
    {
        qDebug() << db->lastError();
        return "0";
    }

    QSqlQuery query;

    query.prepare("SELECT * FROM drinks WHERE id=:ID");
    query.bindValue(":ID", QVariant(id));
    query.exec();

    if(!query.first())
        return "0";

    return query.value(2).toString();
}

void CardDatabase::updateCard(const int _id, const int _amount)
{
    /*
    Update _id with credit _amount in database.
    Use negative numbers to subtract from current amount,
    positiv to add to current amount
    */

    if(!db->isOpen())
    {
        qDebug() << "Database not open..";
        return;
    }
    QSqlQuery query;

    query.prepare("SELECT CREDIT FROM ids WHERE id=:ID;");
    query.bindValue(":ID", QVariant(_id));
    query.exec();

    if(!query.first())
        return;

    int newCredit = query.value(0).toInt() + _amount;
    qDebug() << "newCredit: " << newCredit;

    query.prepare("UPDATE ids SET credit=:NEW WHERE id=:ID;");
    query.bindValue(":ID", QVariant(_id));
    query.bindValue(":NEW", QVariant(newCredit));
    query.exec();
}
