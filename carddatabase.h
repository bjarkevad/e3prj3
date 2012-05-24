/**
 * @file
 * @author Bjarke Vad Andersen
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 * The CardDatabase class connects to a MYSQL database on construction,
 * and disconnects on destruction - this ensures that a connection will only be open when it's needed.
 * The Drink class is used to pass around drink information as a QObject.
 * @endsection1
 *
 */

#ifndef CARDDATABASE_H
#define CARDDATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QThread>


//class QSqlDatabase;
class MainWindow;

/**
 * @brief The Drink class is used to pass around drink information as a QObject
 * \param id_ The ID of the RFID card which is buying a drink
 * \param val_ The value/cost of the drink
 */
/**
 * @brief The Drink class represents a drink value and an RFID card ID.
 */
class Drink : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     * @param id_ The RFID card ID.
     * @param val_ The value/cost of the drink.
     */
    Drink(QObject* parent = 0, int id_ = 0, int val_ = 0) : QObject(parent), id(id_), val(val_){}
    /**
     * @brief Copy constructor.
     * @param other The object to copy.
     */
    Drink(const Drink& other) : QObject(other.parent()), id(other.id), val(other.val) {}
    /**
     * @brief Local copy of the RFID card ID.
     */
    int id;
    /**
     * @brief Local copy of the value of the drink.
     */
    int val;
};

//Opens a mysql connection on construction, and deletes it on destruction
//so a connection will only be open when you need one.
/**
 * @brief The CardDatabase class connects to a MYSQL database on construction,
 * and disconnects on destruction. This ensures that a connection will only be open when it's needed.
 */
class CardDatabase : public QObject
{
    Q_OBJECT
public:
    /** @brief Constructor. Opens a connection to a MYSQL server.
     * @param server The IP of the MYSQL server to connect to
     * @param username The username of the MYSQL server
     * @param password The password of the MYSQL server
     */
    explicit CardDatabase(QObject *parent = 0, QString server = "localhost",
                          QString username = "root",
                          QString password = "123123");
    /**
     * @brief Destructor.
     * Closes and removes the database connection.
     */
    ~CardDatabase();
    /**
     * @brief The status of the database connection.
     * @return The status of the database, true if open, false if closed.
     */
    bool isOpen();

private:
    /**
     * @brief Pointer to a QSqlDatabase.
     * This is the actual database connection point.
     */
    QSqlDatabase* db;

public slots:
    //NOTE: A better solution to the dynamic part could be found
    /**
     * @brief Updates an RFID card
     * @param drink_ This is a Drink object passed as a QObject. This makes it possible to use QSignalMappers. Should contain the cost of the drink and the ID of the buyer.
     * @param dynamic If the database used to run update card was dynammically allocated, this should be set to true.\n Ensures proper garbage collection.
     */
    void updateCard(QObject *drink_, bool dynamic = false);
    /**
     * @brief Looks up and RFID card ID in the database.
     * @param _id The ID to look up.
     * @return The credit on the Card as a QString.
     */
    const QString lookupID(const int _id);
    /**
     * @brief Look up the value of a drink
     * @param _id The ID of the drink, currently 1-6.
     * @return The value of the drink as a QString
     */
    const QString lookupDrink(const int _id);
    /**
     * @brief Look up the name of a drink
     * @param _id The ID of the drink, currently 1-6
     * @return The name of the drink as a QString
     */
    const QString lookupDrinkName(const int _id);
};

#endif // CARDDATABASE_H
