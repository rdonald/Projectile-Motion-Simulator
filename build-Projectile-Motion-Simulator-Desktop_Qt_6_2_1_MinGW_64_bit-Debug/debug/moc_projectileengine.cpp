/****************************************************************************
** Meta object code from reading C++ file 'projectileengine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Projectile-Motion-Simulator/projectileengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projectileengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProjectileEngine_t {
    const uint offsetsAndSize[44];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProjectileEngine_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProjectileEngine_t qt_meta_stringdata_ProjectileEngine = {
    {
QT_MOC_LITERAL(0, 16), // "ProjectileEngine"
QT_MOC_LITERAL(17, 14), // "updateVariable"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 7), // "varType"
QT_MOC_LITERAL(41, 5), // "value"
QT_MOC_LITERAL(47, 12), // "updateCannon"
QT_MOC_LITERAL(60, 6), // "height"
QT_MOC_LITERAL(67, 5), // "angle"
QT_MOC_LITERAL(73, 13), // "getTrajectory"
QT_MOC_LITERAL(87, 37), // "std::vector<std::tuple<float,..."
QT_MOC_LITERAL(125, 14), // "sendTrajectory"
QT_MOC_LITERAL(140, 36), // "std::vector<std::tuple<float,..."
QT_MOC_LITERAL(177, 18), // "changeAngleInModel"
QT_MOC_LITERAL(196, 8), // "newAngle"
QT_MOC_LITERAL(205, 19), // "changeHeightInModel"
QT_MOC_LITERAL(225, 9), // "newHeight"
QT_MOC_LITERAL(235, 20), // "changeGravityInModel"
QT_MOC_LITERAL(256, 10), // "newGravity"
QT_MOC_LITERAL(267, 21), // "changeVelocityInModel"
QT_MOC_LITERAL(289, 11), // "newVelocity"
QT_MOC_LITERAL(301, 25), // "changeWorldStateToDefault"
QT_MOC_LITERAL(327, 7) // "getFire"

    },
    "ProjectileEngine\0updateVariable\0\0"
    "varType\0value\0updateCannon\0height\0"
    "angle\0getTrajectory\0"
    "std::vector<std::tuple<float,float>>&\0"
    "sendTrajectory\0std::vector<std::tuple<float,float>>\0"
    "changeAngleInModel\0newAngle\0"
    "changeHeightInModel\0newHeight\0"
    "changeGravityInModel\0newGravity\0"
    "changeVelocityInModel\0newVelocity\0"
    "changeWorldStateToDefault\0getFire"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjectileEngine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,
       5,    2,   79,    2, 0x06,    4 /* Public */,
       8,    1,   84,    2, 0x06,    7 /* Public */,
      10,    1,   87,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,   90,    2, 0x0a,   11 /* Public */,
      14,    1,   93,    2, 0x0a,   13 /* Public */,
      16,    1,   96,    2, 0x0a,   15 /* Public */,
      18,    1,   99,    2, 0x0a,   17 /* Public */,
      20,    0,  102,    2, 0x0a,   19 /* Public */,
      21,    0,  103,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProjectileEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProjectileEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateVariable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->updateCannon((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->getTrajectory((*reinterpret_cast< std::vector<std::tuple<float,float>>(*)>(_a[1]))); break;
        case 3: _t->sendTrajectory((*reinterpret_cast< std::vector<std::tuple<float,float>>(*)>(_a[1]))); break;
        case 4: _t->changeAngleInModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeHeightInModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changeGravityInModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeVelocityInModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeWorldStateToDefault(); break;
        case 9: _t->getFire(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProjectileEngine::*)(int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProjectileEngine::updateVariable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProjectileEngine::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProjectileEngine::updateCannon)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProjectileEngine::*)(std::vector<std::tuple<float,float>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProjectileEngine::getTrajectory)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProjectileEngine::*)(std::vector<std::tuple<float,float>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProjectileEngine::sendTrajectory)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ProjectileEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProjectileEngine.offsetsAndSize,
    qt_meta_data_ProjectileEngine,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProjectileEngine_t
, QtPrivate::TypeAndForceComplete<ProjectileEngine, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::tuple<float,float>> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::tuple<float,float>>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProjectileEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectileEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectileEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProjectileEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ProjectileEngine::updateVariable(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProjectileEngine::updateCannon(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProjectileEngine::getTrajectory(std::vector<std::tuple<float,float>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProjectileEngine::sendTrajectory(std::vector<std::tuple<float,float>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
