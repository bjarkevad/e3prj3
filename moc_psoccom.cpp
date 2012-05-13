/****************************************************************************
** Meta object code from reading C++ file 'psoccom.h'
**
** Created: Tue Apr 24 11:33:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "psoccom.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'psoccom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_psocCom[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      26,   19,    8,    8, 0x05,
      52,   45,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   70,    8,    8, 0x0a,
     102,   93,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_psocCom[] = {
    "psocCom\0\0cupFull()\0_error\0commError(QString)\0"
    "_value\0bottleStatus(int)\0_id\0"
    "requestStatus(int)\0_drinkId\0"
    "requestDrink(int)\0"
};

void psocCom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        psocCom *_t = static_cast<psocCom *>(_o);
        switch (_id) {
        case 0: _t->cupFull(); break;
        case 1: _t->commError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->bottleStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->requestStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->requestDrink((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData psocCom::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject psocCom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_psocCom,
      qt_meta_data_psocCom, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &psocCom::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *psocCom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *psocCom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_psocCom))
        return static_cast<void*>(const_cast< psocCom*>(this));
    return QObject::qt_metacast(_clname);
}

int psocCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void psocCom::cupFull()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void psocCom::commError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void psocCom::bottleStatus(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
