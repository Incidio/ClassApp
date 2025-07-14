#include "createchart.h"
#include "ui_createchart.h"

#include <QtCharts>
#include <QComboBox>


CreateChart::CreateChart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateChart)
{
    ui->setupUi(this);
    setWindowTitle("Анализ данных");

    ui->chartTypeComboBox->addItems({
        "Столбчатая диаграмма",
        "Столбчатая диаграмма с накоплением",
        "Круговая диаграмма"
    });

    ui->authorCombo->addItem("Для всех");
    ui->authorCombo->setCurrentIndex(0);
}

CreateChart::~CreateChart()
{
    delete ui;
}

void CreateChart::setTreeWidget(QTreeWidget *tree)
{
    AtreeWidget = tree;
    populateColumnSelectors();
}

void CreateChart::populateColumnSelectors()
{
    if (!AtreeWidget) return;

    ui->firstColumnComboBox->clear();
    ui->secondColumnComboBox->clear();

    QTreeWidgetItem *header = AtreeWidget->headerItem();
    int columnCount = AtreeWidget->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        QString name = header->text(i);
        ui->firstColumnComboBox->addItem(name);
        ui->secondColumnComboBox->addItem(name);
    }
    ui->authorCombo->clear();
    ui->authorCombo->addItem("Для всех");
}

bool CreateChart::columnWithNameExists(const QString &columnName) const
{
    QTreeWidgetItem *header = AtreeWidget->headerItem();
    if (!header) return false;

    for (int i = 0; i < AtreeWidget->columnCount(); ++i) {
        if (header->text(i) == columnName) {
            return true;
        }
    }
    return false;
}

int CreateChart::getColumnIndexByName(const QString &columnName) const
{
    QTreeWidgetItem *header = AtreeWidget->headerItem();
    for (int i = 0; i < AtreeWidget->columnCount(); ++i) {
        if (header->text(i) == columnName) {
            return i;
        }
    }
    return -1;
}

void CreateChart::clearLayout(QLayout *layout, bool deleteWidgets)
{
    while (QLayoutItem *item = layout->takeAt(0)) {
        if (deleteWidgets && item->widget())
            item->widget()->deleteLater();
        if (item->layout())
            clearLayout(item->layout(), deleteWidgets);
        delete item;
    }
}

QMap<QString, QMap<QString, QMap<QString, int>>> CreateChart::collectGroupedData(
    const QString &xColumn, const QString &yColumn, const QString &filterValue) const
{
    QMap<QString, QMap<QString, QMap<QString, int>>> data;
    int xIndex = getColumnIndexByName(xColumn);
    int yIndex = getColumnIndexByName(yColumn);
    if (xIndex == -1 || yIndex == -1) return data;

    for (int i = 0; i < AtreeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem *parent = AtreeWidget->topLevelItem(i);
        QString sphere = parent->text(0);

        for (int j = 0; j < parent->childCount(); ++j) {
            QTreeWidgetItem *child = parent->child(j);
            QString xValue = child->text(xIndex).simplified();
            QString yValue = child->text(yIndex).simplified();

            if (xValue.isEmpty()) xValue = "Пусто";
            if (yValue.isEmpty()) yValue = "Пусто";

            if (filterValue == "Для всех" || xValue == filterValue || yValue == filterValue) {
                data[sphere][xValue][yValue]++;
            }
        }
    }
    return data;
}

void CreateChart::ensureAllYValuesPresent(QMap<QString, QMap<QString, QMap<QString, int>>> &data)
{
    QSet<QString> allY;
    for (const auto &sphere : data.keys()) {
        for (const auto &x : data[sphere].keys()) {
            const auto &yKeys = data[sphere][x].keys();
            allY.unite(QSet<QString>(yKeys.begin(), yKeys.end()));
        }
    }
    for (auto &sphereData : data) {
        for (auto &xData : sphereData) {
            for (const auto &yVal : allY) {
                if (!xData.contains(yVal))
                    xData[yVal] = 0;
            }
        }
    }
}

void CreateChart::on_chartTypeComboBox_currentIndexChanged(int index)
{
    ui->authorCombo->clear();
    ui->authorCombo->addItem("Для всех");
}

void CreateChart::on_firstColumnComboBox_currentIndexChanged(int index)
{
    updateFilterValues(ui->firstColumnComboBox->currentText());
}

void CreateChart::on_secondColumnComboBox_currentIndexChanged(int index)
{
    updateFilterValues(ui->secondColumnComboBox->currentText());
}

void CreateChart::updateFilterValues(const QString &columnName)
{
    int columnIndex = getColumnIndexByName(columnName);
    if (columnIndex == -1) return;

    QSet<QString> uniqueValues;
    for (int i = 0; i < AtreeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem *parent = AtreeWidget->topLevelItem(i);
        for (int j = 0; j < parent->childCount(); ++j) {
            QString val = parent->child(j)->text(columnIndex).simplified();
            if (!val.isEmpty()) uniqueValues.insert(val);
        }
    }

    ui->authorCombo->clear();
    ui->authorCombo->addItem("Для всех");
    for (const QString &val : uniqueValues)
        ui->authorCombo->addItem(val);
}

void CreateChart::on_createChart_clicked()
{
    if (!AtreeWidget) return;

    QString chartType = ui->chartTypeComboBox->currentText();
    setupChart(chartType);
}

void CreateChart::setupChart(const QString &chartType)
{
    //clearLayout(ui->ChartPlace);

    QString xColumn = ui->firstColumnComboBox->currentText();
    QString yColumn = ui->secondColumnComboBox->currentText();
    QString filter = ui->authorCombo->currentText();

    auto data = collectGroupedData(xColumn, yColumn, filter);
    ensureAllYValuesPresent(data);

    if (chartType == "Столбчатая диаграмма") {
        QChart *chart = new QChart();
        chart->setTitle(QString("%1 по %2 (фильтр: %3)").arg(yColumn, xColumn, filter));
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarSeries *series = new QBarSeries();
        QSet<QString> allX;

        for (const auto &sphere : data.keys()) {
            QBarSet *barSet = new QBarSet(sphere);
            for (const auto &x : data[sphere].keys()) {
                int sum = 0;
                for (const auto &y : data[sphere][x].keys()) {
                    sum += data[sphere][x][y];
                }
                *barSet << sum;
                allX.insert(x);
            }
            series->append(barSet);
        }

        chart->addSeries(series);  // Важно: ДО добавления осей и attachAxis

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(QStringList(allX.begin(), allX.end()));
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Количество");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->ChartPlace->addWidget(chartView);
    }

    // Здесь можно добавить другие типы графиков при необходимости
}
