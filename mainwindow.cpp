#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QSqlQuery>
#include <QMovie>
#include <QDebug>
#include <QSettings>
#include <QCloseEvent>
#include <QSignalMapper>

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

//TODO: Implement bottle status/calibration

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
#ifdef TARGET
    this->showFullScreen();
    ui->testButton->hide();
    ui->settingsButton->hide();
#endif
    ui->setupUi(this);

    ui->mainwindowStack->setCurrentIndex(0);

    rfids = new rfid;
    psoc = new Psoc(this, "/dev/psoc");
    initLabels();
    initConnections();
    readSettings();

}

MainWindow::~MainWindow()
{
    //These deletes should be called automatically by QObject's parent / child sytem
    delete ui;
    delete rfids;
    delete psoc;
    delete timeout;
    delete sigMap;
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
    ui->creditValueLabel->setText("Scan Card..");
    ui->expensiveLabel->hide();
    ui->warningLabel->setFont(creditFont);
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

    /*NOTE: Disabled for testing purposes*/
    connect(rfids, SIGNAL(newID(QString)),
            this, SLOT(onNewID(QString)));

    connect(psoc, SIGNAL(psocOk(QString)),
            ui->PsocStatusLabel, SLOT(setText(QString)));

    connect(psoc, SIGNAL(psocOk(QString)),
            ui->warningLabel, SLOT(setText(QString)));

}

void MainWindow::returnHome()
{
    ui->mainwindowStack->setCurrentIndex(0);
    ui->expensiveLabel->hide();

    connect(rfids, SIGNAL(newID(QString)),
            this, SLOT(onNewID(QString)));
}

void MainWindow::cleanReturnHome()
{
    currentID.clear();
    delete sigMap;
    delete timeout;
    ui->drinkButton1->setEnabled(true);
    ui->drinkButton2->setEnabled(true);
    ui->drinkButton3->setEnabled(true);
    ui->drinkButton4->setEnabled(true);
    ui->drinkButton5->setEnabled(true);
    ui->drinkButton6->setEnabled(true);
    ui->drinkPickerHomeButton->setEnabled(true);
    returnHome();
}

void MainWindow::showPleaseWait()
{
    ui->mainwindowStack->setCurrentIndex(2);
}

void MainWindow::onNewID(QString id)
{
    disconnect(rfids, SIGNAL(newID(QString)),
               this, SLOT(onNewID(QString)));

    CardDatabase db(this, ui->addressBox->currentText());

    if(!db.isOpen())
    {
        ui->warningLabel->setText("Database Error, contact employee");
        return;
    }

    else
        ui->warningLabel->setText("");

    if(db.isAdmin(id.toInt()))
    {
        //Shows the settings screen if the scanned ID is administrator
        ui->mainwindowStack->setCurrentIndex(3);
        ui->warningLabel->setText("");
    }

    else
    {
        const QString credit = db.lookupID(id.toInt());

        //A treshold for minimum credit to continue can be set here
        ui->creditValueLabel_2->setText(credit);
        currentID = id;
        updateDrinkButtons(&db);

        ui->mainwindowStack->setCurrentIndex(1);
    }
}

void MainWindow::on_settingsButton_clicked()
{
    ui->mainwindowStack->setCurrentIndex(3);
    ui->warningLabel->setText("");
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
    unsigned char *toSend = new unsigned char[1] {PSOC_TEST};

    psoc->write(toSend, 1);
}

void MainWindow::on_bottleStatusButton_clicked()
{
    ui->mainwindowStack->setCurrentIndex(4);
}

void MainWindow::settingsBack()
{
    ui->mainwindowStack->setCurrentIndex(3);
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
    onNewID("109247101");
}

int MainWindow::drinkButtonClicked(QString drinkNo)
{
    ui->drinkButton1->setEnabled(false);
    ui->drinkButton2->setEnabled(false);
    ui->drinkButton3->setEnabled(false);
    ui->drinkButton4->setEnabled(false);
    ui->drinkButton5->setEnabled(false);
    ui->drinkButton6->setEnabled(false);
    ui->drinkPickerHomeButton->setEnabled(false);

    CardDatabase *db = new CardDatabase(this, ui->addressBox->currentText());

    int drinkVal = db->lookupDrink(drinkNo.toInt()).toInt();

    qDebug() << drinkNo;

    if(drinkVal > db->lookupID(currentID.toInt()).toInt())
    {
        ui->expensiveLabel->show();
        return -1;
    }

    //TODO: Amount from database should be parsed
    connect(psoc, SIGNAL(mixStarted()),
            this, SLOT(showPleaseWait()));

   // showPleaseWait();

    sigMap = new QSignalMapper(this);
    Drink *drink = new Drink(this, currentID.toInt(), (-drinkVal));
    timeout = new QTimer(this);

    timeout->setSingleShot(true);
    //TODO: Calibrate timeout
    timeout->setInterval(2000);

    //Connect doneMixing to map
    connect(psoc, SIGNAL(doneMixing()),
            sigMap, SLOT(map()));    

    connect(timeout, SIGNAL(timeout()),
            this, SLOT(cleanReturnHome()));
    //map will now emit a drink
    sigMap->setMapping(psoc, drink);
    //connect mapped to update card, this means that if we receive doneMixing,
    //the correct card will be updated
    connect(sigMap, SIGNAL(mapped(QObject*)),
            db, SLOT(updateCard(QObject*)));

    unsigned char* toSend = new unsigned char[2]{(PSOC_BOTTLE + drinkNo.toInt()), 0x31};
    psoc->write(toSend, 2);

    timeout->start();

    return 0;
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


