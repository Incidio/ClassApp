#ifndef READCONTENTS_H
#define READCONTENTS_H

#include <QDialog>

namespace Ui {
class ReadContents;
}

class ReadContents : public QDialog
{
    Q_OBJECT

public:
    explicit ReadContents(QWidget *parent = nullptr);

    ~ReadContents();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие


private slots:
    void on_pushButton_clicked();

private:
    Ui::ReadContents *ui;
};

#endif // READCONTENTS_H
