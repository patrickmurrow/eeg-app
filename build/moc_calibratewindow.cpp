/****************************************************************************
** Meta object code from reading C++ file 'calibratewindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/eeg-app/calibratewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibratewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalibrateWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      38,   16,   16,   16, 0x08,
      69,   60,   16,   16, 0x08,
      93,   16,   16,   16, 0x08,
     117,  112,   16,   16, 0x08,
     139,   16,   16,   16, 0x08,
     167,  162,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CalibrateWindow[] = {
    "CalibrateWindow\0\0on_btnBack_clicked()\0"
    "on_btnBegin_clicked()\0msg,time\0"
    "txtChanged(QString,int)\0startDataCollect()\0"
    "open\0stopDataCollect(bool)\0"
    "on_btnCancel_clicked()\0arg1\0"
    "on_cmbHeadset_activated(QString)\0"
};

void CalibrateWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalibrateWindow *_t = static_cast<CalibrateWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnBack_clicked(); break;
        case 1: _t->on_btnBegin_clicked(); break;
        case 2: _t->txtChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->startDataCollect(); break;
        case 4: _t->stopDataCollect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_btnCancel_clicked(); break;
        case 6: _t->on_cmbHeadset_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CalibrateWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalibrateWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalibrateWindow,
      qt_meta_data_CalibrateWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalibrateWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalibrateWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalibrateWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrateWindow))
        return static_cast<void*>(const_cast< CalibrateWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalibrateWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
