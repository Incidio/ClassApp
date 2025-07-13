#pragma once

#ifndef CREATECHART_H
#define CREATECHART_H

#include <QDialog>
#include <QTreeWidget>
#include <QMap>
#include <QPair>
#include <QChartView>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class CreateChart;
}
QT_END_NAMESPACE

class CreateChart : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChart(QWidget *parent = nullptr);
    ~CreateChart();

    // Привязка внешнего дерева с данными
    void setTreeWidget(QTreeWidget *tree);

private slots:
    // Обработка выбора типа диаграммы (столбчатая, круговая и т.п.)
    void on_chartTypeComboBox_currentIndexChanged(int index);
    void on_createChart_clicked();

    // Обновление фильтра при смене столбцов
    void on_firstColumnComboBox_currentIndexChanged(int index);
    void on_secondColumnComboBox_currentIndexChanged(int index);

private:
    Ui::CreateChart *ui;

    // Входное дерево с данными
    QTreeWidget *AtreeWidget = nullptr;

    // Обработка построения диаграммы
    void setupChart(const QString &chartType);

    // Проверка существования колонки по имени
    bool columnWithNameExists(const QString &columnName) const;

    // Получение индекса колонки по имени
    int getColumnIndexByName(const QString &columnName) const;

    // Очистка лэйаута
    void clearLayout(QLayout *layout, bool deleteWidgets = true);

    // Сбор данных: группировка по (X, Y) с учётом родителя
    QMap<QString, QMap<QString, QMap<QString, int>>> collectGroupedData(
        const QString &xColumn, const QString &yColumn, const QString &filterValue = "Для всех"
        ) const;

    // Обновление доступных колонок при запуске
    void populateColumnSelectors();

    // Обновление комбобокса фильтров
    void updateFilterValues(const QString &columnName);

    // Унификация данных по категориям
    void ensureAllYValuesPresent(QMap<QString, QMap<QString, QMap<QString, int>>> &data);
};


#endif // CREATECHART_H
