#include "progressdialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Выполнение сортировки");

    QVBoxLayout *layout = new QVBoxLayout(this);

    messageLabel = new QLabel(this);
    layout->addWidget(messageLabel);

    progressBar = new QProgressBar(this);
    layout->addWidget(progressBar);

    //QPushButton *closeButton = new QPushButton("Завершить преждевременно", this);
    //layout->addWidget(closeButton);

    //connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
}
ProgressDialog::~ProgressDialog()
{
    delete progressBar;
    delete messageLabel;
    delete pd;
    delete t;
}
void ProgressDialog::setLength(int number)
{
    progressBar->setRange(0, number);
}
void ProgressDialog::setProgress(int value)
{
    progressBar->setValue(value);
}
void ProgressDialog::setMessage(const QString &message)
{
    messageLabel->setText(message);
}
