#pragma once

#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include "mainwindow.h"

class ProgressDialog : public QDialog {
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr);
    ~ProgressDialog();
    void setProgress(int value);
    void setMessage(const QString &message);
    void setLength(int number);

private:
    QProgressBar *progressBar;
    QLabel *messageLabel;
    QProgressDialog *pd;
    QTimer *t;
    int steps;

};

#endif // PROGRESSDIALOG_H
