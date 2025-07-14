#include "createchart.h"
#include "ui_createchart.h"

CreateChart::CreateChart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateChart)
{
    ui->setupUi(this);
    setWindowTitle("Анализ данных");

    ui->chartTypeComboBox->addItem("Столбчатая диаграмма");
    ui->chartTypeComboBox->addItem("Столбчатая диаграмма с накоплением");
    ui->chartTypeComboBox->addItem("Круговая диаграмма");
    ui->authorCombo->addItem("Для всех");
    ui->authorCombo->setCurrentIndex(0);
}

CreateChart::~CreateChart()
{
    delete ui;
    delete AtreeWidget;
}

void CreateChart::setTreeWidget(QTreeWidget *tree)
{
    AtreeWidget = tree;

    if (columnWithNameExists(AtreeWidget, "Подписал")){
        ui->classTypeCombo->addItem("Подписал");}
    if (columnWithNameExists(AtreeWidget, "Кому")){
        ui->classTypeCombo->addItem("Кому");}

}

bool CreateChart::columnWithNameExists(QTreeWidget *treeWidget, const QString &columnName)
{
    QTreeWidgetItem *header = treeWidget->headerItem();
    if (!header) {
        return false;
    }

    int columnCount = treeWidget->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        if (header->text(i) == columnName) {
            return true;
        }
    }
    return false;
}

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    if (!layout)
        return;
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

void ensureAllNamesInClasses(QMap<QString, QMap<QString, int>>& data) {
    QSet<QString> allNames;
    for (const auto& classData : data) {
        for (const auto& name : classData.keys()) {
            allNames.insert(name);
        }
    }

    for (auto it = data.begin(); it != data.end(); ++it) {
        QMap<QString, int>& classData = it.value();
        for (const auto& name : allNames) {
            if (!classData.contains(name)) {
                classData[name] = 0;
            }
        }
    }
}

