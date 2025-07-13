#include "mainwindow.h"
#include "./ui_mainwindow.h"

//service service1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    styleWidget();

    CreateListWidget();
    LibraryButton();

    CreateCategoryWidget();
    OrgsButton();

    DeleteButton();
    ExportToolButton();

}
MainWindow::~MainWindow()
{
    delete ui;

}

//--------------------------------------------------------------
// Функции для списка "Сферы"
//--------------------------------------------------------------

void MainWindow::CreateListWidget()
{
    QString path = qApp->applicationDirPath() + "/Сферы/";
    QDir directory(path);

    QStringList textFiles = directory.entryList(QStringList() << "*.txt" << "*.pdf" << "*.docx",QDir::Files);

    for (const QString &filename : textFiles) {
        service1.lawBook.append(path + filename);
    }

    QStringList strList;
    for (int i = 0; i < service1.lawBook.size(); ++i) {
        QStringList pieces = service1.lawBook[i].split("/");
        QString lawBookItem = pieces.last();
        strList.append(QString::number(i + 1) + ": " + lawBookItem);
    }

    ui->listWidget->addItems(strList);
    //ui->listWidget->sortItems();

    QListWidgetItem* item = 0;
    // Для всех элементов добавляю галочку и окрашиваю
    for(int i = 0; i < ui->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setBackground(QColor("#ffffb2"));
        item->setCheckState(Qt::Checked);
    }
    connect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);
    //QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));
}

void MainWindow::LibraryButton()
{
    QMenu* libraryMenu = new QMenu(this);

    QAction *selectAllAction = new QAction("Выбрать все", this);
    QAction *deselectAllAction = new QAction("Освободить все", this);
    QAction *addLibraryAction = new QAction("Добавить сферы", this);

    libraryMenu->addAction(selectAllAction);
    libraryMenu->addAction(deselectAllAction);
    libraryMenu->addAction(addLibraryAction);

    ui->toolButton_2->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolButton_2->setMenu(libraryMenu);
    ui->toolButton_2->setDefaultAction(deselectAllAction);
    /*
    QObject::connect(SelectAll, SIGNAL(triggered()),
                     this, SLOT(SelectAll()));
    QObject::connect(deSelectAll, SIGNAL(triggered()),
                     this, SLOT(deSelectAll()));
    QObject::connect(AddLibrary, SIGNAL(triggered()),
                     this, SLOT(expandLibrary()));
    */
    connect(selectAllAction, &QAction::triggered, this, &MainWindow::SelectAll);
    connect(deselectAllAction, &QAction::triggered, this, &MainWindow::deSelectAll);
    connect(addLibraryAction, &QAction::triggered, this, &MainWindow::expandLibrary);
}

void MainWindow::highlightChecked(QListWidgetItem *item)
{
    if (item && service1.check == 0) {
        service1.check = 1;
        if (item->checkState() == Qt::Checked) {
            item->setBackground(QColor("#ffffb2"));
        } else {
            item->setBackground(QColor("#ffffff"));
        }
    } else {
        service1.check = 0;
    }
}

void MainWindow::setAllItemsCheckedState(QListWidget *listWidget, Qt::CheckState checkState, const QColor &color)
{
    QSignalBlocker blocker(listWidget);

    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem *item = listWidget->item(i);
        item->setCheckState(checkState);
        item->setBackground(color);
    }
}
void MainWindow::SelectAll()
{
    setAllItemsCheckedState(ui->listWidget, Qt::Checked, QColor("#b2ffff"));
    /*
    disconnect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);

    //service1.lawBook.clear();

    for (int i = 0; i < ui->listWidget->count(); i++){
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
        item->setBackground(QColor("#ffffb2"));
    }
    connect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);
    */
}

void MainWindow::deSelectAll()
{
    setAllItemsCheckedState(ui->listWidget, Qt::Unchecked, QColor("#ffffff"));
    /*
    disconnect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);

    //service1.lawBook.clear();

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
        item->setBackground(QColor("#ffffff"));
    }

    connect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);
    */
}
QString	testAndIncrementFilename(const QString &fileName )
{
    //filename == path/filename.extension
    QFileInfo fInfo( fileName );
    if (!fInfo.exists()) {
        return fileName;
    }

    QString ext = fInfo.suffix();

    QString	path;
    if ( ext.isEmpty() )
        path = fileName;
    else
        path = fileName.left(fileName.lastIndexOf('.'));

    QString	digits;
    auto pos = path.length() - 1;
    while ( pos > 0 && ( path[ pos ] ).isDigit() ){
        digits.push_front( path[ pos ] );
        pos--;
    }
    pos+=1;
    QString	newPath = path.left( pos ); // path/filename

    int	number = 1;
    if ( !digits.isEmpty() ){
        number = digits.toInt() + 1;
    }

    // newPath = newPath + " ";
    newPath = newPath + QString::number(number);
    if ( !ext.isEmpty() ){
        newPath += ".";
        newPath += ext;
    }
    while(QFile::exists(newPath) && number<10){
        newPath = testAndIncrementFilename(newPath);
    }

    return newPath;
}

void MainWindow::expandLibrary()
{
    QString path = qApp->applicationDirPath() + "/Сферы/";

    QStringList urls = QFileDialog::getOpenFileNames(
        this,
        "Выберите файл для обработки",
        path,
        tr("Файлы (*.txt *.doc *.docx)")
        );
    // copy ( from , to);

    if (urls.isEmpty()) {
        return;
    }

    QString destPath = qApp->applicationDirPath() + "/Сферы/";
    QDir().mkpath(destPath); // Создаст папку, если ее нет

    for (const QString &url : urls) {
        QFileInfo fileInfo(url);
        QString destinationPath = destPath + fileInfo.fileName();

        // Проверяем, существует ли файл, и при необходимости инкрементируем имя
        if (QFile::exists(destinationPath)) {
            destinationPath = testAndIncrementFilename(destinationPath);
        }

        if (QFile::copy(url, destinationPath)) {
            service1.lawBook.append(destinationPath);

            // Обновление UI
            QString newItemText = QString::number(ui->listWidget->count() + 1) + ": " + QFileInfo(destinationPath).fileName();
            QListWidgetItem *newItem = new QListWidgetItem(newItemText, ui->listWidget);
            newItem->setFlags(newItem->flags() | Qt::ItemIsUserCheckable);
            newItem->setBackground(QColor("#ffffb2"));
            newItem->setCheckState(Qt::Checked);
        } else {
            QMessageBox::warning(this, "Ошибка копирования",
                                 QString("Не удалось скопировать файл: %1").arg(fileInfo.fileName()));
        }
    }
    return;
}

