/**
 *@file
 *@author Bjarke Vad Andersen
 *@version 1.0
 *
 *@section LICENSE
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
 *
 * The MainWindow class is used to tie all the different modules of iDrink together.
 * It is in this class most GUI related things are handled.
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "rfid.h"
#include "psoc.h"


namespace Ui {
class MainWindow;
}
//Forward declaration
class CardDatabase;
class QSignalMapper;
class QTimer;

/**
 * @brief The MainWindow class is used to tie all the different objects of iDrink together.
 *
 * This class is responsible for handling all GUI related operations,
 * and implements most of the applications functionality.
 * This class works much as the "main()" function of a traditional C++ program, since everything is run through this class.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief Constructor  Responsible for initalizing the application.
     *
     * Initializes connections, reads saved settings, allocates an rfid object
     * and opens the node "/dev/psoc" in a Psoc object.
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * Destructor
     *
     * Calls delete on dynamically allocated objects. These calls should not really be necessary,
     * since the application is build around Qt's QObject parent/child functionality, which essentially means that
     * if an object of baseclass QObject is created with a parent, the object will get deleted at the same time as the parent is.
     */
    ~MainWindow();

protected:
    /**
     * @brief Event that happens when the application is closed.
     *
     * Calls "saveSettings()" on exit.
     * @param event The exit event that happens when the application gets closed.
     */
    void closeEvent(QCloseEvent *event);

private:
    /**
     * @brief Pointer to the user interface object.
     *
     * The object contains all information of the graphical user interface. Ui::MainWindow is generated from a Qt UI form, created in Qt Designer.
     */
    Ui::MainWindow *ui;
    /**
     * @brief Pointer to an rfid object
     *
     * Used to communicate with the external RFID module through a serial port.
     * Allocated dynamically on application startup.
     */
    rfid *rfids;
    /**
     * @brief Pointer to a Psoc object.
     * Used to communicate with a PSoC5 device through a device node.
     */
    Psoc *psoc;
    /**
     * @brief A QString containing the currently active RFID card serial number.
     *
     * Updated when a new card is scanned on the RFID reader, and is always reset when it is no longer needed.
     * This QString is available for all functions in MainWindow, to avoid parsing around a lot of pointers.
     */
    QString currentID;
    /**
     * @brief A QSignalMapper used to pass a Drink object around as a QObject.
     *
     * This enables the application to send data from a signal that contains none,
     * e.g. when a button is clicked(which sends the signal clicked();), it can pass a Drink object to the CardDatabase object.
     * Used when a user inputs which drink he wants.
     */
    QSignalMapper *sigMap;
    /**
     * @brief A QTimer to be used for timeouts.
     *
     * Used to send a timeout signal if no response is received from the PSoC5 device, when picking a drink.
     * This makes it possible to return to the homescreen if an error happens with the PSoC5 connection.
     */
    QTimer *timeout;

    /**
     * @brief Initialize labels to have behave correctly.
     *
     * Sets font sizes, initial text and hides warning labels that are not used on application startup.
     */
    void initLabels();
    /**
     * @brief Initialize signal/slot connections
     *
     * Connections that should last throughout the lifetime of the application are initialized here.
     * This is done to avoid calling connect more times than strictly necessary.
     */
    void initConnections();
    /**
     * @brief Update drink buttons.
     *
     * The buttons, which are used to pick which drink is served, are updated to show the correct names and prices of the drinks available.
     * The information is updated directly from a MYSQL database, to enable live updates of drinks from the MYSQL server.
     * @param db A CardDatabase pointer from which the drink information is pulled. Used to avoid opening multible MYSQL
     * connections, if the calling function already has one open.
     */
    void updateDrinkButtons(CardDatabase* db);
    /**
     * @brief Read saved settings from a file.
     *
     * On Linux these settings are saved in ~/.config/GRUPPE1/iDrink.conf
     * Only saves MYSQL database adresses, so these can be changed by using a dropdown box,
     * instead of typing them with a keyboard, which is not available on the DevKit8000.
     * New adresses are added by manually editing the iDrink.conf file.
     */
    void readSettings();
    /**
     * @brief Write settings to file(~/.config/GRUPPE1/iDrink.conf).
     * This function always saves two default database adress options, so these are always present on startup.
     */
    void writeSettings();

