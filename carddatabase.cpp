#include "carddatabase.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QSqlError>

CardDatabase::CardDatabase(QObject *parent, QString server, QString username, QString password) :
    QObject(parent)
{
    qDebug() << "Carddatabase open..";
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
    db->close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
    qDebug() << "Database closed..";
}

bool CardDatabase::isOpen()
{
    return db->isOpen();
}

const QString CardDatabase::lookupID(const qlonglong _id)
{

    qDebug() << "Looking up: " << _id;
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
        return 0;

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

const QString CardDatabase::lookupDrinkName(const int _id)
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

    return query.value(2).toString();
}

const bool CardDatabase::isAdmin(const qlonglong _id)
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
        return false;

    return query.value(3).toBool();
}

void CardDatabase::deleteDb()
{
    this->~CardDatabase();
}

void CardDatabase::updateCard(QObject* drink_, bool dynamic)
{
    /*
    Update _id with credit _amount in database.
    Use negative numbers to subtract from current amount,
    positiv to add to current amount
    */
    Drink *drink= qobject_cast<Drink *>(drink_);

    qDebug() << drink->id << " " << drink->val;

    if(!db->isOpen())
    {
        qDebug() << "Database not open..";
        return;
    }
    QSqlQuery query;

    query.prepare("SELECT CREDIT FROM ids WHERE id=:ID;");
    query.bindValue(":ID", QVariant(drink->id));
    query.exec();

    if(!query.first())
    {
        qDebug() << "Query fail";
        return;
    }

    int newCredit = query.value(0).toInt() + (drink->val);
    qDebug() << "newCredit: " << newCredit;

    query.prepare("UPDATE ids SET credit=:NEW WHERE id=:ID;");
    query.bindValue(":ID", QVariant(drink->id));
    query.bindValue(":NEW", QVariant(newCredit));
    query.exec();

    //Added this flag to fix "onDrinkButton_clicked()" in mainwindow
    //This way the function works as before, but can be used to destroy dynamically
    //allocated CardDatabases
    delete drink;
    if(dynamic)
        this->~CardDatabase();

}
