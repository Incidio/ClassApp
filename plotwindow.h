#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include "mainwindow.h"
/*
class PlotWindow
{
public:
    PlotWindow();
};
*/

namespace Ui {
    class BarChartWindow;
}

class BarChartWindow : public QDialog {
    Q_OBJECT
public:
    explicit BarChartWindow( QWidget *parent = nullptr);
    ~BarChartWindow();
public:
    void create();
private:
    Ui::BarChartWindow *ui;
};



#endif // PLOTWINDOW_H