private slots:
    /**
     * @brief Returns to the start screen
     *
     * Sets the application to its default state, meaning that labels and connections that were modified, are returned to their initial state.
     *
     */
    void returnHome();
    /**
     * @brief Cleans up allocated memory and calls "returnHome()".
     *
     * Calls delete on "sigMap" and "timeout", it the reenables all drink buttons,
     * that were disabled in the "drinkButtonClicked()" function.
     * Should only be used after "drinkButtonClicked()" has been called.
     */
    void cleanReturnHome();
    /**
     * @brief Returns to the settings screen.
     *
     * Used when a user presses back on one of the settings pages. Implemented mostly for readability.,
     * but can be used to clean up/update labels that were changed earlier etc.
     */
    void settingsBack();
    /**
     * @brief Shows the user a "Please Wait.." screen.
     *
     * This screen is shown when a drink is in the process of being poured,
     * and is informing the user that the system is working correctly.
     */
    void showPleaseWait();
    /**
     * @brief Event that happens when an ID is scanned.
     *
     * This is called when an RFID card is scanned on the RFID reader.
     * When this is called, it is disconnected from the signal that calls it, to avoid "double scanning" IDs, so only one ID can be active at a time.
     * This connection is reenabled when "returnHome()" is called.
     * A CardDatabase is created, meaning that a MYSQL database connection is opened,
     * if an error occurs in the opening process, a error is printed to the user.
     * If the database is opened successfully, the scanned ID will be looked up in it, and the "currentID" variable is updated accordingly.
     * The credit value of the ID is then printed to the screen, and the application now moves to the drinkpicker state,
     * where the user will be asked to pick a drink.
     *
     * @param id
     */
    void onNewID(QString id);

    /**
     * @brief Function that is run when the Settings button is clicked.
     *
     * The system goes to its settings state, where bottle status and system settings are available.
     * The settings button is normally hidden, but the settings state will be activated when an administrator
     * RFID card is scanned.
     */
    void on_settingsButton_clicked();
    /**
     * @brief Function that is run when the Bottle Status button is clicked.
     *
     * The administrating user is presented with the level of fluid in the individual bottles.
     * This feature is not yet fully implemented.
     */
    void on_bottleStatusButton_clicked();
    /**
     * @brief Function that is run when the System Settings button is clicked.
     *
     * The administrating user is presented with tools to test PSoC5 and MYSQL database connections,
     * and setting up a different IP address for the MYSQL database server.
     * The available IP addresses are read from the saved settings, created by "writeSettings()".
     */
    void on_systemSettingsButton_clicked();
    /**
     * @brief Function that is run when the Test Database button is clicked.
     *
     * Creates a new CardDatabase object, and tests if a MYSQL database can be opened on the earlier specified IP address.
     * A text label is updated accordingly to show "OK" on success, and "Error" on failure.
     * The CardDatabase object is immediately destroyed after testing.
     */
    void on_testDBButton_clicked();
    /**
     * @brief Function that is run when the Test PSoC button is clicked.
     *
     * Sends PSOC_TEST to the PSoC device, if the PSoC answers, a text label is shown to inform the administrator that the test was successful.
     * If the only response is the timeout response from the PSoC node, the administrator is informed that the test failed.
     */
    void on_testPsocButton_clicked();

    /**
     * @brief Function that is run when the Test button is clicked.
     *
     * The test button is only shown if the application is not compiled with "TARGET" defined,
     * meaning when it is run on the desktop.
     * \note This function is only implemented for testing purposes.
     *
     */
    void on_testButton_clicked();

    /**
     * @brief Function that is run when a drink button is clicked.
     *
     * When the user has successfully scanned an RFID card, and been directed to the drink picker,
     * pressing a drink button will call this function.
     * @param drinkNo The ID of the drink picked by the user. Used to identify which drink is to be mixed,
     * and how much credit is to be withdrawn from the users RFID card.
     * @return 0 on success, -1 on error.
     */
    int drinkButtonClicked(QString drinkNo);
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton1_clicked() { drinkButtonClicked("1"); }
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton2_clicked() { drinkButtonClicked("2"); }
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton3_clicked() { drinkButtonClicked("3"); }
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton4_clicked() { drinkButtonClicked("4"); }
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton5_clicked() { drinkButtonClicked("5"); }
    /**
     * @brief Function to forward a specific ID to "drinkButtonClicked()".
     */
    void on_drinkButton6_clicked() { drinkButtonClicked("6"); }
};

#endif // MAINWINDOW_H
