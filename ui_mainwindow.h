/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 7 14:50:21 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *mainwindowStack;
    QWidget *homePage;
    QPushButton *testButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *iDrinkLabel;
    QLabel *creditValueLabel;
    QPushButton *settingsButton;
    QLabel *warningLabel;
    QWidget *drinkpickerPage;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *creditLabel_2;
    QLabel *creditValueLabel_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *drinkButton1;
    QPushButton *drinkButton2;
    QPushButton *drinkButton3;
    QVBoxLayout *verticalLayout;
    QPushButton *drinkButton4;
    QPushButton *drinkButton5;
    QPushButton *drinkButton6;
    QPushButton *drinkPickerHomeButton;
    QLabel *expensiveLabel;
    QWidget *pleaseWaitPage;
    QLabel *pleaseWaitLabel;
    QWidget *servicePage;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *replaceBottlesButton;
    QPushButton *systemSettingsButton;
    QFrame *line_3;
    QPushButton *serviceHomeButton;
    QLabel *iDrinkLabel_3;
    QWidget *replaceBottlesPage;
    QPushButton *settingsBackButton;
    QFrame *line_7;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *bottleButton;
    QPushButton *bottleButton_4;
    QPushButton *bottleButton_6;
    QVBoxLayout *verticalLayout_8;
    QPushButton *bottleButton_2;
    QPushButton *bottleButton_3;
    QPushButton *bottleButton_5;
    QWidget *systemSettingsPage;
    QPushButton *settingsBackButton_2;
    QFrame *line_8;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QComboBox *addressBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_9;
    QPushButton *testDBButton;
    QPushButton *testPsocButton;
    QVBoxLayout *verticalLayout_10;
    QLabel *DBStatusLabel;
    QLabel *PsocStatusLabel;
    QWidget *systemStatusPage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(480, 272));
        MainWindow->setMaximumSize(QSize(480, 272));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainwindowStack = new QStackedWidget(centralWidget);
        mainwindowStack->setObjectName(QString::fromUtf8("mainwindowStack"));
        mainwindowStack->setGeometry(QRect(0, 0, 481, 321));
        homePage = new QWidget();
        homePage->setObjectName(QString::fromUtf8("homePage"));
        testButton = new QPushButton(homePage);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(90, 220, 86, 51));
        layoutWidget = new QWidget(homePage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 481, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        iDrinkLabel = new QLabel(layoutWidget);
        iDrinkLabel->setObjectName(QString::fromUtf8("iDrinkLabel"));
        iDrinkLabel->setMinimumSize(QSize(269, 50));
        iDrinkLabel->setMaximumSize(QSize(269, 50));
        iDrinkLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(iDrinkLabel, 0, Qt::AlignHCenter);

        creditValueLabel = new QLabel(layoutWidget);
        creditValueLabel->setObjectName(QString::fromUtf8("creditValueLabel"));
        creditValueLabel->setMinimumSize(QSize(269, 77));
        creditValueLabel->setMaximumSize(QSize(269, 77));
        creditValueLabel->setTextFormat(Qt::RichText);
        creditValueLabel->setScaledContents(false);
        creditValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(creditValueLabel, 0, Qt::AlignHCenter);

        settingsButton = new QPushButton(homePage);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setGeometry(QRect(0, 220, 91, 51));
        warningLabel = new QLabel(homePage);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setGeometry(QRect(110, 170, 260, 40));
        warningLabel->setMinimumSize(QSize(260, 0));
        warningLabel->setMaximumSize(QSize(300, 40));
        mainwindowStack->addWidget(homePage);
        drinkpickerPage = new QWidget();
        drinkpickerPage->setObjectName(QString::fromUtf8("drinkpickerPage"));
        layoutWidget_2 = new QWidget(drinkpickerPage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 70, 141, 56));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        creditLabel_2 = new QLabel(layoutWidget_2);
        creditLabel_2->setObjectName(QString::fromUtf8("creditLabel_2"));
        creditLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(creditLabel_2);

        creditValueLabel_2 = new QLabel(layoutWidget_2);
        creditValueLabel_2->setObjectName(QString::fromUtf8("creditValueLabel_2"));
        creditValueLabel_2->setTextFormat(Qt::RichText);
        creditValueLabel_2->setScaledContents(true);
        creditValueLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(creditValueLabel_2);

        layoutWidget_3 = new QWidget(drinkpickerPage);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(260, 20, 214, 229));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        drinkButton1 = new QPushButton(layoutWidget_3);
        drinkButton1->setObjectName(QString::fromUtf8("drinkButton1"));
        sizePolicy.setHeightForWidth(drinkButton1->sizePolicy().hasHeightForWidth());
        drinkButton1->setSizePolicy(sizePolicy);
        drinkButton1->setMinimumSize(QSize(101, 71));
        drinkButton1->setMaximumSize(QSize(101, 71));

        verticalLayout_4->addWidget(drinkButton1);

        drinkButton2 = new QPushButton(layoutWidget_3);
        drinkButton2->setObjectName(QString::fromUtf8("drinkButton2"));
        sizePolicy.setHeightForWidth(drinkButton2->sizePolicy().hasHeightForWidth());
        drinkButton2->setSizePolicy(sizePolicy);
        drinkButton2->setMinimumSize(QSize(101, 71));
        drinkButton2->setMaximumSize(QSize(101, 71));

        verticalLayout_4->addWidget(drinkButton2);

        drinkButton3 = new QPushButton(layoutWidget_3);
        drinkButton3->setObjectName(QString::fromUtf8("drinkButton3"));
        sizePolicy.setHeightForWidth(drinkButton3->sizePolicy().hasHeightForWidth());
        drinkButton3->setSizePolicy(sizePolicy);
        drinkButton3->setMinimumSize(QSize(101, 71));
        drinkButton3->setMaximumSize(QSize(101, 71));

        verticalLayout_4->addWidget(drinkButton3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        drinkButton4 = new QPushButton(layoutWidget_3);
        drinkButton4->setObjectName(QString::fromUtf8("drinkButton4"));
        sizePolicy.setHeightForWidth(drinkButton4->sizePolicy().hasHeightForWidth());
        drinkButton4->setSizePolicy(sizePolicy);
        drinkButton4->setMinimumSize(QSize(101, 71));
        drinkButton4->setMaximumSize(QSize(101, 71));

        verticalLayout->addWidget(drinkButton4);

        drinkButton5 = new QPushButton(layoutWidget_3);
        drinkButton5->setObjectName(QString::fromUtf8("drinkButton5"));
        sizePolicy.setHeightForWidth(drinkButton5->sizePolicy().hasHeightForWidth());
        drinkButton5->setSizePolicy(sizePolicy);
        drinkButton5->setMinimumSize(QSize(101, 71));
        drinkButton5->setMaximumSize(QSize(101, 71));

        verticalLayout->addWidget(drinkButton5);

        drinkButton6 = new QPushButton(layoutWidget_3);
        drinkButton6->setObjectName(QString::fromUtf8("drinkButton6"));
        sizePolicy.setHeightForWidth(drinkButton6->sizePolicy().hasHeightForWidth());
        drinkButton6->setSizePolicy(sizePolicy);
        drinkButton6->setMinimumSize(QSize(101, 71));
        drinkButton6->setMaximumSize(QSize(101, 71));

        verticalLayout->addWidget(drinkButton6);


        horizontalLayout->addLayout(verticalLayout);

        drinkPickerHomeButton = new QPushButton(drinkpickerPage);
        drinkPickerHomeButton->setObjectName(QString::fromUtf8("drinkPickerHomeButton"));
        drinkPickerHomeButton->setGeometry(QRect(80, 160, 101, 71));
        drinkPickerHomeButton->setMinimumSize(QSize(101, 71));
        drinkPickerHomeButton->setMaximumSize(QSize(101, 71));
        expensiveLabel = new QLabel(drinkpickerPage);
        expensiveLabel->setObjectName(QString::fromUtf8("expensiveLabel"));
        expensiveLabel->setGeometry(QRect(20, 30, 231, 20));
        mainwindowStack->addWidget(drinkpickerPage);
        pleaseWaitPage = new QWidget();
        pleaseWaitPage->setObjectName(QString::fromUtf8("pleaseWaitPage"));
        pleaseWaitLabel = new QLabel(pleaseWaitPage);
        pleaseWaitLabel->setObjectName(QString::fromUtf8("pleaseWaitLabel"));
        pleaseWaitLabel->setGeometry(QRect(0, 0, 481, 271));
        mainwindowStack->addWidget(pleaseWaitPage);
        servicePage = new QWidget();
        servicePage->setObjectName(QString::fromUtf8("servicePage"));
        layoutWidget_4 = new QWidget(servicePage);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(60, 20, 103, 227));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        replaceBottlesButton = new QPushButton(layoutWidget_4);
        replaceBottlesButton->setObjectName(QString::fromUtf8("replaceBottlesButton"));
        replaceBottlesButton->setMinimumSize(QSize(101, 71));
        replaceBottlesButton->setMaximumSize(QSize(101, 71));

        verticalLayout_5->addWidget(replaceBottlesButton);

        systemSettingsButton = new QPushButton(layoutWidget_4);
        systemSettingsButton->setObjectName(QString::fromUtf8("systemSettingsButton"));
        systemSettingsButton->setMinimumSize(QSize(101, 71));
        systemSettingsButton->setMaximumSize(QSize(101, 71));

        verticalLayout_5->addWidget(systemSettingsButton);

        line_3 = new QFrame(servicePage);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(220, 0, 20, 271));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        serviceHomeButton = new QPushButton(servicePage);
        serviceHomeButton->setObjectName(QString::fromUtf8("serviceHomeButton"));
        serviceHomeButton->setGeometry(QRect(310, 100, 101, 71));
        serviceHomeButton->setMinimumSize(QSize(101, 71));
        serviceHomeButton->setMaximumSize(QSize(101, 71));
        iDrinkLabel_3 = new QLabel(servicePage);
        iDrinkLabel_3->setObjectName(QString::fromUtf8("iDrinkLabel_3"));
        iDrinkLabel_3->setGeometry(QRect(320, 20, 81, 41));
        mainwindowStack->addWidget(servicePage);
        replaceBottlesPage = new QWidget();
        replaceBottlesPage->setObjectName(QString::fromUtf8("replaceBottlesPage"));
        settingsBackButton = new QPushButton(replaceBottlesPage);
        settingsBackButton->setObjectName(QString::fromUtf8("settingsBackButton"));
        settingsBackButton->setGeometry(QRect(310, 100, 101, 71));
        settingsBackButton->setMinimumSize(QSize(101, 71));
        settingsBackButton->setMaximumSize(QSize(101, 71));
        line_7 = new QFrame(replaceBottlesPage);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(220, 0, 20, 271));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(replaceBottlesPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 30, 211, 51));
        layoutWidget1 = new QWidget(replaceBottlesPage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 214, 229));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        bottleButton = new QPushButton(layoutWidget1);
        bottleButton->setObjectName(QString::fromUtf8("bottleButton"));
        bottleButton->setMinimumSize(QSize(101, 71));
        bottleButton->setMaximumSize(QSize(101, 71));

        verticalLayout_7->addWidget(bottleButton);

        bottleButton_4 = new QPushButton(layoutWidget1);
        bottleButton_4->setObjectName(QString::fromUtf8("bottleButton_4"));
        bottleButton_4->setMinimumSize(QSize(101, 71));
        bottleButton_4->setMaximumSize(QSize(101, 71));

        verticalLayout_7->addWidget(bottleButton_4);

        bottleButton_6 = new QPushButton(layoutWidget1);
        bottleButton_6->setObjectName(QString::fromUtf8("bottleButton_6"));
        bottleButton_6->setMinimumSize(QSize(101, 71));
        bottleButton_6->setMaximumSize(QSize(101, 71));

        verticalLayout_7->addWidget(bottleButton_6);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        bottleButton_2 = new QPushButton(layoutWidget1);
        bottleButton_2->setObjectName(QString::fromUtf8("bottleButton_2"));
        bottleButton_2->setMinimumSize(QSize(101, 71));
        bottleButton_2->setMaximumSize(QSize(101, 71));

        verticalLayout_8->addWidget(bottleButton_2);

        bottleButton_3 = new QPushButton(layoutWidget1);
        bottleButton_3->setObjectName(QString::fromUtf8("bottleButton_3"));
        bottleButton_3->setMinimumSize(QSize(101, 71));
        bottleButton_3->setMaximumSize(QSize(101, 71));

        verticalLayout_8->addWidget(bottleButton_3);

        bottleButton_5 = new QPushButton(layoutWidget1);
        bottleButton_5->setObjectName(QString::fromUtf8("bottleButton_5"));
        bottleButton_5->setMinimumSize(QSize(101, 71));
        bottleButton_5->setMaximumSize(QSize(101, 71));

        verticalLayout_8->addWidget(bottleButton_5);


        horizontalLayout_2->addLayout(verticalLayout_8);

        mainwindowStack->addWidget(replaceBottlesPage);
        systemSettingsPage = new QWidget();
        systemSettingsPage->setObjectName(QString::fromUtf8("systemSettingsPage"));
        settingsBackButton_2 = new QPushButton(systemSettingsPage);
        settingsBackButton_2->setObjectName(QString::fromUtf8("settingsBackButton_2"));
        settingsBackButton_2->setGeometry(QRect(310, 100, 101, 71));
        settingsBackButton_2->setMinimumSize(QSize(101, 71));
        settingsBackButton_2->setMaximumSize(QSize(101, 71));
        line_8 = new QFrame(systemSettingsPage);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(220, 0, 20, 271));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(systemSettingsPage);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 131, 48));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);

        addressBox = new QComboBox(layoutWidget2);
        addressBox->setObjectName(QString::fromUtf8("addressBox"));

        verticalLayout_6->addWidget(addressBox);

        widget = new QWidget(systemSettingsPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 150, 167, 110));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        testDBButton = new QPushButton(widget);
        testDBButton->setObjectName(QString::fromUtf8("testDBButton"));
        testDBButton->setMinimumSize(QSize(0, 50));

        verticalLayout_9->addWidget(testDBButton);

        testPsocButton = new QPushButton(widget);
        testPsocButton->setObjectName(QString::fromUtf8("testPsocButton"));
        testPsocButton->setMinimumSize(QSize(0, 50));

        verticalLayout_9->addWidget(testPsocButton);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        DBStatusLabel = new QLabel(widget);
        DBStatusLabel->setObjectName(QString::fromUtf8("DBStatusLabel"));

        verticalLayout_10->addWidget(DBStatusLabel);

        PsocStatusLabel = new QLabel(widget);
        PsocStatusLabel->setObjectName(QString::fromUtf8("PsocStatusLabel"));

        verticalLayout_10->addWidget(PsocStatusLabel);


        horizontalLayout_3->addLayout(verticalLayout_10);

        mainwindowStack->addWidget(systemSettingsPage);
        systemStatusPage = new QWidget();
        systemStatusPage->setObjectName(QString::fromUtf8("systemStatusPage"));
        mainwindowStack->addWidget(systemStatusPage);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        mainwindowStack->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        testButton->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
        iDrinkLabel->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Liberation Sans'; font-size:24pt;\">iDrink </span><span style=\" font-family:'Liberation Sans'; font-size:24pt; vertical-align:super;\">TM</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        creditValueLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        settingsButton->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        warningLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Warning! System Error, contact employee.</p></body></html>", 0, QApplication::UnicodeUTF8));
        creditLabel_2->setText(QApplication::translate("MainWindow", "Credit:", 0, QApplication::UnicodeUTF8));
        creditValueLabel_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        drinkButton1->setText(QApplication::translate("MainWindow", "Drink 1", 0, QApplication::UnicodeUTF8));
        drinkButton2->setText(QApplication::translate("MainWindow", "Drink 2", 0, QApplication::UnicodeUTF8));
        drinkButton3->setText(QApplication::translate("MainWindow", "Drink 3", 0, QApplication::UnicodeUTF8));
        drinkButton4->setText(QApplication::translate("MainWindow", "Drink 4", 0, QApplication::UnicodeUTF8));
        drinkButton5->setText(QApplication::translate("MainWindow", "Drink 5", 0, QApplication::UnicodeUTF8));
        drinkButton6->setText(QApplication::translate("MainWindow", "Drink 6", 0, QApplication::UnicodeUTF8));
        drinkPickerHomeButton->setText(QApplication::translate("MainWindow", "Home", 0, QApplication::UnicodeUTF8));
        expensiveLabel->setText(QApplication::translate("MainWindow", "That drink is too expensive for you..", 0, QApplication::UnicodeUTF8));
        pleaseWaitLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Please Wait..</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        replaceBottlesButton->setText(QApplication::translate("MainWindow", "Replace Bottles", 0, QApplication::UnicodeUTF8));
        systemSettingsButton->setText(QApplication::translate("MainWindow", "System Settings", 0, QApplication::UnicodeUTF8));
        serviceHomeButton->setText(QApplication::translate("MainWindow", "Home", 0, QApplication::UnicodeUTF8));
        iDrinkLabel_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">iDrink</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        settingsBackButton->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">When the Bottle is replaced,</p><p align=\"center\"> please click the button accordingly.</p></body></html>", 0, QApplication::UnicodeUTF8));
        bottleButton->setText(QApplication::translate("MainWindow", "Bottle1", 0, QApplication::UnicodeUTF8));
        bottleButton_4->setText(QApplication::translate("MainWindow", "Bottle3", 0, QApplication::UnicodeUTF8));
        bottleButton_6->setText(QApplication::translate("MainWindow", "Bottle5", 0, QApplication::UnicodeUTF8));
        bottleButton_2->setText(QApplication::translate("MainWindow", "Bottle2", 0, QApplication::UnicodeUTF8));
        bottleButton_3->setText(QApplication::translate("MainWindow", "Bottle4", 0, QApplication::UnicodeUTF8));
        bottleButton_5->setText(QApplication::translate("MainWindow", "Bottle6", 0, QApplication::UnicodeUTF8));
        settingsBackButton_2->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Database Address:", 0, QApplication::UnicodeUTF8));
        testDBButton->setText(QApplication::translate("MainWindow", "Test Database", 0, QApplication::UnicodeUTF8));
        testPsocButton->setText(QApplication::translate("MainWindow", "Test PSoC", 0, QApplication::UnicodeUTF8));
        DBStatusLabel->setText(QString());
        PsocStatusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
