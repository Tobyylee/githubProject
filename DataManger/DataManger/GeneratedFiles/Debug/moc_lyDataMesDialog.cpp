/****************************************************************************
** Meta object code from reading C++ file 'lyDataMesDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Widget/lyDataMesDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lyDataMesDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lyDataMesDialog_t {
    QByteArrayData data[12];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lyDataMesDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lyDataMesDialog_t qt_meta_stringdata_lyDataMesDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "lyDataMesDialog"
QT_MOC_LITERAL(1, 16, 16), // "onDateTypeSelect"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "index"
QT_MOC_LITERAL(4, 40, 17), // "onDateSiteClicked"
QT_MOC_LITERAL(5, 58, 21), // "onBeginDateFinishEdit"
QT_MOC_LITERAL(6, 80, 20), // "onEndTDateFinishEdit"
QT_MOC_LITERAL(7, 101, 9), // "onConfirm"
QT_MOC_LITERAL(8, 111, 8), // "onCancle"
QT_MOC_LITERAL(9, 120, 22), // "onFinishDataSiteSelect"
QT_MOC_LITERAL(10, 143, 8), // "cityName"
QT_MOC_LITERAL(11, 152, 16) // "onMeetSiteSelect"

    },
    "lyDataMesDialog\0onDateTypeSelect\0\0"
    "index\0onDateSiteClicked\0onBeginDateFinishEdit\0"
    "onEndTDateFinishEdit\0onConfirm\0onCancle\0"
    "onFinishDataSiteSelect\0cityName\0"
    "onMeetSiteSelect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lyDataMesDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void lyDataMesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lyDataMesDialog *_t = static_cast<lyDataMesDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDateTypeSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onDateSiteClicked(); break;
        case 2: _t->onBeginDateFinishEdit(); break;
        case 3: _t->onEndTDateFinishEdit(); break;
        case 4: _t->onConfirm(); break;
        case 5: _t->onCancle(); break;
        case 6: _t->onFinishDataSiteSelect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onMeetSiteSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject lyDataMesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_lyDataMesDialog.data,
      qt_meta_data_lyDataMesDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lyDataMesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lyDataMesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lyDataMesDialog.stringdata0))
        return static_cast<void*>(const_cast< lyDataMesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int lyDataMesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