//--------------------------------------------------------------------
// Функции для списка "Категории"
//--------------------------------------------------------------------

void MainWindow::CreateCategoryWidget()
{
    QString path = qApp->applicationDirPath() + "/Организации/";
    QDir directory(path);
    QStringList textFiles = directory.entryList(QStringList() << "*.txt" << "*.pdf" << "*.docx", QDir::Files);

    service1.orgsBook.clear(); // Clear existing items if needed

    foreach(QString filename, textFiles) {
        service1.orgsBook.append(path + filename);
    }

    ui->listWidget_2->clear();
    QStringList strList;
    for (int i = 0; i < service1.orgsBook.size(); ++i) {
        strList.append(QString::number(i + 1) + ": " + QFileInfo(service1.orgsBook[i]).fileName());
    }
    ui->listWidget_2->addItems(strList);

    for (int i = 0; i < ui->listWidget_2->count(); ++i) {
        QListWidgetItem *item = ui->listWidget_2->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setBackground(QColor("#b2ffff")); // Другой цвет для наглядности
        item->setCheckState(Qt::Checked);
    }

    connect(ui->listWidget_2, &QListWidget::itemChanged, this, &MainWindow::highlightChecked);

}

//void MainWindow::highlightChecked(QListWidgetItem *item)

void MainWindow::OrgsButton()
{
    QMenu* orgsMenu  = new QMenu(this);

    QAction *selectAllOrgsAction = new QAction("Выбрать все", this);
    QAction *deselectAllOrgsAction = new QAction("Освободить все", this);
    QAction *addOrgsAction = new QAction("Добавить организации", this);

    orgsMenu->addAction(selectAllOrgsAction);
    orgsMenu->addAction(deselectAllOrgsAction);
    orgsMenu->addAction(addOrgsAction);

    ui->toolButton_3->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolButton_3->setMenu(orgsMenu);
    ui->toolButton_3->setDefaultAction(deselectAllOrgsAction);

    connect(selectAllOrgsAction, &QAction::triggered, this, &MainWindow::SelectAllOrgs);
    connect(deselectAllOrgsAction, &QAction::triggered, this, &MainWindow::deSelectAllOrgs);
    connect(addOrgsAction, &QAction::triggered, this, &MainWindow::expandOrgsLibrary);

}

