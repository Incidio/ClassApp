#pragma once

#ifndef TREEWIDGETCOLUMNMANAGER_H
#define TREEWIDGETCOLUMNMANAGER_H

#include <QDialog>
#include <QTreeWidget>
#include <QHeaderView>
#include <QPdfDocument>
#include <QProgressDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDateTime>
#include <QMap>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>

#include "service.h"

namespace Ui {
class TreeWidgetColumnManager;
}

class TreeWidgetColumnManager : public QDialog
{
    Q_OBJECT

private slots:
    void processColumns();

public:
    explicit TreeWidgetColumnManager(QTreeWidget* treeWidget, service* service1, QWidget* parent = nullptr);
    ~TreeWidgetColumnManager();
private:
    void setupUI();
    void manageColumn(const QString& columnName, bool create);
    int findColumnIndex(const QString& columnName);
    int createColumn(const QString& columnName);
    void updateCreationDate(int columnIndex);
    QString extractSignature(const QString& pdfText);
    QString determineDocumentType(const QString& firstPageText);
    void processPdfItems(std::function<void(QTreeWidgetItem*, QPdfDocument&)> processor,
                         const QString& progressTitle);

    // UI Components
    Ui::TreeWidgetColumnManager *ui;
    QTreeWidget* m_treeWidget;
    service* m_service;
    QMap<QString, QCheckBox*> m_checkboxes;

    // Configuration
    QMap<QString, QString> m_documentTypeKeywords = {
        {"представление", "Представление"},
        {"приказ", "Приказ"}
    };

};

#endif // TREEWIDGETCOLUMNMANAGER_H
