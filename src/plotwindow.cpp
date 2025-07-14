#include "plotwindow.h"

BarChartWindow::BarCharWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::BarChartWindow)
{
    ui->setupUi(this);
}
void BarChartWindow::create()
{


    setWindowTitle("Bar Chart");
    QBarSeries *series = new QBarSeries();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Изменение ? за период времени");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    // Create a QBarSeries

    // Create bars and add them to the series



    QBarSet *set1 = new QBarSet("Период 1");

    set1->append(55);
    set1->append(80);
    set1->append(90);
    set1->append(70);
    set1->append(65);

    QBarSet *set2 = new QBarSet("Период 2");

    set2->append(10);
    set2->append(20);
    set2->append(30);
    set2->append(40);
    set2->append(60);

    QBarSet *set3 = new QBarSet("Период 3");

    set3->append(60);
    set3->append(80);
    set3->append(20);
    set3->append(30);
    set1->append(60);


    series->append(set1);
    //series->append(set2);
    //series->append(set3);
    ////////////////////////////////

    // Create a chart


    QStringList Subjects;
    Subjects.append("Сфера Охраны окружающей среды");
    Subjects.append("Сфера соблюдения прав и свобод человека");
    Subjects.append("Сфера Экономики");
    Subjects.append("Сфера 4");
    Subjects.append("Сфера 5");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjects);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY= new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);
    //setCentralWidget(chartview);

    // Setup the layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartview);
    setLayout(layout);
    resize(800, 600);

}

