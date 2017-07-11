/****************************************************************************
** Meta object code from reading C++ file 'genemy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game1/genemy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genemy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GEnemy_t {
    QByteArrayData data[7];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GEnemy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GEnemy_t qt_meta_stringdata_GEnemy = {
    {
QT_MOC_LITERAL(0, 0, 6), // "GEnemy"
QT_MOC_LITERAL(1, 7, 4), // "died"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 7), // "spawned"
QT_MOC_LITERAL(4, 21, 4), // "calc"
QT_MOC_LITERAL(5, 26, 5), // "order"
QT_MOC_LITERAL(6, 32, 5) // "spawn"

    },
    "GEnemy\0died\0\0spawned\0calc\0order\0spawn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GEnemy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GEnemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GEnemy *_t = static_cast<GEnemy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->died(); break;
        case 1: _t->spawned(); break;
        case 2: _t->calc(); break;
        case 3: _t->order(); break;
        case 4: _t->spawn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GEnemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GEnemy::died)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GEnemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GEnemy::spawned)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GEnemy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GEnemy.data,
      qt_meta_data_GEnemy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GEnemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GEnemy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GEnemy.stringdata0))
        return static_cast<void*>(const_cast< GEnemy*>(this));
    if (!strcmp(_clname, "GTurret"))
        return static_cast< GTurret*>(const_cast< GEnemy*>(this));
    return QObject::qt_metacast(_clname);
}

int GEnemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GEnemy::died()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GEnemy::spawned()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
