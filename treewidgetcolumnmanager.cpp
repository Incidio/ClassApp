#include "treewidgetcolumnmanager.h"
#include "ui_treewidgetcolumnmanager.h"


TreeWidgetColumnManager::TreeWidgetColumnManager(QTreeWidget* treeWidget, service* service, QWidget* parent)
    : QDialog(parent), m_treeWidget(treeWidget), m_service(service)
    , ui(new Ui::TreeWidgetColumnManager)
{
    ui->setupUi(this);

    setWindowTitle("Управление столбцами");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setupUI();
    resize(400, 300);
}

TreeWidgetColumnManager::~TreeWidgetColumnManager()
{
    delete ui;
}

void TreeWidgetColumnManager::setupUI()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Группа для настроек столбцов
    QGroupBox* groupBox = new QGroupBox("Выберите столбцы для обработки", this);
    QVBoxLayout* groupLayout = new QVBoxLayout(groupBox);

    // Создаем чекбоксы для каждого типа столбца
    QStringList columns = {
        "Дата создания",
        "Описание",
        "Кому",
        "Подписал",
        "Тип документа"
    };

    for (const QString& column : columns) {
        QCheckBox* checkbox = new QCheckBox(column, this);
        m_checkboxes[column] = checkbox;
        groupLayout->addWidget(checkbox);
    }

    groupBox->setLayout(groupLayout);
    mainLayout->addWidget(groupBox);

    // Кнопка запуска обработки
    QPushButton* processButton = new QPushButton("Запустить обработку", this);
    processButton->setMinimumHeight(40);
    connect(processButton, &QPushButton::clicked, this, &TreeWidgetColumnManager::processColumns);
    mainLayout->addWidget(processButton);

    setLayout(mainLayout);
}

void TreeWidgetColumnManager::processColumns()
{
    // Собираем выбранные пользователем действия
    for (auto it = m_checkboxes.constBegin(); it != m_checkboxes.constEnd(); ++it) {
        manageColumn(it.key(), it.value()->isChecked());
    }

}

void TreeWidgetColumnManager::manageColumn(const QString& columnName, bool create)
{
    if (columnName == "Дата создания") {
        int columnIndex = findColumnIndex(columnName);

        if (create) {
            if (columnIndex == -1) {
                columnIndex = createColumn(columnName);
            }
            m_treeWidget->setColumnHidden(columnIndex, false);
            updateCreationDate(columnIndex);
        } else {
            if (columnIndex != -1) {
                m_treeWidget->setColumnHidden(columnIndex, true);
            }
        }
    }
    else if (columnName == "Описание") {
        int columnIndex = findColumnIndex(columnName);

        if (columnIndex != -1) {
            m_treeWidget->setColumnHidden(columnIndex, !create);
        }
    }
    else if (columnName == "Кому") {
        int columnIndex = findColumnIndex(columnName);

        if (create) {
            if (columnIndex == -1) {
                columnIndex = createColumn(columnName);
            }
            m_treeWidget->setColumnHidden(columnIndex, false);

            auto targetProcessor = [columnIndex](QTreeWidgetItem* item, QPdfDocument& document) {
                QString selectedText = document.getAllText(0).text();
                QString target = "";

                // Алгоритм извлечения получателя
                for (int i = selectedText.length() - 1; i > 2; i--) {
                    if (selectedText[i] == '.' && selectedText[i - 2] == '.') {
                        int leftIndex = -1, rightIndex = selectedText.length() + 1;
                        for (int j = i; j > 2; j--) {
                            if (selectedText[j] == '\n') {
                                leftIndex = j;
                                break;
                            }
                        }
                        for (int j = i + 2; j < selectedText.length(); j++) {
                            if (selectedText[j] == '\n') {
                                rightIndex = j;
                                break;
                            }
                        }
                        for (int j = leftIndex + 1; j < rightIndex - 1; j++) {
                            target += selectedText[j];
                        }

                        int spaceCount = 0;
                        for (const QChar& ch : target) {
                            if (ch.isSpace()) {
                                spaceCount++;
                                if (spaceCount >= 3) {
                                    target = "";
                                }
                            }
                        }
                        item->setText(columnIndex, target);
                        break;
                    }
                }
            };

            processPdfItems(targetProcessor, "Обработка файлов...");
        } else {
            if (columnIndex != -1) {
                m_treeWidget->setColumnHidden(columnIndex, true);
            }
        }
    }
    else if (columnName == "Подписал") {
        int columnIndex = findColumnIndex(columnName);

        if (create) {
            if (columnIndex == -1) {
                columnIndex = createColumn(columnName);
            }
            m_treeWidget->setColumnHidden(columnIndex, false);

            auto authorProcessor = [this, columnIndex](QTreeWidgetItem* item, QPdfDocument& document) {
                // Получаем текст с последних двух страниц
                QString selectedText;
                if (document.pageCount() >= 2) {
                    selectedText = document.getAllText(document.pageCount() - 2).text();
                }
                selectedText += document.getAllText(document.pageCount() - 1).text();

                QString signature = extractSignature(selectedText);
                item->setText(columnIndex, signature);
            };

            processPdfItems(authorProcessor, "Обработка подписей...");
        } else {
            if (columnIndex != -1) {
                m_treeWidget->setColumnHidden(columnIndex, true);
            }
        }
    }
    else if (columnName == "Тип документа") {
        int columnIndex = findColumnIndex(columnName);

        if (create) {
            if (columnIndex == -1) {
                columnIndex = createColumn(columnName);
            }
            m_treeWidget->setColumnHidden(columnIndex, false);

            auto docTypeProcessor = [this, columnIndex](QTreeWidgetItem* item, QPdfDocument& document) {
                if (document.pageCount() > 0) {
                    QString firstPageText = document.getAllText(0).text().toLower();
                    QString docType = determineDocumentType(firstPageText);
                    item->setText(columnIndex, docType);
                }
            };

            processPdfItems(docTypeProcessor, "Определение типа документа...");
        } else {
            if (columnIndex != -1) {
                m_treeWidget->setColumnHidden(columnIndex, true);
            }
        }
    }
}

