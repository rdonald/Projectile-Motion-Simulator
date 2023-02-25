/****************************************************************************
** Meta object code from reading C++ file 'worldstate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Projectile-Motion-Simulator/worldstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worldstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorldState_t {
    const uint offsetsAndSize[16];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WorldState_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WorldState_t qt_meta_stringdata_WorldState = {
    {
QT_MOC_LITERAL(0, 10), // "WorldState"
QT_MOC_LITERAL(11, 11), // "getNextStep"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 37), // "std::vector<std::tuple<float,..."
QT_MOC_LITERAL(62, 8), // "b2World*"
QT_MOC_LITERAL(71, 7), // "b2Body*"
QT_MOC_LITERAL(79, 19), // "calculateTrajectory"
QT_MOC_LITERAL(99, 21) // "getNextTrajectoryStep"

    },
    "WorldState\0getNextStep\0\0"
    "std::vector<std::tuple<float,float>>&\0"
    "b2World*\0b2Body*\0calculateTrajectory\0"
    "getNextTrajectoryStep"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorldState[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   39,    2, 0x0a,    5 /* Public */,
       7,    3,   42,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,

       0        // eod
};

void WorldState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorldState *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getNextStep((*reinterpret_cast< std::vector<std::tuple<float,float>>(*)>(_a[1])),(*reinterpret_cast< b2World*(*)>(_a[2])),(*reinterpret_cast< b2Body*(*)>(_a[3]))); break;
        case 1: _t->calculateTrajectory((*reinterpret_cast< std::vector<std::tuple<float,float>>(*)>(_a[1]))); break;
        case 2: _t->getNextTrajectoryStep((*reinterpret_cast< std::vector<std::tuple<float,float>>(*)>(_a[1])),(*reinterpret_cast< b2World*(*)>(_a[2])),(*reinterpret_cast< b2Body*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorldState::*)(std::vector<std::tuple<float,float>> & , b2World * , b2Body * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorldState::getNextStep)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WorldState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WorldState.offsetsAndSize,
    qt_meta_data_WorldState,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WorldState_t
, QtPrivate::TypeAndForceComplete<WorldState, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::tuple<float,float>> &, std::false_type>, QtPrivate::TypeAndForceComplete<b2World *, std::false_type>, QtPrivate::TypeAndForceComplete<b2Body *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::tuple<float,float>> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::tuple<float,float>> &, std::false_type>, QtPrivate::TypeAndForceComplete<b2World *, std::false_type>, QtPrivate::TypeAndForceComplete<b2Body *, std::false_type>


>,
    nullptr
} };


const QMetaObject *WorldState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorldState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorldState.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WorldState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WorldState::getNextStep(std::vector<std::tuple<float,float>> & _t1, b2World * _t2, b2Body * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
