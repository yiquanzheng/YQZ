/****************************************************************************
** Meta object code from reading C++ file 'ModeSettingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ModeSettingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModeSettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModeSettingWidget_t {
    QByteArrayData data[15];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModeSettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModeSettingWidget_t qt_meta_stringdata_ModeSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ModeSettingWidget"
QT_MOC_LITERAL(1, 18, 10), // "updateMode"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "faultModelSelected"
QT_MOC_LITERAL(4, 49, 12), // "modelChanged"
QT_MOC_LITERAL(5, 62, 16), // "modeltextChanged"
QT_MOC_LITERAL(6, 79, 4), // "text"
QT_MOC_LITERAL(7, 84, 12), // "cabinChanged"
QT_MOC_LITERAL(8, 97, 16), // "cabintextChanged"
QT_MOC_LITERAL(9, 114, 11), // "hostChanged"
QT_MOC_LITERAL(10, 126, 15), // "hosttextChanged"
QT_MOC_LITERAL(11, 142, 15), // "softwareChanged"
QT_MOC_LITERAL(12, 158, 19), // "softwaretextChanged"
QT_MOC_LITERAL(13, 178, 7), // "comfrim"
QT_MOC_LITERAL(14, 186, 5) // "clear"

    },
    "ModeSettingWidget\0updateMode\0\0"
    "faultModelSelected\0modelChanged\0"
    "modeltextChanged\0text\0cabinChanged\0"
    "cabintextChanged\0hostChanged\0"
    "hosttextChanged\0softwareChanged\0"
    "softwaretextChanged\0comfrim\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModeSettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModeSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModeSettingWidget *_t = static_cast<ModeSettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMode(); break;
        case 1: _t->faultModelSelected(); break;
        case 2: _t->modelChanged(); break;
        case 3: _t->modeltextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->cabinChanged(); break;
        case 5: _t->cabintextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->hostChanged(); break;
        case 7: _t->hosttextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->softwareChanged(); break;
        case 9: _t->softwaretextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->comfrim(); break;
        case 11: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModeSettingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModeSettingWidget::updateMode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ModeSettingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModeSettingWidget.data,
      qt_meta_data_ModeSettingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModeSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModeSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModeSettingWidget.stringdata0))
        return static_cast<void*>(const_cast< ModeSettingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ModeSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ModeSettingWidget::updateMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
