/****************************************************************************
** Meta object code from reading C++ file 'carddatabase.h'
**
** Created: Mon May 7 14:48:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "carddatabase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carddatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CardDatabase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   43,   13,   13, 0x0a,
      87,   83,   75,   13, 0x0a,
     101,   83,   75,   13, 0x0a,
     121,  118,   75,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CardDatabase[] = {
    "CardDatabase\0\0credit\0returnCredit(QString)\0"
    "_id,_amount\0updateCard(int,int)\0QString\0"
    "_id\0lookupID(int)\0lookupDrink(int)\0"
    "id\0lookupDrinkName(int)\0"
};

void CardDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CardDatabase *_t = static_cast<CardDatabase *>(_o);
        switch (_id) {
        case 0: _t->returnCredit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateCard((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: { QString _r = _t->lookupID((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->lookupDrink((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->lookupDrinkName((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CardDatabase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CardDatabase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CardDatabase,
      qt_meta_data_CardDatabase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CardDatabase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CardDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CardDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CardDatabase))
        return static_cast<void*>(const_cast< CardDatabase*>(this));
    return QObject::qt_metacast(_clname);
}

int CardDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CardDatabase::returnCredit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