void CreateChart::setupChart(QString name){

    clearLayout(ui->ChartPlace);

    if (name == "Столбчатая диаграмма")
    {

        QString selectedColumn = ui->classTypeCombo->currentText();

        int column = AtreeWidget->columnCount();
        int index = -1;
        QHeaderView* header = AtreeWidget->header();

        for (int i = 0; i <column ; i++)
        {
            QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();

            if (justChecking == selectedColumn)
            {
                index = i;
                break;
            }
        }
        column = index;
        if (index == -1) return;

        QString selectedValue = ui->authorCombo->currentText();

        QMap<QString, QMap<QString, int>> data;
        for (int i = 0; i < AtreeWidget->topLevelItemCount(); ++i) {
            QTreeWidgetItem *parent = AtreeWidget->topLevelItem(i);
            QString parentName = parent->text(0);

            for (int j = 0; j < parent->childCount(); ++j) {
                QTreeWidgetItem *child = parent->child(j);
                QString key = child->text(column);
                key.remove(' ');
                key.remove("\r");
                key.remove("\n");
                if (key == "") key = "Пусто";

                //data[parentName][key]++;


                if (selectedValue == "Для всех")
                    data[parentName][key]++;
                else
                {
                    if (key == selectedValue)
                        data[parentName][key]++;
                }

            }
        }

        QString output;
        ui->textEdit->clear();
        for (auto outerIt = data.begin(); outerIt != data.end(); ++outerIt) {
            QString parentKey = outerIt.key();
            output += QString("Сфера: %1\n").arg(parentKey);

            for (auto innerIt = outerIt.value().begin(); innerIt != outerIt.value().end(); ++innerIt) {
                QString childKey = innerIt.key();
                int value = innerIt.value();
                output += QString("    %1: %2\n").arg(childKey).arg(value);
            }

            output += "\n";
        }
        ui->textEdit->append(output);

        // Много мыслей на данном этапе происходит //
        ensureAllNamesInClasses(data);

        QChart *chart = new QChart();
        chart->setTitle(QString("Столбцовая диаграмма %1").arg(selectedColumn));
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarSeries *series = new QBarSeries();
        QStringList categories;

        for (auto parentIt = data.begin(); parentIt != data.end(); ++parentIt) {
            QBarSet *barSet = new QBarSet(parentIt.key());
            for (auto keyIt = parentIt.value().begin(); keyIt != parentIt.value().end(); ++keyIt) {
                *barSet << keyIt.value();
                if (!categories.contains(keyIt.key())) {
                    categories << keyIt.key();
                }
            }
            series->append(barSet);
        }

        chart->addSeries(series);

        // Add axes
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        axisY->setTitleText("Количество");
        series->attachAxis(axisY);

        chart->legend()->setAlignment(Qt::AlignTop);
        chart->legend()->setMarkerShape(QLegend::MarkerShapeRectangle);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setRubberBand(QChartView::RectangleRubberBand);

        ui->ChartPlace->addWidget(chartView);

        ui->authorCombo->clear();
        ui->authorCombo->addItem("Для всех");
        ui->authorCombo->setCurrentIndex(0);
        ui->authorCombo->addItems(categories);

    }

    if (name == "Столбчатая диаграмма с накоплением")
    {
        QString selectedColumn = ui->classTypeCombo->currentText();

        int column = AtreeWidget->columnCount();
        int index = -1;
        QHeaderView* header = AtreeWidget->header();

        for (int i = 0; i <column ; i++)
        {
            QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();

            if (justChecking == selectedColumn)
            {
                index = i;
                break;
            }
        }
        column = index;
        if (index == -1) return;

        QMap<QString, QMap<QString, int>> data; // parent -> (category -> count)
        for (int i = 0; i < AtreeWidget->topLevelItemCount(); ++i) {
            QTreeWidgetItem *parentItem = AtreeWidget->topLevelItem(i);
            QString parentName = parentItem->text(0);

            for (int j = 0; j < parentItem->childCount(); ++j) {
                QTreeWidgetItem *childItem = parentItem->child(j);
                QString category = childItem->text(column);
                category = category.simplified();
                if (category.isEmpty()) {
                    category = "Пусто";
                }
                data[parentName][category]++;
            }
        }

        QStringList categories; // X-axis categories
        for (const auto &parentName : data.keys()) {
            for (const auto &category : data[parentName].keys()) {
                if (!categories.contains(category)) {
                    categories << category;
                }
            }
        }

        QString output;
        ui->textEdit->clear();
        for (auto outerIt = data.begin(); outerIt != data.end(); ++outerIt) {
            QString parentKey = outerIt.key();
            output += QString("Сфера: %1\n").arg(parentKey);

            for (auto innerIt = outerIt.value().begin(); innerIt != outerIt.value().end(); ++innerIt) {
                QString childKey = innerIt.key();
                int value = innerIt.value();
                output += QString("    %1: %2\n").arg(childKey).arg(value);
            }

            output += "\n";
        }
        ui->textEdit->append(output);



        QStackedBarSeries *series = new QStackedBarSeries();
        for (const auto &category : categories) {
            QBarSet *barSet = new QBarSet(category);
            for (const auto &parentName : data.keys()) {
                *barSet << data[parentName].value(category, 0); // Default to 0 if category doesn't exist
            }
            series->append(barSet);
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(QString("Столбчатая диаграмма с накоплением для %1").arg(selectedColumn));
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Configure axes
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(data.keys());
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Количество");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Display the chart in the layout
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->ChartPlace->addWidget(chartView);
    }

    if (name == "Круговая диаграмма")
    {
        QString selectedColumn = ui->classTypeCombo->currentText();

        int column = AtreeWidget->columnCount();
        int index = -1;
        QHeaderView* header = AtreeWidget->header();

        for (int i = 0; i <column ; i++)
        {
            QString justChecking = header->model()->headerData(i, Qt::Horizontal).toString();

            if (justChecking == selectedColumn)
            {
                index = i;
                break;
            }
        }
        column = index;
        if (index == -1) return;


        QMap<QString, int> data;
        for (int i = 0; i < AtreeWidget->topLevelItemCount(); ++i) {
            QTreeWidgetItem *parent = AtreeWidget->topLevelItem(i);

            for (int j = 0; j < parent->childCount(); ++j) {
                QTreeWidgetItem *child = parent->child(j);
                QString key = child->text(column);
                key.remove(' ');
                key.remove("\r");
                key.remove("\n");
                data[key]++;
            }
        }

        QString output;
        ui->textEdit->clear();
        for (auto it = data.begin(); it != data.end(); ++it) {
            QString key = it.key();
            int value = it.value();
            output += QString("%1: %2\n").arg(key).arg(value);
        }
        ui->textEdit->append(output);


        QPieSeries *series = new QPieSeries();
        for (auto it = data.begin(); it != data.end(); ++it) {
            series->append(it.key(), it.value());
        }

        auto slices = series->slices();
        for (QPieSlice *slice : slices) {
            slice->setLabel(slice->label() + ": " + QString::number(slice->value()));
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(QString("Круговая диаграмма %1").arg(selectedColumn));
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Enable and align the legend
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignLeft);

        // Изменить легенду к виду "Category: Value"

        const QList<QLegendMarker *> legendMarkers = chart->legend()->markers(series);
        for (int i = 0; i < legendMarkers.size(); ++i) {
            auto marker = legendMarkers.at(i);
            if (marker->type() == QLegendMarker::LegendMarkerTypePie) {
                QString category = slices.at(i)->label().split(":").first();
                QString value = QString::number(slices.at(i)->value());
                marker->setLabel(category + ": " + value);
            }
        }

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->ChartPlace->addWidget(chartView);

    }

}

void CreateChart::on_createChart_clicked()
{
    if (!AtreeWidget)
        return;

    QString chartType = "";
    chartType = ui->chartTypeComboBox->currentText();
    if (chartType != "")
    {
        setupChart(chartType);
    }


}


void CreateChart::on_chartTypeComboBox_currentIndexChanged(int index)
{
    ui->authorCombo->clear();
    ui->authorCombo->addItem("Для всех");
    ui->authorCombo->setCurrentIndex(0);
}


void CreateChart::on_classTypeCombo_currentIndexChanged(int index)
{
    ui->authorCombo->clear();
    ui->authorCombo->addItem("Для всех");
    ui->authorCombo->setCurrentIndex(0);
}

