#include "barchartwidget.h"

BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent) {
}
void BarChartWidget::setupChart(const std::map<QString, int>& data){

    std::map<QString, int> mp = data;
    QChartView *chartView = new QChartView();
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    QBarSet *set = new QBarSet("Данные");

    for (const auto& item : mp) {
        *set << item.second; // insert the values into the bar set
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Bar Chart с авторами");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (const auto& item : mp) {
        categories << item.first;
    }

    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);
    //setCentralWidget(chartview);

    // Setup the layout
    setLayout(layout);

}
