/****************************************************************************
** Meta object code from reading C++ file 'lyExcelTableModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Widget/lyExcelTableModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lyExcelTableModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lyExcelTableModel_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lyExcelTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lyExcelTableModel_t qt_meta_stringdata_lyExcelTableModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "lyExcelTableModel"
QT_MOC_LITERAL(1, 18, 13), // "setExcelTitle"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "title"
QT_MOC_LITERAL(4, 39, 13), // "writeFinished"
QT_MOC_LITERAL(5, 53, 12) // "readFinished"

    },
    "lyExcelTableModel\0setExcelTitle\0\0title\0"
    "writeFinished\0readFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lyExcelTableModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lyExcelTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lyExcelTableModel *_t = static_cast<lyExcelTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setExcelTitle((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->writeFinished(); break;
        case 2: _t->readFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (lyExcelTableModel::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lyExcelTableModel::setExcelTitle)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (lyExcelTableModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lyExcelTableModel::writeFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (lyExcelTableModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lyExcelTableModel::readFinished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject lyExcelTableModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_lyExcelTableModel.data,
      qt_meta_data_lyExcelTableModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lyExcelTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lyExcelTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lyExcelTableModel.stringdata0))
        return static_cast<void*>(const_cast< lyExcelTableModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int lyExcelTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void lyExcelTableModel::setExcelTitle(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lyExcelTableModel::writeFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void lyExcelTableModel::readFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