int TreeWidgetColumnManager::findColumnIndex(const QString& columnName)
{
    for (int i = 0; i < m_treeWidget->columnCount(); ++i) {
        if (m_treeWidget->headerItem()->text(i) == columnName) {
            return i;
        }
    }
    return -1;
}

int TreeWidgetColumnManager::createColumn(const QString& columnName)
{
    int newColumnIndex = m_treeWidget->columnCount();
    m_treeWidget->setColumnCount(newColumnIndex + 1);
    m_treeWidget->headerItem()->setText(newColumnIndex, columnName);
    return newColumnIndex;
}

void TreeWidgetColumnManager::updateCreationDate(int columnIndex)
{
    QTreeWidgetItemIterator it(m_treeWidget);
    while (*it) {
        if (!(*it)->text(1).isEmpty()) {
            QFileInfo fileInfo((*it)->text(1));
            (*it)->setText(columnIndex, fileInfo.lastModified().toString("yyyy-MM-dd"));
        }
        ++it;
    }
}

QString TreeWidgetColumnManager::extractSignature(const QString& pdfText)
{
    QString substring = "\r\n[SIGNERSTAMP1]";
    int position = pdfText.indexOf(substring);

    if (position == -1 && !pdfText.isEmpty()) {
        substring = "эл.подпись";
        position = pdfText.indexOf(substring);
    }

    if (position == -1 && !pdfText.isEmpty()) {
        position = pdfText.length();
    }

    QString signature;
    for (int i = position - 1; i > 0; i--) {
        if (pdfText[i] == '[' || pdfText[i] == ']' || pdfText[i] == '\n') {
            signature.clear();
        } else {
            if (pdfText[i] == '.' && pdfText[i - 2] == '.') {
                signature += pdfText[i];
                signature += pdfText[i - 1];
                signature += pdfText[i - 2];
                signature += pdfText[i - 3];
                break;
            } else if (!pdfText[i].isDigit()) {
                signature += pdfText[i];
            }
        }
    }

    if (signature.length() == 4) {
        signature += ' ';
        for (int i = position - 6; i > 0; i--) {
            if (pdfText[i] != ' ') {
                signature += pdfText[i];
            } else {
                break;
            }
        }
    }

    std::reverse(signature.begin(), signature.end());
    return signature;
}

QString TreeWidgetColumnManager::determineDocumentType(const QString& firstPageText)
{
    for (auto it = m_documentTypeKeywords.constBegin(); it != m_documentTypeKeywords.constEnd(); ++it) {
        if (firstPageText.contains(it.key())) {
            return it.value();
        }
    }
    return "Неизвестный тип";
}

void TreeWidgetColumnManager::processPdfItems(
    std::function<void(QTreeWidgetItem*, QPdfDocument&)> processor,
    const QString& progressTitle)
{
    // Подсчет элементов для обработки
    int totalItems = 0;
    QTreeWidgetItemIterator countIt(m_treeWidget);
    while (*countIt) {
        if (!(*countIt)->text(1).isEmpty()) totalItems++;
        ++countIt;
    }

    if (totalItems == 0) {
        QMessageBox::information(this, "Информация", "Нет элементов для обработки");
        return;
    }

    // Настройка диалога прогресса
    QProgressDialog progressDialog(progressTitle, "Отмена", 0, totalItems, this);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(0);
    progressDialog.show();

    // Обработка элементов
    QTreeWidgetItemIterator it(m_treeWidget);
    int processedItems = 0;
    bool wasCanceled = false;

    while (*it && !wasCanceled) {
        if (progressDialog.wasCanceled()) {
            wasCanceled = true;
            break;
        }

        if (!(*it)->text(1).isEmpty()) {
            QString filePath = (*it)->text(1);
            int extension = m_service->checkFileExtension(filePath);

            if (extension == 3) { // PDF
                QPdfDocument document;
                if (document.load(filePath) == QPdfDocument::Error::None) {
                    processor(*it, document);
                    document.close();
                }
            }

            processedItems++;
            progressDialog.setValue(processedItems);
            QCoreApplication::processEvents();
        }

        ++it;
    }

    progressDialog.close();

    if (!wasCanceled) {
        m_treeWidget->setSortingEnabled(true);
        //QMessageBox::information(this, "Готово", "Обработка завершена успешно");
    }
}