void MainWindow::SelectAllOrgs()
{
    setAllItemsCheckedState(ui->listWidget_2, Qt::Checked, QColor("#b2ffff"));

}
void MainWindow::deSelectAllOrgs()
{
    setAllItemsCheckedState(ui->listWidget_2, Qt::Unchecked, QColor("#ffffff"));

}
void MainWindow::expandOrgsLibrary()
{
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QStringList urls = QFileDialog::getOpenFileNames(
        this, "Выберите файлы организаций",
        initialPath,
        "Файлы (*.docx *.txt)"
        );
    if (urls.isEmpty()) {
        return;
    }

    QString destinationDir = qApp->applicationDirPath() + "/Организации/";
    QDir().mkpath(destinationDir); // существует

    for (const QString &url : urls) {
        QString filename = QFileInfo(url).fileName();
        QString destPath = destinationDir + filename;

        if (QFile::exists(destPath)) {
            destPath = testAndIncrementFilename(destPath);
        }

        if (QFile::copy(url, destPath)) {
            service1.orgsBook.append(destPath);

            QString newFileName = QFileInfo(destPath).fileName();
            QString displayText = QString::number(service1.orgsBook.size()) + ": " + newFileName;

            QListWidgetItem *newItem = new QListWidgetItem(displayText, ui->listWidget_2);
            newItem->setFlags(newItem->flags() | Qt::ItemIsUserCheckable);
            newItem->setBackground(QColor("#b2ffff"));
            newItem->setCheckState(Qt::Checked);
        } else {
            QMessageBox::warning(this, "Ошибка", QString("Не удалосб скопировать файл"));
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////


QString removeNumber(const QString &input)
{
    // section() делит строку по разделителю.
    // 1 - взять часть ПОСЛЕ первого разделителя.
    // SectionSkipEmpty пропускает пустые части, если разделитель в начале.
    return input.section(' ', 1, -1, QString::SectionSkipEmpty);
}

//--------------------------------------------------------------------
// Кнопка для удаления
//--------------------------------------------------------------------
void MainWindow::DeleteButton()
{
    QMenu* deleteMenu = new QMenu(this);

    QAction* deleteSelectedAction = new QAction("Удалить выбранные", this);
    QAction* deleteAllItemsAction = new QAction("Удалить все", this);

    deleteMenu->addAction(deleteSelectedAction);
    deleteMenu->addAction(deleteAllItemsAction);

    ui->toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolButton->setMenu(deleteMenu);
    ui->toolButton->setDefaultAction(deleteSelectedAction);

    connect(deleteSelectedAction, &QAction::triggered, this, &MainWindow::on_deleteElement);
    connect(deleteAllItemsAction, &QAction::triggered, this, &MainWindow::on_deleteAllElement);
}

void MainWindow::on_deleteElement() // нужно добавить чтобы удалялись элементы service1.files
{
    QList<QTreeWidgetItem*> selectedItems = ui->treeWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        return;
    }

    for (QTreeWidgetItem *item : selectedItems) {
        // не родитель и существует
        if (!item || !item->parent()) {
            continue;
        }
        // удаление элемента
        QTreeWidgetItem *parent = item->parent();

        QString fileUrl = item->text(1); // URL файла

        auto it = std::remove_if(service1.files.begin(), service1.files.end(),
                                 [&](const auto& file) {
                                     return file.URL == fileUrl;
                                 });
        service1.files.erase(it, service1.files.end());

        // Измененеие счетчика
        QString str = parent->text(0);
        if (str.at(str.length()-1).isDigit()){
            QString number;
            for(int j = str.length()-1; j > 0; j--)
            {
                if (str.at(j).isDigit()==true)
                    number+=str.at(j);
                if (str.at(j).isDigit()==false)
                    break;
            }
            QString reversed;
            for (int i = number.length() - 1; i >= 0; --i) {
                reversed.append(number.at(i));
            }
            int n = reversed.toInt();
            n = n-1;
            str.replace(reversed, QString::number(n));

            parent->setText(0, str);
        }

        delete item;
    }

    return;
}

void MainWindow::on_deleteAllElement() // нужно добавить чтобы удалялись элементы service1.files
{
    service1.files.clear();
    ParentsItems.clear(); // Также очищаем список корневых элементов

    ui->treeWidget->clear();
}
//--------------------------------------------------------------------
// Кнопка экспорта файлов
//--------------------------------------------------------------------

void MainWindow::ExportToolButton()
{
    QMenu* exportMenu = new QMenu(this);

    QAction* exportToExcel = new QAction("Сохранить в excel", this);
    QAction* createFile = new QAction("Сохранить файлы", this);

    exportMenu->addAction(exportToExcel);
    exportMenu->addAction(createFile);

    ui->exportToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    ui->exportToolButton->setMenu(exportMenu);
    ui->exportToolButton->setDefaultAction(createFile);

    connect(exportToExcel, &QAction::triggered, this, &MainWindow::on_exportToExcel);
    connect(createFile, &QAction::triggered, this, &MainWindow::on_createFile);
}

void MainWindow::on_exportToExcel()
{
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    tr("Сохранить в excel"),
                                                    initialPath,
                                                    tr("Файл excel (*.xlsx)"));

    if (filePath.isEmpty()){
        return;
    }

    lxw_workbook *workbook = workbook_new(filePath.toUtf8().constData());
    if (!workbook) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось создать файл"));
        return;
    }

    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "Данные");
    if (!worksheet) {
        workbook_close(workbook);
        QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось создать файл"));
        return;
    }

    lxw_format *header_format = workbook_add_format(workbook);
    format_set_bold(header_format);
    format_set_bg_color(header_format, 0xD3D3D3);  // Light gray header
    format_set_align(header_format, LXW_ALIGN_CENTER);

    lxw_format *data_format = workbook_add_format(workbook);
    format_set_align(data_format, LXW_ALIGN_LEFT);

    worksheet_write_string(worksheet, 0, 0, "Сфера", header_format);

    int excel_col = 1;
    for (int col = 0; col < ui->treeWidget->columnCount(); ++col) {
        if (!ui->treeWidget->isColumnHidden(col)) {
            QString header = ui->treeWidget->headerItem()->text(col);
            worksheet_write_string(worksheet, 0, excel_col, header.toUtf8().constData(), header_format);
            excel_col++;
        }
    }

    int excel_row = 1;
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        QTreeWidgetItem *item = *it;

        // Process both leaf nodes and parent nodes without children
        if (item->parent()) {
            // Build parent path string (skip empty parent names)
            QStringList parentPath;
            QTreeWidgetItem *parent = item->parent();
            while (parent) {
                if (!parent->text(0).isEmpty()) {
                    parentPath.prepend(parent->text(0));
                }
                parent = parent->parent();
            }

            worksheet_write_string(worksheet, excel_row, 0,
                                   parentPath.join(" → ").toUtf8().constData(),
                                   data_format);

            int current_col = 1;
            for (int col = 0; col < ui->treeWidget->columnCount(); ++col) {
                if (!ui->treeWidget->isColumnHidden(col)) {
                    worksheet_write_string(worksheet, excel_row, current_col,
                                           item->text(col).toUtf8().constData(),
                                           data_format);
                    current_col++;
                }
            }
            excel_row++;
        }
        ++it;
    }

    worksheet_set_column(worksheet, 0, 0, 30, NULL);
    for (int col = 1; col < excel_col; col++) {
        worksheet_set_column(worksheet, col, col, 20, NULL);
    }

    worksheet_autofilter(worksheet, 0, 0, excel_row-1, excel_col - 1);

    lxw_error error = workbook_close(workbook);
    if (error != LXW_NO_ERROR) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка: %1").arg(error));
    } else {
        QMessageBox::information(this, tr("Успех"),
                                 tr("Данные успешно сохранены в :\n%1").arg(filePath));
    }
}

void MainWindow::on_createFile()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Выберите конечную папку"),
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (dir.isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Ошибка - папка не выбрана");
        return;
    }

    int totalItems = countFilesInTree(ui->treeWidget);
    QProgressDialog progress("Копирование файлов...", "Отмена", 0, totalItems, this);
    progress.setWindowTitle("Копирование файлов");  // Custom title
    progress.setWindowModality(Qt::NonModal);
    progress.setMinimumDuration(0);

    int successCount = 0;
    int skipCount = 0;
    int errorCount = 0;
    QStringList copiedFiles;
    QStringList errorFiles;

    // 3. Process files
    QTreeWidgetItemIterator it(ui->treeWidget);
    int currentItem = 0;
    while (*it) {
        QTreeWidgetItem *item = *it;

        QString filePath = item->text(1).trimmed();
        if (filePath.isEmpty() || filePath == " " || item->childCount() > 0) {
            ++it;
            continue;
        }

        progress.setValue(currentItem++);
        if (progress.wasCanceled()) break;

        if (QFile::exists(filePath)) {
            QString newPath = dir + "/" + QFileInfo(filePath).fileName();

            if (filePath == newPath) {
                skipCount++;
                ++it;
                continue;
            }

            if (QFile::exists(newPath)) {

                progress.hide();

                QMessageBox msgBox(this);
                msgBox.setWindowTitle("Файл существует");
                msgBox.setText(QString("Переписать существующий файл?\n%1").arg(newPath));
                msgBox.setIcon(QMessageBox::Question);

                // Add custom buttons with Russian text
                QPushButton *overwriteButton = msgBox.addButton("Да", QMessageBox::YesRole);
                QPushButton *skipButton = msgBox.addButton("Нет", QMessageBox::NoRole);
                QPushButton *cancelButton = msgBox.addButton("Остановиться", QMessageBox::RejectRole);
                msgBox.setDefaultButton(overwriteButton);

                msgBox.exec();

                progress.show();

                if (msgBox.clickedButton() == cancelButton) {
                    break;
                } else if (msgBox.clickedButton() == skipButton) {
                    skipCount++;
                    ++it;
                    continue;
                }
                QFile::remove(newPath);
            }

            if (QFile::copy(filePath, newPath)) {
                successCount++;
                copiedFiles << newPath;
            } else {
                errorCount++;
                errorFiles << filePath;

            }
        } else {
            errorCount++;
            errorFiles << filePath;

        }

        ++it;
    }

    progress.close();

    QString summary = QString("Операция завершена :\n"
                              "Успешно копировано: %1\n"
                              "Пропущено : %2\n"
                              "Ошибки : %3")
                          .arg(successCount).arg(skipCount).arg(errorCount);

    if (!errorFiles.isEmpty()) {
        summary += "\n\nОшибки :\n" + errorFiles.join("\n");
    }

    QMessageBox::information(this, "Результаты копирования", summary);

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Открыть файл");
    msgBox.setText("Открыть файл назначения?");
    msgBox.setIcon(QMessageBox::Question);

    // Add custom buttons
    QPushButton *openButton = msgBox.addButton("&Да", QMessageBox::YesRole);
    QPushButton *cancelButton = msgBox.addButton("&Нет", QMessageBox::NoRole);
    msgBox.setDefaultButton(openButton);

    // Execute and check result
    msgBox.exec();
    if (msgBox.clickedButton() == openButton) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir));
    }
}

