/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *openFileLocation;
    QAction *SphereChangeState;
    QAction *CreateCheckBox;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *searchLayout;
    QLineEdit *seachEdit;
    QPushButton *searchButton;
    QPushButton *antiButton;
    QPushButton *cancelButton;
    QPushButton *hideButton;
    QPushButton *showButton;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addElement;
    QToolButton *toolButton;
    QPushButton *addLaws;
    QPushButton *redactButton;
    QPushButton *sortElement;
    QToolButton *exportToolButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QWidget *ListWidgetPlace;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QToolButton *toolButton_2;
    QFrame *frame;
    QListWidget *listWidget;
    QWidget *tab_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit_2;
    QToolButton *toolButton_3;
    QFrame *frame_3;
    QListWidget *listWidget_2;
    QMenuBar *menubar;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1102, 673);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_7 = new QAction(MainWindow);
        action_7->setObjectName("action_7");
        action_8 = new QAction(MainWindow);
        action_8->setObjectName("action_8");
        action_9 = new QAction(MainWindow);
        action_9->setObjectName("action_9");
        openFileLocation = new QAction(MainWindow);
        openFileLocation->setObjectName("openFileLocation");
        SphereChangeState = new QAction(MainWindow);
        SphereChangeState->setObjectName("SphereChangeState");
        CreateCheckBox = new QAction(MainWindow);
        CreateCheckBox->setObjectName("CreateCheckBox");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        seachEdit = new QLineEdit(centralwidget);
        seachEdit->setObjectName("seachEdit");

        searchLayout->addWidget(seachEdit);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        searchButton->setIcon(icon);

        searchLayout->addWidget(searchButton);

        antiButton = new QPushButton(centralwidget);
        antiButton->setObjectName("antiButton");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ViewRestore));
        antiButton->setIcon(icon1);

        searchLayout->addWidget(antiButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName("cancelButton");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        cancelButton->setIcon(icon2);

        searchLayout->addWidget(cancelButton);


        gridLayout->addLayout(searchLayout, 0, 0, 1, 1);

        hideButton = new QPushButton(centralwidget);
        hideButton->setObjectName("hideButton");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
        hideButton->setIcon(icon3);

        gridLayout->addWidget(hideButton, 2, 2, 1, 1);

        showButton = new QPushButton(centralwidget);
        showButton->setObjectName("showButton");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::GoPrevious));
        showButton->setIcon(icon4);

        gridLayout->addWidget(showButton, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(-1, -1, 5, -1);
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setBaseSize(QSize(0, 0));
        treeWidget->setAutoFillBackground(false);
        treeWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

        verticalLayout->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        addElement = new QPushButton(centralwidget);
        addElement->setObjectName("addElement");

        horizontalLayout->addWidget(addElement);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(toolButton);

        addLaws = new QPushButton(centralwidget);
        addLaws->setObjectName("addLaws");

        horizontalLayout->addWidget(addLaws);

        redactButton = new QPushButton(centralwidget);
        redactButton->setObjectName("redactButton");

        horizontalLayout->addWidget(redactButton);

        sortElement = new QPushButton(centralwidget);
        sortElement->setObjectName("sortElement");

        horizontalLayout->addWidget(sortElement);

        exportToolButton = new QToolButton(centralwidget);
        exportToolButton->setObjectName("exportToolButton");

        horizontalLayout->addWidget(exportToolButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(311, 0));
        tab = new QWidget();
        tab->setObjectName("tab");
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        ListWidgetPlace = new QWidget(tab);
        ListWidgetPlace->setObjectName("ListWidgetPlace");
        verticalLayout_2 = new QVBoxLayout(ListWidgetPlace);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(5, 5, 5, -1);
        frame_2 = new QFrame(ListWidgetPlace);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(frame_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        plainTextEdit = new QPlainTextEdit(ListWidgetPlace);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(20);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMaximumSize(QSize(16777215, 35));
        plainTextEdit->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        plainTextEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(plainTextEdit);

        toolButton_2 = new QToolButton(ListWidgetPlace);
        toolButton_2->setObjectName("toolButton_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(toolButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        frame = new QFrame(ListWidgetPlace);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(frame);

        listWidget = new QListWidget(ListWidgetPlace);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);


        verticalLayout_3->addWidget(ListWidgetPlace);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        sizePolicy.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy);
        widget = new QWidget(tab_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 11, 354, 520));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(5, 5, 5, -1);
        frame_4 = new QFrame(widget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::HLine);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_4->addWidget(frame_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        plainTextEdit_2 = new QPlainTextEdit(widget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(35);
        sizePolicy4.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy4);
        plainTextEdit_2->setMaximumSize(QSize(16777215, 35));
        plainTextEdit_2->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        plainTextEdit_2->setReadOnly(true);

        horizontalLayout_3->addWidget(plainTextEdit_2);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName("toolButton_3");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(35);
        sizePolicy5.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy5);

        horizontalLayout_3->addWidget(toolButton_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        frame_3 = new QFrame(widget);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::HLine);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_4->addWidget(frame_3);

        listWidget_2 = new QListWidget(widget);
        listWidget_2->setObjectName("listWidget_2");
        sizePolicy.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(listWidget_2);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 3, 3, 1);

        gridLayout->setColumnStretch(0, 2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1102, 26));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        menu_7 = new QMenu(menu_5);
        menu_7->setObjectName("menu_7");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu_3->addSeparator();
        menu_3->addAction(openFileLocation);
        menu_3->addAction(SphereChangeState);
        menu_5->addAction(action_4);
        menu_5->addAction(CreateCheckBox);
        menu_5->addAction(menu_7->menuAction());
        menu_5->addAction(action_9);
        menu_7->addAction(action_7);
        menu_7->addAction(action_8);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202\320\273\321\213\320\271", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\274\320\275\321\213\320\271", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213...", nullptr));
        action_7->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
        action_8->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        action_9->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        openFileLocation->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\273\320\276\320\272\320\260\321\206\320\270\321\216 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        SphereChangeState->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\321\217\321\202\320\260\321\202\321\214/\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\321\204\320\265\321\200\321\213", nullptr));
        CreateCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        seachEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 [\321\202\320\265\321\200\320\274\320\270\320\275\321\203]", nullptr));
        searchButton->setText(QString());
        antiButton->setText(QString());
        cancelButton->setText(QString());
        hideButton->setText(QString());
        showButton->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "URL", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        addElement->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213...", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        addLaws->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        redactButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        sortElement->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        exportToolButton->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202...", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\265 \321\201\321\204\320\265\321\200\321\213:", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\201\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\265 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270:", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\204\320\265\321\200\321\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
