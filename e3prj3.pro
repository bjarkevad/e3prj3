#-------------------------------------------------
#
# Project created by QtCreator 2012-03-26T11:50:44
#
#-------------------------------------------------

QT       += core gui\
            sql\

TARGET = e3prj3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carddatabase.cpp \
    rfid.cpp \
    QAsyncSerial.cpp \
    AsyncSerial.cpp \
    psoc.cpp

HEADERS  += mainwindow.h \
    carddatabase.h \
    rfid.h \
    QAsyncSerial.h \
    AsyncSerial.h \
    psoc.h

LIBS += -lboost_system \
        -lboost_thread \

FORMS    += mainwindow.ui