int MainWindow::countFilesInTree(QTreeWidget* tree)
{
    int count = 0;
    QTreeWidgetItemIterator it(tree);
    while (*it) {
        QTreeWidgetItem *item = *it;

        if (!item->text(1).trimmed().isEmpty() && item->childCount() == 0) {
            count++;
        }
        ++it;
    }
    return count;
}

//--------------------------------------------------------------------
// Стиль
//--------------------------------------------------------------------

void MainWindow::styleWidget()
{
    ui->showButton->hide();
    ui->plainTextEdit->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->tabWidget->setTabText(0, "Сферы");
    ui->tabWidget->setTabText(1, "Категории");

    ui->frame_2->setFrameShape(QFrame::HLine);
    ui->frame_2->setFrameShadow(QFrame::Sunken);
    ui->frame->setFrameShape(QFrame::HLine);
    ui->frame->setFrameShadow(QFrame::Sunken);

    ui->treeWidget -> setColumnHidden(1, true);
    ui->treeWidget->setColumnWidth(0,350);
    ui->treeWidget->header()->ResizeToContents;
    ui->treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui->treeWidget->setStyleSheet("QTreeView { background-color: rgb(255,250,250);}");
    ui->treeWidget->setAlternatingRowColors(true);
}

//--------------------------------------------------------------------
// Работа с элементами
//--------------------------------------------------------------------

void MainWindow::on_addElement_clicked()
{
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QStringList urls = QFileDialog::getOpenFileNames(
        this,
        "Выберите файл для обработки",
        initialPath,
        tr("Text files (*.txt *.pdf *.docx)")
        );

    if (urls.isEmpty()){
        return;
    }

    if (!ParentsItems.isEmpty() &&
        ParentsItems.last()->text(0) == QObject::tr("Не отсортированные")) {
        addFilesToRoot(ParentsItems.last(), urls);
        return;
    }

    QTreeWidgetItem *root = AddRoot(tr("Не отсортированные"));
    QColor bg(255, 0, 0, 25);  // Red with alpha
    root->setBackground(0, QBrush(bg));
    root->setExpanded(true);
    ParentsItems.append(root);

    addFilesToRoot(root, urls);
    return;
}

void MainWindow::addFilesToRoot(QTreeWidgetItem *root,
                                const QStringList &urls) {
    for (const auto &path : urls) {
        const QString desc = service1.Check_contents(path);
        const QString fileName = QFileInfo(path).fileName();
        AddChild(root, fileName, path, desc);
    }
}

void MainWindow::on_addLaws_clicked(){
    CreateChart *newWind = new CreateChart(this);
    newWind->setTreeWidget(ui->treeWidget);
    newWind->show();
}

void MainWindow::on_redactButton_clicked()
{
    QTreeWidgetItem *selectedItem = ui->treeWidget->currentItem();
    if (!selectedItem) {
        return;
    }

    RedactingItem *newWind = new RedactingItem(this);
    newWind->setAttribute(Qt::WA_DeleteOnClose);
    newWind->setItems(ui->treeWidget, selectedItem);
    newWind->show();
}

void MainWindow::AddChild(QTreeWidgetItem *parent,
                          const QString &name,
                          const QString &url,
                          const QString &description) {
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, name);
    item->setText(1, url);
    item->setText(2, description);
    parent->addChild(item);
}

QTreeWidgetItem* MainWindow::AddRoot(const QString& name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0,name);
    ui->treeWidget->addTopLevelItem(item);
    return item;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item->parent() == nullptr) {
        const int count = item->childCount();
        if (count == 0)
            return;
        const bool select = !item->child(0)->isSelected();
        for (int i = 0; i < count; ++i)
            item->child(i)->setSelected(select);
    }
}

void MainWindow::on_treeWidget_doubleClicked()
{
    const auto selItems = ui->treeWidget->selectedItems();
    if (selItems.isEmpty())
        return;
    QTreeWidgetItem *item = selItems.last();
    if (item->parent() == nullptr)
        return;

    const QString path = item->text(1);
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));

}

void MainWindow::openFromList(const QModelIndex &index, const QString &subdir) {
    if (!index.isValid())
        return;
    const QString filename = removeNumber(index.data().toString());
    const QString path = qApp->applicationDirPath() + subdir + filename;
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index) {
    openFromList(index, "/Сферы/");
}

void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index) {
    openFromList(index, "/Организации/");
}

struct Color {
    int r; // Red component
    int g; // Green component
    int b; // Blue component

    // Constructor
    Color(int red, int green, int blue) : r(red), g(green), b(blue) {}

    // Method to interpolate between two colors
    static Color interpolate(const Color& start, const Color& end, float t) {
        // Clamp t to the range [0, 1]
        t = std::fmax(0.0f, std::fmin(1.0f, t));

        // Calculate the interpolated color
        int r = static_cast<int>(start.r + (end.r - start.r) * t);
        int g = static_cast<int>(start.g + (end.g - start.g) * t);
        int b = static_cast<int>(start.b + (end.b - start.b) * t);

        return Color(r, g, b);
    }
};

