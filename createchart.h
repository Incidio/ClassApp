#ifndef CREATECHART_H
#define CREATECHART_H

#include <QDialog>

#include <QMainWindow>
#include <QHeaderView>
#include <QTextEdit>
#include <QListWidget>
#include <QMenu>
#include <QToolButton>
#include <QFrame>
#include <QTreeWidget>

//#include <QtCharts>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QtCharts/QPieSeries>
#include <QStackedBarSeries>

#include <QtCharts/QLegend>
#include <QtCharts/QLegendMarker>

namespace Ui {
class CreateChart;
}

class CreateChart : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChart(QWidget *parent = nullptr);
    ~CreateChart();

    void setTreeWidget(QTreeWidget *tree);
    void setupChart(QString chartType);
    bool columnWithNameExists(QTreeWidget *treeWidget, const QString &columnName);

private slots:
    void on_createChart_clicked();

    void on_chartTypeComboBox_currentIndexChanged(int index);

    void on_classTypeCombo_currentIndexChanged(int index);

private:
    Ui::CreateChart *ui;
    QTreeWidget *AtreeWidget;

};

#endif // CREATECHART_H
