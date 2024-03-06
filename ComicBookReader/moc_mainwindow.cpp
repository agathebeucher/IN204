/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "header/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[50];
    char stringdata0[796];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "loadConfig"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "configFilePath"
QT_MOC_LITERAL(4, 38, 18), // "populateTreeWidget"
QT_MOC_LITERAL(5, 57, 5), // "items"
QT_MOC_LITERAL(6, 63, 25), // "on_treeWidget_itemClicked"
QT_MOC_LITERAL(7, 89, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(8, 106, 4), // "item"
QT_MOC_LITERAL(9, 111, 6), // "column"
QT_MOC_LITERAL(10, 118, 23), // "on_previousPage_clicked"
QT_MOC_LITERAL(11, 142, 19), // "on_nextPage_clicked"
QT_MOC_LITERAL(12, 162, 19), // "on_lastPage_clicked"
QT_MOC_LITERAL(13, 182, 20), // "on_firstPage_clicked"
QT_MOC_LITERAL(14, 203, 18), // "on_ZoomOut_clicked"
QT_MOC_LITERAL(15, 222, 17), // "on_ZoomIn_clicked"
QT_MOC_LITERAL(16, 240, 34), // "on_currPageDisplay_editingFin..."
QT_MOC_LITERAL(17, 275, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(18, 300, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(19, 325, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(20, 349, 28), // "on_actionAssembler_triggered"
QT_MOC_LITERAL(21, 378, 29), // "on_actionSimplePage_triggered"
QT_MOC_LITERAL(22, 408, 29), // "on_actionDoublePage_triggered"
QT_MOC_LITERAL(23, 438, 32), // "on_actionRedimVertical_triggered"
QT_MOC_LITERAL(24, 471, 34), // "on_actionRedimHorizontal_trig..."
QT_MOC_LITERAL(25, 506, 27), // "on_actionBookmark_triggered"
QT_MOC_LITERAL(26, 534, 31), // "on_actionGotobookmark_triggered"
QT_MOC_LITERAL(27, 566, 8), // "setImage"
QT_MOC_LITERAL(28, 575, 5), // "image"
QT_MOC_LITERAL(29, 581, 13), // "refreshScreen"
QT_MOC_LITERAL(30, 595, 14), // "numPageChanged"
QT_MOC_LITERAL(31, 610, 6), // "msgBox"
QT_MOC_LITERAL(32, 617, 3), // "msg"
QT_MOC_LITERAL(33, 621, 11), // "resizeEvent"
QT_MOC_LITERAL(34, 633, 13), // "QResizeEvent*"
QT_MOC_LITERAL(35, 647, 5), // "event"
QT_MOC_LITERAL(36, 653, 14), // "setDefaultZoom"
QT_MOC_LITERAL(37, 668, 13), // "assemblerSlot"
QT_MOC_LITERAL(38, 682, 10), // "QList<int>"
QT_MOC_LITERAL(39, 693, 1), // "l"
QT_MOC_LITERAL(40, 695, 1), // "s"
QT_MOC_LITERAL(41, 697, 11), // "eventFilter"
QT_MOC_LITERAL(42, 709, 7), // "watched"
QT_MOC_LITERAL(43, 717, 7), // "QEvent*"
QT_MOC_LITERAL(44, 725, 10), // "wheelEvent"
QT_MOC_LITERAL(45, 736, 12), // "QWheelEvent*"
QT_MOC_LITERAL(46, 749, 15), // "keyReleaseEvent"
QT_MOC_LITERAL(47, 765, 10), // "QKeyEvent*"
QT_MOC_LITERAL(48, 776, 10), // "fileExists"
QT_MOC_LITERAL(49, 787, 8) // "fileName"

    },
    "MainWindow\0loadConfig\0\0configFilePath\0"
    "populateTreeWidget\0items\0"
    "on_treeWidget_itemClicked\0QTreeWidgetItem*\0"
    "item\0column\0on_previousPage_clicked\0"
    "on_nextPage_clicked\0on_lastPage_clicked\0"
    "on_firstPage_clicked\0on_ZoomOut_clicked\0"
    "on_ZoomIn_clicked\0on_currPageDisplay_editingFinished\0"
    "on_actionClose_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionAssembler_triggered\0"
    "on_actionSimplePage_triggered\0"
    "on_actionDoublePage_triggered\0"
    "on_actionRedimVertical_triggered\0"
    "on_actionRedimHorizontal_triggered\0"
    "on_actionBookmark_triggered\0"
    "on_actionGotobookmark_triggered\0"
    "setImage\0image\0refreshScreen\0"
    "numPageChanged\0msgBox\0msg\0resizeEvent\0"
    "QResizeEvent*\0event\0setDefaultZoom\0"
    "assemblerSlot\0QList<int>\0l\0s\0eventFilter\0"
    "watched\0QEvent*\0wheelEvent\0QWheelEvent*\0"
    "keyReleaseEvent\0QKeyEvent*\0fileExists\0"
    "fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x08 /* Private */,
       4,    1,  167,    2, 0x08 /* Private */,
       6,    2,  170,    2, 0x08 /* Private */,
      10,    0,  175,    2, 0x08 /* Private */,
      11,    0,  176,    2, 0x08 /* Private */,
      12,    0,  177,    2, 0x08 /* Private */,
      13,    0,  178,    2, 0x08 /* Private */,
      14,    0,  179,    2, 0x08 /* Private */,
      15,    0,  180,    2, 0x08 /* Private */,
      16,    0,  181,    2, 0x08 /* Private */,
      17,    0,  182,    2, 0x08 /* Private */,
      18,    0,  183,    2, 0x08 /* Private */,
      19,    0,  184,    2, 0x08 /* Private */,
      20,    0,  185,    2, 0x08 /* Private */,
      21,    0,  186,    2, 0x08 /* Private */,
      22,    0,  187,    2, 0x08 /* Private */,
      23,    0,  188,    2, 0x08 /* Private */,
      24,    0,  189,    2, 0x08 /* Private */,
      25,    0,  190,    2, 0x08 /* Private */,
      26,    0,  191,    2, 0x08 /* Private */,
      27,    1,  192,    2, 0x08 /* Private */,
      29,    1,  195,    2, 0x08 /* Private */,
      31,    1,  198,    2, 0x08 /* Private */,
      33,    1,  201,    2, 0x08 /* Private */,
      36,    0,  204,    2, 0x08 /* Private */,
      37,    2,  205,    2, 0x08 /* Private */,
      41,    2,  210,    2, 0x08 /* Private */,
      44,    1,  215,    2, 0x08 /* Private */,
      46,    1,  218,    2, 0x08 /* Private */,
      48,    1,  221,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QJsonArray,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   28,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38, QMetaType::QString,   39,   40,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 43,   42,   35,
    QMetaType::Void, 0x80000000 | 45,   35,
    QMetaType::Void, 0x80000000 | 47,   35,
    QMetaType::Bool, QMetaType::QString,   49,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->populateTreeWidget((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 2: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_previousPage_clicked(); break;
        case 4: _t->on_nextPage_clicked(); break;
        case 5: _t->on_lastPage_clicked(); break;
        case 6: _t->on_firstPage_clicked(); break;
        case 7: _t->on_ZoomOut_clicked(); break;
        case 8: _t->on_ZoomIn_clicked(); break;
        case 9: _t->on_currPageDisplay_editingFinished(); break;
        case 10: _t->on_actionClose_triggered(); break;
        case 11: _t->on_actionAbout_triggered(); break;
        case 12: _t->on_actionOpen_triggered(); break;
        case 13: _t->on_actionAssembler_triggered(); break;
        case 14: _t->on_actionSimplePage_triggered(); break;
        case 15: _t->on_actionDoublePage_triggered(); break;
        case 16: _t->on_actionRedimVertical_triggered(); break;
        case 17: _t->on_actionRedimHorizontal_triggered(); break;
        case 18: _t->on_actionBookmark_triggered(); break;
        case 19: _t->on_actionGotobookmark_triggered(); break;
        case 20: _t->setImage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 21: _t->refreshScreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->msgBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 24: _t->setDefaultZoom(); break;
        case 25: _t->assemblerSlot((*reinterpret_cast< QList<int>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 28: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 29: { bool _r = _t->fileExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
