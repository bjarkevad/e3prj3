#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "rfid.h"
#include "psoc.h"


namespace Ui {
class MainWindow;
}

class CardDatabase;
class QSignalMapper;
class QTimer;


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    rfid *rfids;
    Psoc *psoc;
    //The currently active RFID card ID
    QString currentID;

    QSignalMapper *sigMap;
    QTimer *timeout;

    void initLabels();
    void initConnections();
    void updateCreditLabels(QString value);
    void updateDrinkButtons(CardDatabase* db);

    void readSettings();
    void writeSettings();

private slots:
    void returnHome();
    void settingsBack();
    void showPleaseWait();
    void cleanReturnHome();

    void onNewID(QString id);

    int drinkButtonClicked(QString drinkNo);

    void on_settingsButton_clicked();
    void on_replaceBottlesButton_clicked();
    void on_systemSettingsButton_clicked();
    void on_testDBButton_clicked();
    void on_testPsocButton_clicked();

    void on_testButton_clicked();

    void on_drinkButton1_clicked() { drinkButtonClicked(QString::number(1)); }
    void on_drinkButton2_clicked() { drinkButtonClicked(QString::number(2)); }
    void on_drinkButton3_clicked() { drinkButtonClicked(QString::number(3)); }
    void on_drinkButton4_clicked() { drinkButtonClicked(QString::number(4)); }
    void on_drinkButton5_clicked() { drinkButtonClicked(QString::number(5)); }
    void on_drinkButton6_clicked() { drinkButtonClicked(QString::number(6)); }
};

#endif // MAINWINDOW_H
