#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include <QTreeWidget>
#include <QHeaderView>
#include <QTextEdit>
#include <QListWidget>
#include <QThread>
#include <QDesktopServices>
#include <QUrl>
#include <QMenu>
#include <QToolButton>
#include <QFrame>
#include <QtCharts>

class BarChartWidget : public QWidget {
    Q_OBJECT

public:
    explicit BarChartWidget(QWidget *parent = nullptr);

    void setupChart(const std::map<QString, int>& data);
};

#endif // BARCHARTWIDGET_H
