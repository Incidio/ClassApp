#pragma once

#ifndef REDACTINGITEM_H
#define REDACTINGITEM_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMap>
#include <QRegularExpression>

namespace Ui {
class RedactingItem;
}

class RedactingItem : public QDialog
{
    Q_OBJECT

public:
    explicit RedactingItem(QWidget *parent = nullptr);
    ~RedactingItem();

    void setItems(QTreeWidget *tree, QTreeWidgetItem *currentItem);
    void fillAction();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RedactingItem *ui;
    QTreeWidgetItem *AcurrentItem;
    QTreeWidget *AtreeWidget;
    QMap<int, QWidget*> inputFields;  // Stores inputs for each column

};

#endif // REDACTINGITEM_H
