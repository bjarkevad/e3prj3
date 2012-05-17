#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QSqlQuery>
#include <QMovie>
#include <QDebug>
#include <QSettings>
#include <QCloseEvent>

#include "mainwindow.h"
#include "carddatabase.h"
#include "rfid.h"

#include "ui_mainwindow.h"


/* MainWindow stack Index:

  0: Main
  1: Drink Picker
  2: Please Wait
  3: Service Page
  4: Replace bottles page
  5: System Settings
  6: System Status

  */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
#ifdef TARGET
    this->showFullScreen();
#endif
		ui->setupUi(this);
    ui->warningLabel->hide();
    ui->mainwindowStack->setCurrentIndex(0);

    rfids = new rfid;
    psoc = new Psoc(this, "/dev/Psoc5");
    initLabels();
    initConnections();
    writeSettings();
    readSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete rfids;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

void MainWindow::initLabels()
{
    QFont creditFont = ui->creditValueLabel->font();
    creditFont.setPointSize(28);
    ui->creditValueLabel->setFont(creditFont);
    ui->creditValueLabel_2->setFont(creditFont);
    updateCreditLabels("Scan Card..");
    ui->expensiveLabel->hide();
}

void MainWindow::initConnections()
{
    connect(this->ui->settingsBackButton, SIGNAL(clicked()),
            this, SLOT(settingsBack()));
    connect(this->ui->settingsBackButton_2, SIGNAL(clicked()),
            this, SLOT(settingsBack()));
    connect(this->ui->serviceHomeButton, SIGNAL(clicked()),
            this, SLOT(returnHome()));
    connect(this->ui->drinkPickerHomeButton, SIGNAL(clicked()),
            this, SLOT(returnHome()));

    /*connect(rfids, SIGNAL(newID(QString)),
            this, SLOT(onNewID(QString)));*/

    /** TODO:
            connect psoccom::cupFull to this::returnHome
          */
}

void MainWindow::returnHome()
{
    ui->mainwindowStack->setCurrentIndex(0);
    updateCreditLabels("Scan Card..");
    ui->expensiveLabel->hide();

    connect(rfids, SIGNAL(newID(QString)),
            this, SLOT(onNewID(QString)));
}

void MainWindow::onNewID(QString id)
{
    CardDatabase db(this, ui->addressBox->currentText());

    if(!db.isOpen())
    {
        ui->warningLabel->show();
        return;
    }

    else
        ui->warningLabel->hide();

    const QString credit = db.lookupID(id.toInt());

    //A treshold for minimum credit to continue can be set here
    updateCreditLabels(credit);
    currentID = id;
    updateDrinkButtons(&db);

    ui->mainwindowStack->setCurrentIndex(1);

    disconnect(rfids, SIGNAL(newID(QString)),
               this, SLOT(onNewID(QString)));
}

void MainWindow::on_settingsButton_clicked()
{
    ui->mainwindowStack->setCurrentIndex(3);
}

void MainWindow::on_systemSettingsButton_clicked()
{
    ui->DBStatusLabel->setText("");
    ui->PsocStatusLabel->setText("");
    ui->mainwindowStack->setCurrentIndex(5);
}

void MainWindow::on_testDBButton_clicked()
{
    CardDatabase testDB(this, ui->addressBox->currentText());

    if(testDB.isOpen())
        ui->DBStatusLabel->setText("OK");
    else
        ui->DBStatusLabel->setText("Error");
}

void MainWindow::on_testPsocButton_clicked()
{
}

void MainWindow::on_replaceBottlesButton_clicked()
{
    ui->mainwindowStack->setCurrentIndex(4);
}

void MainWindow::settingsBack()
{
    ui->mainwindowStack->setCurrentIndex(3);
}

void MainWindow::updateCreditLabels(QString value)
{
    ui->creditValueLabel->setText(value);
    ui->creditValueLabel_2->setText(value);
}

void MainWindow::updateDrinkButtons(CardDatabase* db)
{
    //Takes a CardDatabase pointer as argument to prevent opening a new sql connection
    ui->drinkButton1->setText(db->lookupDrinkName(1) + "\n" + db->lookupDrink(1));
    ui->drinkButton2->setText(db->lookupDrinkName(2) + "\n" + db->lookupDrink(2));
    ui->drinkButton3->setText(db->lookupDrinkName(3) + "\n" + db->lookupDrink(3));
    ui->drinkButton4->setText(db->lookupDrinkName(4) + "\n" + db->lookupDrink(4));
    ui->drinkButton5->setText(db->lookupDrinkName(5) + "\n" + db->lookupDrink(5));
    ui->drinkButton6->setText(db->lookupDrinkName(6) + "\n" + db->lookupDrink(6));
}

void MainWindow::on_testButton_clicked()
{
    psoc->writePsoc("0xab");
}

int MainWindow::drinkButtonClicked(QString drinkNo)
{
    //connect donePouring();

    /*
      -Is this drink available? if no, print error, else continue:
      -Send signal to psoc to start pouring drinkX

      -Show pleaseWait screen and..
        -Subtract correct amount of credit from DB
        -Wait for psoc to send done()??
      -Show pleaseTakeDrink screen and wait for psoc to send drinkTaken()?
      -Return to homescreen

    */
    CardDatabase db(this, ui->addressBox->currentText());

    int drinkVal = db.lookupDrink(drinkNo.toInt()).toInt();

    if(drinkVal > db.lookupID(currentID.toInt()).toInt())
    {
        ui->expensiveLabel->show();
        return -1;
    }

    db.updateCard(currentID.toInt(), -(drinkVal));
    currentID.clear();
    returnHome();

    return 0;
}

void MainWindow::on_drinkButton1_clicked()
{
    drinkButtonClicked(QString::number(1));
}

void MainWindow::on_drinkButton2_clicked()
{
    drinkButtonClicked(QString::number(2));
}

void MainWindow::on_drinkButton3_clicked()
{
    drinkButtonClicked(QString::number(3));
}

void MainWindow::on_drinkButton4_clicked()
{
    drinkButtonClicked(QString::number(4));
}

void MainWindow::on_drinkButton5_clicked()
{
    drinkButtonClicked(QString::number(5));
}

void MainWindow::on_drinkButton6_clicked()
{
    drinkButtonClicked(QString::number(6));
}

void MainWindow::showPleaseWait()
{

}

void MainWindow::writeSettings()
{
    QSettings settings("GRUPPE1", "iDrink");

    //Always have these options saved!!
    settings.setValue("Database/ip"+QString::number(0), "10.9.8.1");
    settings.setValue("Database/ip"+QString::number(1), "localhost");
}

void MainWindow::readSettings()
{
    QSettings settings("GRUPPE1", "iDrink");

    for(int i = 0; i < 5; i++)
        ui->addressBox->addItem(settings.value("Database/ip"+QString::number(i)).toString());
}