void MainWindow::on_sortElement_clicked()
{

    ui->treeWidget->setSortingEnabled(false);
    int a = service1.files.size();
    if (a==0) return;

    //ParentsItems.clear();
    service1.lawBook.clear();
    for (int i =0; i < ui->listWidget->count(); i++ )
    {
        //item->checkState() == Qt::Checked

        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
        {
            QString path = qApp->applicationDirPath();
            path.append("/Сферы/");
            QString text = removeNumber(ui->listWidget->item(i)->text());
            path.append(text);
            service1.lawBook.append(path);
        }

    }

    //ui->sortElement->setEnabled(false);

    if (ParentsItems.isEmpty())
    {
        //ui->sortElement->setEnabled(true);

        return;
    }

    QTreeWidgetItem *item;
    for(int i=0;i<ParentsItems.size();i++)
    {
        item = ParentsItems[i];
        if(item)
        {
            delete item;
        }
    }
    ParentsItems.clear();

    for (int i=0; i<=service1.lawBook.size();i++)
    {
        QTreeWidgetItem *test_1;
        ParentsItems.append(test_1);
    }

    QVector<QTreeWidgetItem *> vector; //здесь хранятся все адреса для родителей сферы

    for (int i=0; i<service1.lawBook.size();i++)
    {
        QStringList pieces = service1.lawBook[i].split( "/" );
        QString lawBookItem = pieces.value( pieces.length() - 1 );

        item = AddRoot(lawBookItem);
        vector.append(item);
        ParentsItems[i] = item;
    }

    QTreeWidgetItem *root;
    root = AddRoot("Не сортируемые");
    ParentsItems[service1.lawBook.size()] = root;

    Color startColor(220, 150, 250); // Purple
    Color endColor(0, 0, 255);   // Blue
    float r = 0;
    float step = 1.0 / ParentsItems.size();
    for (int i=0; i<ParentsItems.size(); i++)
    {
        r = r + step;
        Color interpolatedColor = Color::interpolate(startColor, endColor, r);
        //qDebug() << interpolatedColor.r << interpolatedColor.g << interpolatedColor.b;
        QColor color = QColor(interpolatedColor.r, interpolatedColor.g,interpolatedColor.b);
        color.setAlphaF( 0.5 );
        //color = QColor(Qt::yellow);
        ParentsItems[i]->setBackground(0, QBrush(color));
    }


    std::vector<QStringList> AllLawsSaved(service1.lawBook.count());
    for (int i=0; i<service1.lawBook.count();i++)
    {
        QStringList temp;

        QString filePath = service1.lawBook[i];
        std::string stdpath = filePath.toLocal8Bit().constData();
        duckx::Document doc(stdpath);

        doc.open();

        for (auto p : doc.paragraphs())
            for (auto r : p.runs())
            {
                std::string str = r.get_text();
                QString input = QString::fromStdString(str);
                temp.append(input);

            }
        AllLawsSaved[i] = temp;
    }

    ProgressDialog *progressDialog = new ProgressDialog(this);
    progressDialog->setMessage("Обработка...");
    progressDialog->setLength(a);
    progressDialog->show();

    // for
    //  progressDialog->setProgress(i);
    // progressDialog->accept();


    for (int i = 0; i < service1.files.size(); i++)
    {
        QStringList copys;

        QCoreApplication::processEvents(); // Process events while updating
        progressDialog->setProgress(i);

        QString URL = service1.files[i].URL; // C:/place/in/sytem/file1.txt

        QStringList pieces = URL.split( "/" );
        QString Item = pieces.value( pieces.length() - 1 ); // file1.txt

        std::vector<int> a(service1.lawBook.count()); // vector a {0 , 1 , 2 ...}

        QString Description = "";

        QStringList fileContents = service1.FullFile(service1.files[i].URL);

        for (const auto &oneLine: fileContents)
        {
            QString lineToCheckForLaws = oneLine;
            if (lineToCheckForLaws!="" &&
                lineToCheckForLaws!=" " &&
                lineToCheckForLaws.size()>5 &&
                lineToCheckForLaws.contains(" ") &&
                copys.contains(lineToCheckForLaws) == false)
            {
                for (int i=0; i<service1.lawBook.count();i++)
                {
                    QStringList RuleBookContents = AllLawsSaved[i];

                    QStringList pieces = service1.lawBook[i].split( "/" );
                    QString Item = pieces.value( pieces.length() - 1 ); // file1.txt

                    for (const auto &oneRule: RuleBookContents)
                    {
                        if (oneRule.contains(lineToCheckForLaws))
                        {
                            copys.append(lineToCheckForLaws);

                            QString Text = "";

                            for (int j = 0; j < ui->listWidget->count(); j++)
                            {
                                QListWidgetItem *item = ui->listWidget->item(j);
                                if (Item == removeNumber(item->text()))
                                {
                                    Text = item->text();
                                }
                            }

                            Description.append(Text.split(" ").at(0) + lineToCheckForLaws);

                            Description.append("\n ");
                            a[i] = a[i] + 1;
                            break;
                        }
                    }

                }
            }
        }



        service1.files[i].lawBookNumber = a;
        std::vector <int> A = service1.files[i].lawBookNumber;
        bool zeros = std::all_of(A.begin(), A.end(), [](int i) { return i==0; }); //Если состоит из 0 и нет
        if(zeros)
        {
            AddChild(root, Item , URL , Description);
        }
        else
        {
            int maxElementIndex = std::max_element(A.begin(),A.end()) - A.begin();

            AddChild(vector[maxElementIndex], Item , URL , Description);
        }

    }

    // для написания размерности каждого родителя после добавления всех элементов
    for (int i = 0; i < ParentsItems.size() - 1  ; i++)
    {
        QTreeWidgetItem *toHelp;
        toHelp = ParentsItems[i];

        QString Item;

        QString name = service1.lawBook[i];
        QStringList pieces = name.split( "/" );
        Item = pieces.value( pieces.length() - 1 );
        Item.append(" ---- элементов : ");
        Item.append(QString::number(toHelp->childCount()));

        toHelp->setText(0,Item);
        //toHelp->setExpanded(false);
    }

    QString Item;
    QTreeWidgetItem *toHelp = ParentsItems[ParentsItems.size()-1];

    Item.append("Не сортируемые ---- элементов: ");
    Item.append(QString::number(toHelp->childCount()));
    toHelp->setText(0,Item);

    ui->treeWidget->setSortingEnabled(true);
    ui->treeWidget->sortItems(1, Qt::AscendingOrder);
    progressDialog->accept();

}






