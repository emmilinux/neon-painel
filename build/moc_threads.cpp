/****************************************************************************
** Meta object code from reading C++ file 'threads.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Neon_Panel/threads.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threads.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Threads_t {
    QByteArrayData data[9];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Threads_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Threads_t qt_meta_stringdata_Threads = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 8),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 9),
QT_MOC_LITERAL(4, 28, 15),
QT_MOC_LITERAL(5, 44, 4),
QT_MOC_LITERAL(6, 49, 7),
QT_MOC_LITERAL(7, 57, 5),
QT_MOC_LITERAL(8, 63, 14)
    },
    "Threads\0onCreate\0\0onDestroy\0onDesktopWindow\0"
    "nome\0wmclass\0winId\0onClearWindows"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Threads[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    3,   36,    2, 0x06 /* Public */,
       8,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    5,    6,    7,
    QMetaType::Void,

       0        // eod
};

void Threads::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Threads *_t = static_cast<Threads *>(_o);
        switch (_id) {
        case 0: _t->onCreate(); break;
        case 1: _t->onDestroy(); break;
        case 2: _t->onDesktopWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->onClearWindows(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Threads::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Threads::onCreate)) {
                *result = 0;
            }
        }
        {
            typedef void (Threads::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Threads::onDestroy)) {
                *result = 1;
            }
        }
        {
            typedef void (Threads::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Threads::onDesktopWindow)) {
                *result = 2;
            }
        }
        {
            typedef void (Threads::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Threads::onClearWindows)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Threads::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Threads.data,
      qt_meta_data_Threads,  qt_static_metacall, 0, 0}
};


const QMetaObject *Threads::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Threads::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Threads.stringdata))
        return static_cast<void*>(const_cast< Threads*>(this));
    return QThread::qt_metacast(_clname);
}

int Threads::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Threads::onCreate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Threads::onDestroy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Threads::onDesktopWindow(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Threads::onClearWindows()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
