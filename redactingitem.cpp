#include "redactingitem.h"
#include "ui_redactingitem.h"

RedactingItem::RedactingItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RedactingItem)
{
    ui->setupUi(this);
    setWindowTitle("Редактирование данных");
    ui->textEdit->setAlignment(Qt::AlignCenter);

}

void RedactingItem::setItems(QTreeWidget *tree, QTreeWidgetItem *currentItem)
{
    this->AtreeWidget = tree;
    this->AcurrentItem = currentItem;

    fillAction();

}
RedactingItem::~RedactingItem()
{
    qDeleteAll(inputFields);
    inputFields.clear();
    delete ui;
}
void RedactingItem::fillAction()
{
    if (!AcurrentItem || !AtreeWidget) return;

    qDeleteAll(inputFields);
    inputFields.clear();

    QTreeWidget *treeWidget = AtreeWidget;
    QStringList columnNames;
    for (int i = 0; i < treeWidget->columnCount(); ++i) {
        columnNames.append(treeWidget->headerItem()->text(i));
    }

    QGridLayout *gridLayout = new QGridLayout();

    for (int i = 0; i < AcurrentItem->columnCount(); ++i) {
        QString columnText = AcurrentItem->text(i);
        QString columnName = columnNames.value(i, "Column " + QString::number(i));
        QWidget *inputWidget = nullptr;
        QLabel *label = new QLabel(columnName + ":", this);
        if (i==1) label -> setText("Сфера:");
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        if (i == 0) { // Название, только читается
            QLineEdit *lineEdit = new QLineEdit(columnText, this);
            lineEdit->setReadOnly(true);
            inputFields[i] = lineEdit;
            inputWidget = lineEdit;
        }
        else if (i == 1) { // В таблице сфера законов
            QComboBox *comboBox = new QComboBox(this);

            QTreeWidgetItem *parentItem = AcurrentItem->parent();
            QString categoryName = parentItem ? parentItem->text(0) : "";
            for (int j = 0; j < AtreeWidget->topLevelItemCount(); ++j) {
                QTreeWidgetItem *topItem = AtreeWidget->topLevelItem(j);
                comboBox->addItem(topItem->text(0));
            }

            int index = comboBox->findText(categoryName, Qt::MatchExactly | Qt::MatchCaseSensitive);
            if (index >= 0) {
                comboBox->setCurrentIndex(index);
            } else {
                comboBox->setCurrentIndex(0);
            }

            inputFields[i] = comboBox;
            inputWidget = comboBox;
        }
        else { // редактируемая
            QLineEdit *lineEdit = new QLineEdit(columnText, this);
            inputFields[i] = lineEdit;
            inputWidget = lineEdit;
        }

        // Add to grid layout with 1:4 ratio
        gridLayout->addWidget(label, i, 0, 1, 1);  // Label in column 0
        gridLayout->addWidget(inputWidget, i, 1, 1, 4);  // Input field in column 1

        gridLayout->setColumnStretch(0, 1);  // Labels take 1 part
        gridLayout->setColumnStretch(1, 4);  // Inputs take 4 parts
    }

    // Apply the layout to a container widget
    QWidget *formContainer = new QWidget(this);
    formContainer->setLayout(gridLayout);

    ui->layout->addWidget(formContainer);

}

void RedactingItem::on_pushButton_clicked()
{
    if (!AcurrentItem)
    {
        return;
    }
    QString categoryName;

    for (int i = 0; i < AcurrentItem->columnCount(); i++)
    {
        if (i == 0) {
            continue;
        }
        if (i == 1) { // данные для сферы
            QComboBox *comboBox = qobject_cast<QComboBox *>(inputFields[i]);
            if (comboBox) {
                categoryName = comboBox->currentText();  // сфера
            }
        }
        else { // другие колонны
            QLineEdit *lineEdit = qobject_cast<QLineEdit *>(inputFields[i]);
            if (lineEdit) {
                AcurrentItem->setText(i, lineEdit->text()); // обновленный
            }
        }
    }
    for (int i = 0; i < AtreeWidget->topLevelItemCount(); i++)
    {

        QTreeWidgetItem *parentItem = AtreeWidget->topLevelItem(i);

        if (parentItem->text(0) == categoryName)
        {
            QTreeWidgetItem *newChild = new QTreeWidgetItem(parentItem);

            for (int j = 0; j < AcurrentItem->columnCount(); ++j) {
                newChild->setText(j, AcurrentItem->text(j));
            }

            parentItem->addChild(newChild);
            QString text = parentItem->text(0);
            //qDebug() << text;
            QRegularExpression regex("(\\d+)$");

            QRegularExpressionMatch match = regex.match(text);

            if (match.hasMatch()) {
                QString numberStr = match.captured(0);

                int number = numberStr.toInt();
                number += 1;

                text.replace(match.capturedStart(0), match.capturedLength(0), QString::number(number));
            }
            parentItem->setText(0, text);
        }
        if (parentItem == AcurrentItem->parent()) {
            parentItem->removeChild(AcurrentItem);

            QString text = parentItem->text(0);
            //qDebug() << text;
            QRegularExpression regex("(\\d+)$");

            QRegularExpressionMatch match = regex.match(text);

            if (match.hasMatch()) {
                QString numberStr = match.captured(0);

                int number = numberStr.toInt();
                number -= 1;

                text.replace(match.capturedStart(0), match.capturedLength(0), QString::number(number));
            }
            parentItem->setText(0, text);
        }
    }
    this->close();

}