void MainWindow::on_CreateDate_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Дата создания")
        {
            header->showSection(i);
            // если такая колонка существует
            QTreeWidgetItemIterator it(ui->treeWidget);
            while (*it) {
                if ((*it)->text(1) != "")
                {
                    //QString url = (*it)->text(1);
                    QDateTime thisFile = QFileInfo((*it)->text(1)).lastModified();
                    QString ofThisFile = thisFile.toString("yyyy-MM-dd");
                    (*it)->setText(i, ofThisFile);

                }

                ++it;
            }
            return;
        }
    }

    // если нужно ее вначале создать
    ui->treeWidget->setColumnCount(columnCount + 1);

    ui->treeWidget->headerItem()->setText(columnCount,"Дата создания");


    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        if ((*it)->text(1) != "")
        {
            //QString url = (*it)->text(1);
            QDateTime thisFile = QFileInfo((*it)->text(1)).lastModified();
            QString ofThisFile = thisFile.toString("yyyy-MM-dd");
            (*it)->setText(columnCount, ofThisFile);

        }

        ++it;
    }

    return;
}

void MainWindow::on_HideDate_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Дата создания")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

void MainWindow::on_HideDescription_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Описание")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

void MainWindow::on_CreateDescription_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Описание")
        {
            header->showSection(i);
            // если такая колонка существует
            return;
        }
    }
    return;
}

void MainWindow::on_CreateTarget_triggered()
{
    int columnCount = ui->treeWidget->columnCount();
    QHeaderView* header = ui->treeWidget->header();
    int columnIndex = -1;

    for (int i = 0; i < columnCount; i++)
    {
        if (header->model()->headerData(i, Qt::Horizontal).toString() == "Кому")
        {
            columnIndex = i;
            break;
        }
    }

    if (columnIndex == -1)
    {
        ui->treeWidget->setColumnCount(columnCount + 1);
        ui->treeWidget->headerItem()->setText(columnCount, "Кому");
        columnIndex = columnCount;
    }

    ui->treeWidget->setColumnHidden(columnIndex, false);  // Show the column

    // Count relevant items for progress tracking
    int totalItems = 0;
    QTreeWidgetItemIterator countIt(ui->treeWidget);
    while (*countIt) {
        if (!(*countIt)->text(1).isEmpty()) totalItems++;
        ++countIt;
    }

    if (totalItems == 0) {
        QMessageBox::information(this, "Информация", "Нет предметов для обрабоки");
        return;
    }

    QProgressDialog progressDialog("Обработка документов...", "Отмена", 0, totalItems, this);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(0);
    progressDialog.setWindowTitle("Прогресс");
    progressDialog.show();

    // Process items
    QTreeWidgetItemIterator it(ui->treeWidget);
    int processedItems = 0;
    bool wasCanceled = false;

    while (*it && !wasCanceled)
    {
        if (progressDialog.wasCanceled()) {
            wasCanceled = true;
            break;
        }

        if (!(*it)->text(1).isEmpty())
        {
            QString filePath = (*it)->text(1);
            int extension = service1.checkFileExtension(filePath);

            // Обработка PDF документов
            if (extension == 3)
            {
                QPdfDocument document;
                if (document.load(filePath) == QPdfDocument::Error::None)
                {
                    QString selectedText = document.getAllText(0).text();
                    QString ToWhom = "";

                    for (int i = selectedText.length()-1; i > 2 ; i --)
                    {
                        if (selectedText[i]=='.' && selectedText[i-2]=='.')
                        {
                            int leftIndex=-1, rightIndex=selectedText.length()+1;
                            for (int j=i;j>2;j--)
                            {
                                if (selectedText[j]=='\n'){
                                    leftIndex = j;
                                    break;
                                }
                            }
                            for (int j=i+2;j<selectedText.length();j++)
                            {
                                if (selectedText[j]=='\n'){
                                    rightIndex = j;
                                    break;
                                }
                            }
                            ToWhom = "";
                            for (int j=leftIndex+1;j<rightIndex-1;j++)
                            {
                                ToWhom+=selectedText[j];
                            }


                            break;
                        }
                    }

                    int spaceCount = 0;
                    for (const QChar& ch : ToWhom) {
                        if (ch.isSpace()) {
                            spaceCount++;
                            if (spaceCount >= 3) {
                                ToWhom="";
                            }
                        }
                    }
                    (*it)->setText(columnIndex, ToWhom);

                    document.close();
                }
            }

            processedItems++;
            progressDialog.setValue(processedItems);
            qApp->processEvents();
        }

        ++it;
    }

    progressDialog.close();

    if (!wasCanceled) {
        ui->treeWidget->setSortingEnabled(true);
        QMessageBox::information(this, "Готово", "Обработка завершена успешно");
    } else {
        QMessageBox::information(this, "Прервано", "Обработка прервана пользователем");
    }
}

void MainWindow::on_CreateAuthor_triggered()
{
    // Find or create the "Подписал" column
    int columnCount = ui->treeWidget->columnCount();
    QHeaderView* header = ui->treeWidget->header();
    int columnIndex = -1;

    for (int i = 0; i < columnCount; i++)
    {
        if (header->model()->headerData(i, Qt::Horizontal).toString() == "Подписал")
        {
            columnIndex = i;
            break;
        }
    }

    if (columnIndex == -1)
    {
        ui->treeWidget->setColumnCount(columnCount + 1);
        ui->treeWidget->headerItem()->setText(columnCount, "Подписал");
        columnIndex = columnCount;
    }

    ui->treeWidget->setColumnHidden(columnIndex, false);  // Show the column

    // Count PDF items to process for progress tracking
    int totalItems = 0;
    QTreeWidgetItemIterator countIt(ui->treeWidget);
    while (*countIt) {
        if (!(*countIt)->text(1).isEmpty()) totalItems++;
        ++countIt;
    }

    if (totalItems == 0) {
        QMessageBox::information(this, "Информация", "Нет документов для обработки");
        return;
    }

    // Setup progress dialog
    QProgressDialog progressDialog("Обработка подписей...", "Отмена", 0, totalItems, this);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(0);
    progressDialog.setWindowTitle("Прогресс обработки");
    progressDialog.show();

    // Process items
    QTreeWidgetItemIterator it(ui->treeWidget);
    int processedItems = 0;
    bool wasCanceled = false;

    while (*it && !wasCanceled)
    {
        if (progressDialog.wasCanceled()) {
            wasCanceled = true;
            break;
        }

        if (!(*it)->text(1).isEmpty())
        {
            QString filePath = (*it)->text(1);
            int extension = service1.checkFileExtension(filePath);

            if (extension == 3) // Only process PDF documents
            {
                QPdfDocument document;
                if (document.load(filePath) == QPdfDocument::Error::None)
                {
                    // Get text from last page
                    QString selectedText = document.getAllText(document.pageCount()-1).text();

                    // Include second-to-last page if exists
                    if (document.pageCount() >= 2) {
                        selectedText = document.getAllText(document.pageCount()-2).text() + selectedText;
                    }

                    QString signature = extractSignature(selectedText); // Extracted logic to separate function
                    (*it)->setText(columnIndex, signature);
                }
                else
                {
                    (*it)->setText(columnIndex, "Ошибка загрузки");
                }
            }

            processedItems++;
            progressDialog.setValue(processedItems);
            qApp->processEvents(); // Keep UI responsive
        }

        ++it;
    }

    progressDialog.close();

    if (!wasCanceled) {
        ui->treeWidget->setSortingEnabled(true);
        QMessageBox::information(this, "Готово", "Обработка подписей завершена");
    }
}

