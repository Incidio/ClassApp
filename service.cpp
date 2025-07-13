#include "service.h"
#include <string>
#include <vector>

/////////////////////////////////////////////////////////
/////////////////Работа с поиском по тексту//////////////
/////////////////////////////////////////////////////////
///
///
//    qDebug() << files[i].URL;

service::service()
{

}

service::~service(){}

std::string ReplaceString(std::string subject,
                          const std::string& search,
                          const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}


QString service::Check_contents(const QString &path)
{
    files.push_back(custom());
    int n = files.size() - 1 ;
    files[n].URL = path;
    QString answer = " ";
    return answer;
}

int service::checkFileExtension(const QString& filePath)
{
    int a=0;
    if (filePath.endsWith(".txt", Qt::CaseInsensitive))
        a=1;
    if (filePath.endsWith(".docx", Qt::CaseInsensitive))
        a=2;
    if (filePath.endsWith(".pdf", Qt::CaseInsensitive))
        a=3;
    return a;
}

QStringList service::FullFile(const QString& filePath)
{
    int extension = service::checkFileExtension(filePath);
    QStringList temp;
    switch (extension)
    {

    case 1: // это .txt файл
    {
        QFile inputFile(filePath);

        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            while (!in.atEnd())
            {
                QString lineToCheckForLaws = in.readLine();

                QString input = lineToCheckForLaws;
                input.replace("\"", "\'");
                input.replace("«", "\'");
                input.replace("»", "\'");


                temp.append(input);


                int start = 0 ;

                while ((start = input.indexOf("'", start)) != -1)
                {
                    int end = input.indexOf("'", start + 1);
                    if (end == -1)
                    {
                        break; // No closing apostrophe found
                    }
                    QString chunk = input.mid(start + 1, end - start - 1); // Extract the chunk
                    chunk.replace("\r", "");
                    chunk.replace("\n", " ");
                    temp.append(chunk); // Print the extracted chunk
                    start = end + 1; // Move past the closing apostrophe
                }

            }
            inputFile.close();
        }
    }
    case 2: // это .docx файл
    {
        std::string stdpath = filePath.toLocal8Bit().constData();
        duckx::Document doc(stdpath);

        doc.open();

        for (auto p : doc.paragraphs())
            for (auto r : p.runs())
            {
                std::string str = r.get_text();
                QString input = QString::fromStdString(str);
                input.replace("\"", "\'");
                input.replace("«", "\'");
                input.replace("»", "\'");

                temp.append(input);


                int start = 0 ;

                while ((start = input.indexOf("'", start)) != -1)
                {
                    int end = input.indexOf("'", start + 1);
                    if (end == -1)
                    {
                        break; // No closing apostrophe found
                    }
                    QString chunk = input.mid(start + 1, end - start - 1); // Extract the chunk
                    chunk.replace("\r", "");
                    chunk.replace("\n", " ");
                    temp.append(chunk); // Print the extracted chunk
                    start = end + 1; // Move past the closing apostrophe

                }

            }
    }
    case 3: // это .pdf файл
    {

        QPdfDocument *document = new QPdfDocument;
        document->load(filePath);

        QString selectedText;
        for (int i=0; i<document->pageCount(); i++)
        {
            //ssw->append("current page is : " + QString::number(i));

            selectedText = document->getAllText(i).text();
            //ui->textEdit->append(selectedText);
            QString input = selectedText;
            input.replace("\"", "\'");
            input.replace("«", "\'");
            input.replace("»", "\'");

            int start = 0 ;

            while ((start = input.indexOf("'", start)) != -1)
            {
                int end = input.indexOf("'", start + 1);
                if (end == -1)
                {
                    break; // No closing apostrophe found
                }
                QString chunk = input.mid(start + 1, end - start - 1); // Extract the chunk
                chunk.replace("\r", "");
                chunk.replace("\n", " ");
                temp.append(chunk); // Print the extracted chunk
                start = end + 1; // Move past the closing apostrophe
            }
        }


    }
    }

    return temp;
}
