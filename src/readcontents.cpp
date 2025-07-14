#include "readcontents.h"
#include "ui_readcontents.h"
#include "service.h"

ReadContents::ReadContents(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReadContents)
{
    ui->setupUi(this);

}

ReadContents::~ReadContents()
{
    delete ui;
}


void ReadContents::on_pushButton_clicked()
{
    this->close();
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

