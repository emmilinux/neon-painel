/****************************************************************************
** Meta object code from reading C++ file 'context.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Neon_Panel/context.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'context.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Context_t {
    QByteArrayData data[28];
    char stringdata[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Context_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Context_t qt_meta_stringdata_Context = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 11),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 3),
QT_MOC_LITERAL(4, 25, 6),
QT_MOC_LITERAL(5, 32, 6),
QT_MOC_LITERAL(6, 39, 4),
QT_MOC_LITERAL(7, 44, 3),
QT_MOC_LITERAL(8, 48, 8),
QT_MOC_LITERAL(9, 57, 3),
QT_MOC_LITERAL(10, 61, 6),
QT_MOC_LITERAL(11, 68, 3),
QT_MOC_LITERAL(12, 72, 13),
QT_MOC_LITERAL(13, 86, 7),
QT_MOC_LITERAL(14, 94, 9),
QT_MOC_LITERAL(15, 104, 11),
QT_MOC_LITERAL(16, 116, 7),
QT_MOC_LITERAL(17, 124, 11),
QT_MOC_LITERAL(18, 136, 7),
QT_MOC_LITERAL(19, 144, 16),
QT_MOC_LITERAL(20, 161, 3),
QT_MOC_LITERAL(21, 165, 8),
QT_MOC_LITERAL(22, 174, 12),
QT_MOC_LITERAL(23, 187, 8),
QT_MOC_LITERAL(24, 196, 5),
QT_MOC_LITERAL(25, 202, 14),
QT_MOC_LITERAL(26, 217, 11),
QT_MOC_LITERAL(27, 229, 11)
    },
    "Context\0addLauncher\0\0app\0mouseX\0mouseY\0"
    "exec\0pro\0minimize\0win\0active\0pid\0"
    "manyMinimizes\0pidname\0minimizes\0"
    "isMinimized\0wmclass\0manyActives\0actives\0"
    "changeThemeColor\0rgb\0isActive\0"
    "applications\0dragDrop\0icone\0addDesktopFile\0"
    "desktopFile\0defaultIcon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Context[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x02 /* Public */,
       4,    0,  102,    2, 0x02 /* Public */,
       5,    0,  103,    2, 0x02 /* Public */,
       6,    1,  104,    2, 0x02 /* Public */,
       8,    1,  107,    2, 0x02 /* Public */,
      10,    1,  110,    2, 0x02 /* Public */,
      12,    1,  113,    2, 0x02 /* Public */,
      14,    1,  116,    2, 0x02 /* Public */,
      15,    1,  119,    2, 0x02 /* Public */,
      17,    1,  122,    2, 0x02 /* Public */,
      18,    1,  125,    2, 0x02 /* Public */,
      19,    1,  128,    2, 0x02 /* Public */,
      21,    1,  131,    2, 0x02 /* Public */,
      22,    0,  134,    2, 0x02 /* Public */,
      23,    2,  135,    2, 0x02 /* Public */,
      25,    2,  140,    2, 0x02 /* Public */,
      27,    0,  145,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QStringList, QMetaType::QString,    3,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Int, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Int, QMetaType::QString,   13,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   24,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   26,
    QMetaType::QString,

       0        // eod
};

void Context::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Context *_t = static_cast<Context *>(_o);
        switch (_id) {
        case 0: { QStringList _r = _t->addLauncher((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->mouseX();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->mouseY();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->exec((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->minimize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->active((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->manyMinimizes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->minimizes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { int _r = _t->isMinimized((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->manyActives((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->actives((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->changeThemeColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: { int _r = _t->isActive((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { QStringList _r = _t->applications();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 14: _t->dragDrop((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->addDesktopFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: { QString _r = _t->defaultIcon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Context::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Context.data,
      qt_meta_data_Context,  qt_static_metacall, 0, 0}
};


const QMetaObject *Context::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Context::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Context.stringdata))
        return static_cast<void*>(const_cast< Context*>(this));
    if (!strcmp(_clname, "Xlibutil"))
        return static_cast< Xlibutil*>(const_cast< Context*>(this));
    return QObject::qt_metacast(_clname);
}

int Context::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
