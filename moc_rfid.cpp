/****************************************************************************
** Meta object code from reading C++ file 'rfid.h'
**
** Created: Wed May 2 17:19:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rfid.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rfid[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,    6,    5,    5, 0x0a,
      44,    5,    5,    5, 0x0a,
      60,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rfid[] = {
    "rfid\0\0_ID\0newID(QString)\0receiveID(QString)\0"
    "sendRequestID()\0sendReset()\0"
};

void rfid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rfid *_t = static_cast<rfid *>(_o);
        switch (_id) {
        case 0: _t->newID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receiveID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendRequestID(); break;
        case 3: _t->sendReset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rfid::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rfid::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rfid,
      qt_meta_data_rfid, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rfid::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rfid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rfid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rfid))
        return static_cast<void*>(const_cast< rfid*>(this));
    return QObject::qt_metacast(_clname);
}

int rfid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void rfid::newID(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
