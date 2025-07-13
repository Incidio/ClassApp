/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "buttonPressed",
    "",
    "on_addElement_clicked",
    "addFilesToRoot",
    "QTreeWidgetItem*",
    "root",
    "urls",
    "on_treeWidget_doubleClicked",
    "on_sortElement_clicked",
    "on_addLaws_clicked",
    "AddRoot",
    "name",
    "AddChild",
    "parent",
    "url",
    "description",
    "styleWidget",
    "DeleteButton",
    "on_deleteElement",
    "on_deleteAllElement",
    "ExportToolButton",
    "on_createFile",
    "countFilesInTree",
    "QTreeWidget*",
    "tree",
    "on_exportToExcel",
    "CreateListWidget",
    "LibraryButton",
    "SelectAll",
    "deSelectAll",
    "expandLibrary",
    "highlightChecked",
    "QListWidgetItem*",
    "item",
    "setAllItemsCheckedState",
    "QListWidget*",
    "listWidget",
    "Qt::CheckState",
    "checkState",
    "color",
    "openFromList",
    "QModelIndex",
    "index",
    "subdir",
    "on_listWidget_doubleClicked",
    "CreateCategoryWidget",
    "SelectAllOrgs",
    "deSelectAllOrgs",
    "expandOrgsLibrary",
    "OrgsButton",
    "on_listWidget_2_doubleClicked",
    "on_treeWidget_itemClicked",
    "column",
    "on_CreateDate_triggered",
    "on_HideDate_triggered",
    "on_CreateDescription_triggered",
    "on_HideDescription_triggered",
    "on_CreateTarget_triggered",
    "on_HideTarget_triggered",
    "on_CreateAuthor_triggered",
    "on_HideAuthor_triggered",
    "extractSignature",
    "pdfText",
    "on_CreateDocumentType_triggered",
    "on_HideDocumentType_triggered",
    "on_SphereChangeState_triggered",
    "on_openFileLocation_triggered",
    "on_hideButton_clicked",
    "on_showButton_clicked",
    "on_searchButton_pressed",
    "on_antiButton_pressed",
    "on_cancelButton_pressed",
    "on_redactButton_clicked",
    "on_CreateOrg_triggered",
    "getLastLines",
    "filePath",
    "lineCount",
    "on_HideOrg_triggered"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  338,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  339,    2, 0x08,    2 /* Private */,
       4,    2,  340,    2, 0x08,    3 /* Private */,
       8,    0,  345,    2, 0x08,    6 /* Private */,
       9,    0,  346,    2, 0x08,    7 /* Private */,
      10,    0,  347,    2, 0x08,    8 /* Private */,
      11,    1,  348,    2, 0x08,    9 /* Private */,
      13,    4,  351,    2, 0x08,   11 /* Private */,
      17,    0,  360,    2, 0x08,   16 /* Private */,
      18,    0,  361,    2, 0x08,   17 /* Private */,
      19,    0,  362,    2, 0x08,   18 /* Private */,
      20,    0,  363,    2, 0x08,   19 /* Private */,
      21,    0,  364,    2, 0x08,   20 /* Private */,
      22,    0,  365,    2, 0x08,   21 /* Private */,
      23,    1,  366,    2, 0x08,   22 /* Private */,
      26,    0,  369,    2, 0x08,   24 /* Private */,
      27,    0,  370,    2, 0x08,   25 /* Private */,
      28,    0,  371,    2, 0x08,   26 /* Private */,
      29,    0,  372,    2, 0x08,   27 /* Private */,
      30,    0,  373,    2, 0x08,   28 /* Private */,
      31,    0,  374,    2, 0x08,   29 /* Private */,
      32,    1,  375,    2, 0x08,   30 /* Private */,
      35,    3,  378,    2, 0x08,   32 /* Private */,
      41,    2,  385,    2, 0x08,   36 /* Private */,
      45,    1,  390,    2, 0x08,   39 /* Private */,
      46,    0,  393,    2, 0x08,   41 /* Private */,
      47,    0,  394,    2, 0x08,   42 /* Private */,
      48,    0,  395,    2, 0x08,   43 /* Private */,
      49,    0,  396,    2, 0x08,   44 /* Private */,
      50,    0,  397,    2, 0x08,   45 /* Private */,
      51,    1,  398,    2, 0x08,   46 /* Private */,
      52,    2,  401,    2, 0x08,   48 /* Private */,
      54,    0,  406,    2, 0x08,   51 /* Private */,
      55,    0,  407,    2, 0x08,   52 /* Private */,
      56,    0,  408,    2, 0x08,   53 /* Private */,
      57,    0,  409,    2, 0x08,   54 /* Private */,
      58,    0,  410,    2, 0x08,   55 /* Private */,
      59,    0,  411,    2, 0x08,   56 /* Private */,
      60,    0,  412,    2, 0x08,   57 /* Private */,
      61,    0,  413,    2, 0x08,   58 /* Private */,
      62,    1,  414,    2, 0x08,   59 /* Private */,
      64,    0,  417,    2, 0x08,   61 /* Private */,
      65,    0,  418,    2, 0x08,   62 /* Private */,
      66,    0,  419,    2, 0x08,   63 /* Private */,
      67,    0,  420,    2, 0x08,   64 /* Private */,
      68,    0,  421,    2, 0x08,   65 /* Private */,
      69,    0,  422,    2, 0x08,   66 /* Private */,
      70,    0,  423,    2, 0x08,   67 /* Private */,
      71,    0,  424,    2, 0x08,   68 /* Private */,
      72,    0,  425,    2, 0x08,   69 /* Private */,
      73,    0,  426,    2, 0x08,   70 /* Private */,
      74,    0,  427,    2, 0x08,   71 /* Private */,
      75,    2,  428,    2, 0x08,   72 /* Private */,
      78,    0,  433,    2, 0x08,   75 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QStringList,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   12,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void, 0x80000000 | 36, 0x80000000 | 38, QMetaType::QColor,   37,   39,   40,
    QMetaType::Void, 0x80000000 | 42, QMetaType::QString,   43,   44,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,   34,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   63,
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
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   76,   77,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'buttonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addElement_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFilesToRoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'on_treeWidget_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sortElement_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addLaws_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddRoot'
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'AddChild'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'styleWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeleteButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteElement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteAllElement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ExportToolButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_createFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'countFilesInTree'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidget *, std::false_type>,
        // method 'on_exportToExcel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CreateListWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LibraryButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SelectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deSelectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'expandLibrary'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highlightChecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'setAllItemsCheckedState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::CheckState, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'openFromList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_listWidget_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'CreateCategoryWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SelectAllOrgs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deSelectAllOrgs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'expandOrgsLibrary'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OrgsButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listWidget_2_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_treeWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_CreateDate_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HideDate_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CreateDescription_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HideDescription_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CreateTarget_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HideTarget_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CreateAuthor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HideAuthor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'extractSignature'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_CreateDocumentType_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HideDocumentType_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SphereChangeState_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openFileLocation_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_hideButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_antiButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelButton_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_redactButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CreateOrg_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getLastLines'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_HideOrg_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->buttonPressed(); break;
        case 1: _t->on_addElement_clicked(); break;
        case 2: _t->addFilesToRoot((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 3: _t->on_treeWidget_doubleClicked(); break;
        case 4: _t->on_sortElement_clicked(); break;
        case 5: _t->on_addLaws_clicked(); break;
        case 6: { QTreeWidgetItem* _r = _t->AddRoot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTreeWidgetItem**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->AddChild((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 8: _t->styleWidget(); break;
        case 9: _t->DeleteButton(); break;
        case 10: _t->on_deleteElement(); break;
        case 11: _t->on_deleteAllElement(); break;
        case 12: _t->ExportToolButton(); break;
        case 13: _t->on_createFile(); break;
        case 14: { int _r = _t->countFilesInTree((*reinterpret_cast< std::add_pointer_t<QTreeWidget*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->on_exportToExcel(); break;
        case 16: _t->CreateListWidget(); break;
        case 17: _t->LibraryButton(); break;
        case 18: _t->SelectAll(); break;
        case 19: _t->deSelectAll(); break;
        case 20: _t->expandLibrary(); break;
        case 21: _t->highlightChecked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 22: _t->setAllItemsCheckedState((*reinterpret_cast< std::add_pointer_t<QListWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 23: _t->openFromList((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->on_listWidget_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 25: _t->CreateCategoryWidget(); break;
        case 26: _t->SelectAllOrgs(); break;
        case 27: _t->deSelectAllOrgs(); break;
        case 28: _t->expandOrgsLibrary(); break;
        case 29: _t->OrgsButton(); break;
        case 30: _t->on_listWidget_2_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 31: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->on_CreateDate_triggered(); break;
        case 33: _t->on_HideDate_triggered(); break;
        case 34: _t->on_CreateDescription_triggered(); break;
        case 35: _t->on_HideDescription_triggered(); break;
        case 36: _t->on_CreateTarget_triggered(); break;
        case 37: _t->on_HideTarget_triggered(); break;
        case 38: _t->on_CreateAuthor_triggered(); break;
        case 39: _t->on_HideAuthor_triggered(); break;
        case 40: { QString _r = _t->extractSignature((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 41: _t->on_CreateDocumentType_triggered(); break;
        case 42: _t->on_HideDocumentType_triggered(); break;
        case 43: _t->on_SphereChangeState_triggered(); break;
        case 44: _t->on_openFileLocation_triggered(); break;
        case 45: _t->on_hideButton_clicked(); break;
        case 46: _t->on_showButton_clicked(); break;
        case 47: _t->on_searchButton_pressed(); break;
        case 48: _t->on_antiButton_pressed(); break;
        case 49: _t->on_cancelButton_pressed(); break;
        case 50: _t->on_redactButton_clicked(); break;
        case 51: _t->on_CreateOrg_triggered(); break;
        case 52: { QString _r = _t->getLastLines((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 53: _t->on_HideOrg_triggered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTreeWidget* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QListWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MainWindow::*)();
            if (_q_method_type _q_method = &MainWindow::buttonPressed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::buttonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
