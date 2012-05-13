/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat May 12 19:02:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      57,   54,   11,   11, 0x08,
      86,   78,   74,   11, 0x08,
     114,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     236,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     314,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     366,   11,   11,   11, 0x08,
     392,   11,   11,   11, 0x08,
     418,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0donePouring()\0returnHome()\0"
    "settingsBack()\0id\0onNewID(QString)\0"
    "int\0drinkNo\0drinkButtonClicked(QString)\0"
    "on_settingsButton_clicked()\0"
    "on_replaceBottlesButton_clicked()\0"
    "on_systemSettingsButton_clicked()\0"
    "on_testDBButton_clicked()\0"
    "on_testPsocButton_clicked()\0"
    "on_testButton_clicked()\0"
    "on_drinkButton1_clicked()\0"
    "on_drinkButton2_clicked()\0"
    "on_drinkButton3_clicked()\0"
    "on_drinkButton4_clicked()\0"
    "on_drinkButton5_clicked()\0"
    "on_drinkButton6_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->donePouring(); break;
        case 1: _t->returnHome(); break;
        case 2: _t->settingsBack(); break;
        case 3: _t->onNewID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { int _r = _t->drinkButtonClicked((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->on_settingsButton_clicked(); break;
        case 6: _t->on_replaceBottlesButton_clicked(); break;
        case 7: _t->on_systemSettingsButton_clicked(); break;
        case 8: _t->on_testDBButton_clicked(); break;
        case 9: _t->on_testPsocButton_clicked(); break;
        case 10: _t->on_testButton_clicked(); break;
        case 11: _t->on_drinkButton1_clicked(); break;
        case 12: _t->on_drinkButton2_clicked(); break;
        case 13: _t->on_drinkButton3_clicked(); break;
        case 14: _t->on_drinkButton4_clicked(); break;
        case 15: _t->on_drinkButton5_clicked(); break;
        case 16: _t->on_drinkButton6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::donePouring()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
