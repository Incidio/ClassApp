#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include <QTreeWidget>
#include <QHeaderView>
#include <QTextEdit>
#include <QListWidget>
#include <QThread>
#include <QDesktopServices>
#include <QUrl>
#include <QMenu>
#include <QToolButton>
#include <QFrame>
#include <QtCharts>
#include <QEventLoop>

#include <QtConcurrent>

#include <QPainter>
#include <QColor>

#include "service.h"
#include "progressdialog.h"
#include "plotwindow.h"
#include "xlsxwriter.h"

#include "createchart.h"
#include "redactingitem.h"

#include "3rdparty/duckx/include/duckx.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<QTreeWidgetItem*> ParentsItems;

signals:
    void buttonPressed();

private slots:
    //Нажатие кнопок
    void on_addElement_clicked();
    void addFilesToRoot(QTreeWidgetItem *root, const QStringList &urls);
    void on_treeWidget_doubleClicked();
    void on_sortElement_clicked();

    void on_addLaws_clicked();
    //
    QTreeWidgetItem* AddRoot(const QString& name); //для предметов в большой коробке
    //
    void AddChild(QTreeWidgetItem *parent,
                            const QString &name,
                            const QString &url,
                            const QString &description);
    void styleWidget();

    // для tool button удаления из списка
    void DeleteButton();
    void on_deleteElement();
    void on_deleteAllElement();

    void ExportToolButton();
    void on_createFile();
    int countFilesInTree(QTreeWidget* tree);
    void on_exportToExcel();

    // для tool button работы сфер
    void CreateListWidget();
    void LibraryButton();
    void SelectAll();
    void deSelectAll();
    void expandLibrary();
    void highlightChecked(QListWidgetItem *item);
    void setAllItemsCheckedState(QListWidget *listWidget, Qt::CheckState checkState, const QColor &color);

    void openFromList(const QModelIndex &index, const QString &subdir);
    void on_listWidget_doubleClicked(const QModelIndex &index);

    // Для работы организации
    void CreateCategoryWidget();
    void SelectAllOrgs();
    void deSelectAllOrgs();
    void expandOrgsLibrary();
    void OrgsButton();
    void on_listWidget_2_doubleClicked(const QModelIndex &index);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_CreateDate_triggered();
    void on_HideDate_triggered();

    void on_CreateDescription_triggered();
    void on_HideDescription_triggered();

    void on_CreateTarget_triggered();
    void on_HideTarget_triggered();

    void on_CreateAuthor_triggered();
    void on_HideAuthor_triggered();

    QString extractSignature(const QString &pdfText);

    void on_CreateDocumentType_triggered();
    void on_HideDocumentType_triggered();

    void on_SphereChangeState_triggered();
    void on_openFileLocation_triggered();

    void on_hideButton_clicked();
    void on_showButton_clicked();


    void on_searchButton_pressed();
    void on_antiButton_pressed();
    void on_cancelButton_pressed();

    void on_redactButton_clicked();

    void on_CreateOrg_triggered();
    QString getLastLines(const QString& filePath, int lineCount);

    void on_HideOrg_triggered();

private:
    Ui::MainWindow *ui;

    service service1;

};


#endif // MAINWINDOW_H