QString MainWindow::extractSignature(const QString &pdfText)
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
    for (int i = position-1; i > 0; i--)
    {
        if (pdfText[i] == '[' || pdfText[i] == ']' || pdfText[i] == '\n') {
            signature.clear();
        }
        else {
            if (pdfText[i] == '.' && pdfText[i-2] == '.') {
                signature += pdfText[i];
                signature += pdfText[i-1];
                signature += pdfText[i-2];
                signature += pdfText[i-3];
                break;
            }
            else if (!pdfText[i].isDigit()) {
                signature += pdfText[i];
            }
        }
    }

    if (signature.length() == 4) {
        signature += ' ';
        for (int i = position-6; i > 0; i--) {
            if (pdfText[i] != ' ') {
                signature += pdfText[i];
            }
            else {
                break;
            }
        }
    }

    std::reverse(signature.begin(), signature.end());
    return signature;
}

void MainWindow::on_CreateDocumentType_triggered()
{
    int columnCount = ui->treeWidget->columnCount();
    int typeColumnIndex = -1;

    for (int i = 0; i < columnCount; i++) {
        if (ui->treeWidget->headerItem()->text(i) == "Тип документа") {
            typeColumnIndex = i;
            break;
        }
    }

    if (typeColumnIndex == -1) {
        typeColumnIndex = columnCount;
        ui->treeWidget->setColumnCount(columnCount + 1);
        ui->treeWidget->headerItem()->setText(typeColumnIndex, "Тип документа");
    }

    ui->treeWidget->setColumnHidden(typeColumnIndex, false);

    QMap<QString, QString> typeKeywords = {
        {"представление", "Представление"},
        {"agreement", "Agreement"}

    };

    int totalItems = 0;
    QTreeWidgetItemIterator countIt(ui->treeWidget);
    while (*countIt) {
        if (!(*countIt)->text(1).isEmpty()) totalItems++;
        ++countIt;
    }

    if (totalItems == 0) {
        return;
    }

    QProgressDialog progressDialog("Обработка документов...", "Отменить", 0, totalItems, this);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(0);
    progressDialog.show();

    // Process items
    QTreeWidgetItemIterator it(ui->treeWidget);
    int processedItems = 0;
    bool wasCanceled = false;

    while (*it && !wasCanceled) {
        if (progressDialog.wasCanceled()) {
            wasCanceled = true;
            break;
        }

        if (!(*it)->text(1).isEmpty()) {
            QString filePath = (*it)->text(1);
            int extension = service1.checkFileExtension(filePath);

            if (extension == 3) {
                QPdfDocument document;
                if (document.load(filePath) == QPdfDocument::Error::None && document.pageCount() > 0) {
                    QString firstPageText = document.getAllText(0).text().toLower();
                    QString foundType = "Ошибка";
                    for (auto it = typeKeywords.constBegin(); it != typeKeywords.constEnd(); ++it) {
                        if (firstPageText.contains(it.key())) {
                            foundType = it.value();
                            break;
                        }
                    }

                    (*it)->setText(typeColumnIndex, foundType);
                } else {
                    (*it)->setText(typeColumnIndex, "Ошибка");
                }
            }

            processedItems++;
            progressDialog.setValue(processedItems);
            qApp->processEvents();
        }

        ++it;
    }

    progressDialog.close();

    if (!wasCanceled) {
        ui->treeWidget->setSortingEnabled(true);
        QMessageBox::information(this, "Успех", "Обработка докуметов завершена успешно");
    }
}


void MainWindow::on_HideDocumentType_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Тип документа")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

