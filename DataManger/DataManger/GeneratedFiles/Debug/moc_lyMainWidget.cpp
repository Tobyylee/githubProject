/****************************************************************************
** Meta object code from reading C++ file 'lyMainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Widget/lyMainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lyMainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lyMainWidget_t {
    QByteArrayData data[19];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lyMainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lyMainWidget_t qt_meta_stringdata_lyMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "lyMainWidget"
QT_MOC_LITERAL(1, 13, 13), // "readExcelFile"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "writeExcelFile"
QT_MOC_LITERAL(4, 43, 11), // "onActivated"
QT_MOC_LITERAL(5, 55, 5), // "index"
QT_MOC_LITERAL(6, 61, 13), // "onContextMenu"
QT_MOC_LITERAL(7, 75, 5), // "point"
QT_MOC_LITERAL(8, 81, 8), // "onAction"
QT_MOC_LITERAL(9, 90, 15), // "onAddExcelTitle"
QT_MOC_LITERAL(10, 106, 4), // "list"
QT_MOC_LITERAL(11, 111, 10), // "onComboBox"
QT_MOC_LITERAL(12, 122, 14), // "onFindComboBox"
QT_MOC_LITERAL(13, 137, 12), // "onDeletePage"
QT_MOC_LITERAL(14, 150, 11), // "onBuildPage"
QT_MOC_LITERAL(15, 162, 18), // "onOperatorFinished"
QT_MOC_LITERAL(16, 181, 12), // "onCheckTImer"
QT_MOC_LITERAL(17, 194, 11), // "onQueryData"
QT_MOC_LITERAL(18, 206, 8) // "onRename"

    },
    "lyMainWidget\0readExcelFile\0\0writeExcelFile\0"
    "onActivated\0index\0onContextMenu\0point\0"
    "onAction\0onAddExcelTitle\0list\0onComboBox\0"
    "onFindComboBox\0onDeletePage\0onBuildPage\0"
    "onOperatorFinished\0onCheckTImer\0"
    "onQueryData\0onRename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lyMainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   90,    2, 0x0a /* Public */,
       6,    1,   93,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    1,   97,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,
      14,    0,  107,    2, 0x0a /* Public */,
      15,    0,  108,    2, 0x0a /* Public */,
      16,    0,  109,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   10,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lyMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lyMainWidget *_t = static_cast<lyMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readExcelFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->writeExcelFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->onAction(); break;
        case 5: _t->onAddExcelTitle((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 6: _t->onComboBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onFindComboBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onDeletePage(); break;
        case 9: _t->onBuildPage(); break;
        case 10: _t->onOperatorFinished(); break;
        case 11: _t->onCheckTImer(); break;
        case 12: _t->onQueryData(); break;
        case 13: _t->onRename(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (lyMainWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lyMainWidget::readExcelFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (lyMainWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lyMainWidget::writeExcelFile)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject lyMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_lyMainWidget.data,
      qt_meta_data_lyMainWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lyMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lyMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lyMainWidget.stringdata0))
        return static_cast<void*>(const_cast< lyMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int lyMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void lyMainWidget::readExcelFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lyMainWidget::writeExcelFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
