/****************************************************************************
** Meta object code from reading C++ file 'psoc.h'
**
** Created: Sat May 12 19:02:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "psoc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'psoc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PsocReader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PsocReader[] = {
    "PsocReader\0\0data\0sendData(QString)\0"
};

void PsocReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PsocReader *_t = static_cast<PsocReader *>(_o);
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PsocReader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PsocReader::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PsocReader,
      qt_meta_data_PsocReader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PsocReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PsocReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PsocReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PsocReader))
        return static_cast<void*>(const_cast< PsocReader*>(this));
    return QThread::qt_metacast(_clname);
}

int PsocReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void PsocReader::sendData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Psoc[] = {

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
       6,    5,    5,    5, 0x05,
      23,   16,    5,    5, 0x05,
      49,   42,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   67,    5,    5, 0x0a,
      99,   90,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Psoc[] = {
    "Psoc\0\0cupFull()\0_error\0commError(QString)\0"
    "_value\0bottleStatus(int)\0_id\0"
    "requestStatus(int)\0_drinkId\0"
    "requestDrink(int)\0"
};

void Psoc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Psoc *_t = static_cast<Psoc *>(_o);
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

const QMetaObjectExtraData Psoc::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Psoc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Psoc,
      qt_meta_data_Psoc, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Psoc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Psoc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Psoc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Psoc))
        return static_cast<void*>(const_cast< Psoc*>(this));
    return QObject::qt_metacast(_clname);
}

int Psoc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Psoc::cupFull()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Psoc::commError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Psoc::bottleStatus(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