void MainWindow::on_HideAuthor_triggered()
{

    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Подписал")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

void MainWindow::on_HideTarget_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Кому")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

void MainWindow::on_SphereChangeState_triggered()
{
    if (ui->tabWidget->isVisible() == true)
    {
        ui->hideButton->hide();
        ui->tabWidget->hide();
        ui->showButton->show();
    }
    else
    {
        ui->showButton->hide();
        ui->tabWidget->show();
        ui->hideButton->show();
    }
}

void MainWindow::on_openFileLocation_triggered()
{
    QString path = qApp->applicationDirPath() + "/Сферы";
    qDebug() << path << "this";
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MainWindow::on_hideButton_clicked()
{
    ui->hideButton->hide();
    ui->tabWidget->hide();
    ui->showButton->show();
}

void MainWindow::on_showButton_clicked()
{
    ui->showButton->hide();
    ui->tabWidget->show();
    ui->hideButton->show();
}

void MainWindow::on_searchButton_pressed()
{
    QString text = ui->seachEdit->text().trimmed();

    if (text.isEmpty())
    {
        QMessageBox::information(this, tr("Поиск невозможен"),
                                 tr("Пожалуйста повторите снова."));
        return;
    }
    else
    {
        QTreeWidgetItemIterator it(ui->treeWidget);
        while (*it)
        {
            QTreeWidgetItem *item = *it;
            bool matches = false;
            //item->text(1).contains(text, Qt::CaseInsensitive);
            for (int col = 0; col < ui->treeWidget->columnCount(); ++col)
            {
                if (!ui->treeWidget->isColumnHidden(col))
                {
                    if (item->text(col).contains(text, Qt::CaseInsensitive)) {matches = true; break;}
                }
            }
            if (item->parent()!=nullptr)
                item->setSelected(matches);

            ++it;
        }

    }
}
void MainWindow::on_antiButton_pressed()
{
    QString text = ui->seachEdit->text().trimmed();

    if (text.isEmpty())
    {
        QMessageBox::information(this, tr("Поиск невозможен"),
                                 tr("Пожалуйста повторите снова."));
        return;
    }
    else
    {
        QTreeWidgetItemIterator it(ui->treeWidget);
        while (*it)
        {
            QTreeWidgetItem *item = *it;
            bool matches = false;
            //item->text(1).contains(text, Qt::CaseInsensitive);
            for (int col = 0; col < ui->treeWidget->columnCount(); ++col)
            {
                if (!ui->treeWidget->isColumnHidden(col))
                {
                    if (item->text(col).contains(text, Qt::CaseInsensitive)) {matches = true; break;}
                }
            }
            if (item->parent()!=nullptr)
                item->setSelected(!matches);

            ++it;
        }

    }
}

void MainWindow::on_cancelButton_pressed()
{
    ui->treeWidget->clearSelection();

}

void MainWindow::on_CreateOrg_triggered()
{
    // Find or create "Type" column
    int typeColumn = -1;
    for (int i = 0; i < ui->treeWidget->columnCount(); i++) {
        if (ui->treeWidget->headerItem()->text(i) == "Организация") {
            typeColumn = i;
            break;
        }
    }
    if (typeColumn == -1) {
        typeColumn = ui->treeWidget->columnCount();
        ui->treeWidget->setColumnCount(typeColumn + 1);
        ui->treeWidget->headerItem()->setText(typeColumn, "Организация");
    }
    ui->treeWidget->setColumnHidden(typeColumn, false);

    // Build organization-to-type map from listWidget_2 files
    QMap<QString, QString> orgToTypeMap;
    QString typesPath = qApp->applicationDirPath() + "/Организации/";

    for (int i = 0; i < ui->listWidget_2->count(); i++) {
        if (ui->listWidget_2->item(i)->checkState() == Qt::Checked) {
            QString typeFileName = removeNumber(ui->listWidget_2->item(i)->text());
            QString typeName = typeFileName.split('.').first();
            QString filePath = typesPath + typeFileName;

            if (filePath.endsWith(".docx", Qt::CaseInsensitive)) {
                // Handle .docx files with duckx
                std::string stdpath = filePath.toLocal8Bit().constData();
                duckx::Document doc(stdpath);
                doc.open();

                for (auto p : doc.paragraphs()) {
                    for (auto r : p.runs()) {
                        std::string str = r.get_text();
                        QString orgName = QString::fromStdString(str)
                                              .replace("\"", "'")
                                              .replace("«", "'")
                                              .replace("»", "'")
                                              .trimmed();

                        if (!orgName.isEmpty()) {
                            orgToTypeMap[orgName] = typeName;
                        }
                    }
                }
            } else {
                // Handle other file types (txt, etc)
                QFile typeFile(filePath);
                if (typeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&typeFile);
                    while (!in.atEnd()) {
                        QString orgName = in.readLine().trimmed();
                        if (!orgName.isEmpty()) {
                            orgToTypeMap[orgName] = typeName;
                        }
                    }
                    typeFile.close();
                }
            }
        }
    }

    if (orgToTypeMap.isEmpty()) {
        QMessageBox::information(this, "Информация", "Ошибка");
        return;
    }

    QProgressDialog progress("Обработка файлов...", "Отмена", 0, ui->treeWidget->topLevelItemCount(), this);
    progress.setWindowModality(Qt::WindowModal);

    QTreeWidgetItemIterator it(ui->treeWidget);
    int processed = 0;
    while (*it && !progress.wasCanceled()) {
        QTreeWidgetItem* item = *it;
        item->setText(typeColumn, "");

        QString filePath = item->text(1);
        if (!filePath.isEmpty()) {
            QString lastLines = getLastLines(filePath, 10);
            for (auto it = orgToTypeMap.constBegin(); it != orgToTypeMap.constEnd(); ++it) {
                if (lastLines.contains(it.key(), Qt::CaseInsensitive)) {
                    item->setText(typeColumn, it.value());
                    break;
                }
            }
        }

        progress.setValue(++processed);
        qApp->processEvents();
        ++it;
    }
    if (!progress.wasCanceled()) {
        ui->treeWidget->sortItems(typeColumn, Qt::AscendingOrder);
        QMessageBox::information(this, "Успех", "Заполнение огранизации завершено");
    }
}

QString MainWindow::getLastLines(const QString& filePath, int lineCount)
{
    if (filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        QPdfDocument doc;
        if (doc.load(filePath) == QPdfDocument::Error::None && doc.pageCount() > 0) {
            QString fullText = doc.getAllText(0).text();
            QStringList lines = fullText.split('\n', Qt::SkipEmptyParts);
            int start = qMax(0, lines.size() - lineCount);
            return lines.mid(start).join('\n');
        }
    }
    else if (filePath.endsWith(".docx", Qt::CaseInsensitive)) {
        std::string stdpath = filePath.toLocal8Bit().constData();
        duckx::Document doc(stdpath);
        doc.open();

        QStringList allLines;
        for (auto p : doc.paragraphs()) {
            for (auto r : p.runs()) {
                QString text = QString::fromStdString(r.get_text());
                allLines.append(text.split('\n', Qt::SkipEmptyParts));
            }
        }
        int start = qMax(0, allLines.size() - lineCount);
        return allLines.mid(start).join('\n');
    }
    else {
        // Regular text files
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd()) {
                lines.append(in.readLine());
                if (lines.size() > lineCount) {
                    lines.removeFirst();
                }
            }
            return lines.join('\n');
        }
    }
    return "";
}

void MainWindow::on_HideOrg_triggered()
{
    int columnCount = ui->treeWidget->columnCount();

    QHeaderView* header = ui->treeWidget->header();

    for (int i = 0; i <columnCount ; i++)
    {
        QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();
        if (justChecking == "Организация")
        {
            header->hideSection(i);
            // если такая колонка существует
            return;
        }
    }

    return;
}

