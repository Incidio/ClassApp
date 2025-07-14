#pragma once

#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>
#include <QFile>
#include <QPdfDocument>

#include<string>

#include "3rdparty/duckx/include/duckx.hpp"

class service
{
private:

public:
    QStringList lawBook;
    QStringList orgsBook;

    int check=0;
    struct custom
    {
        QString URL;
        std::vector<int> lawBookNumber; // {0, 1 , 2 , ...} - показывает сколько законов для каждой группы, для разделения
    };
    std::vector<custom> files;
    service();
    ~service();
    QString Check_contents(const QString& path);

    int checkFileExtension(const QString& filePath);
    QStringList FullFile(const QString& filePath);

};

#endif // SERVICE_H
