/********************************************************************************
** Form generated from reading UI file 'createchart.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECHART_H
#define UI_CREATECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateChart
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *additionalSpace;
    QHBoxLayout *ChartPlace;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QComboBox *chartTypeComboBox;
    QComboBox *classTypeCombo;
    QComboBox *authorCombo;
    QTextEdit *textEdit;
    QPushButton *createChart;

    void setupUi(QDialog *CreateChart)
    {
        if (CreateChart->objectName().isEmpty())
            CreateChart->setObjectName("CreateChart");
        CreateChart->resize(960, 480);
        CreateChart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(CreateChart);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        additionalSpace = new QHBoxLayout();
        additionalSpace->setSpacing(0);
        additionalSpace->setObjectName("additionalSpace");
        ChartPlace = new QHBoxLayout();
        ChartPlace->setSpacing(0);
        ChartPlace->setObjectName("ChartPlace");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        ChartPlace->addItem(verticalSpacer);


        additionalSpace->addLayout(ChartPlace);


        horizontalLayout->addLayout(additionalSpace);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout->setContentsMargins(8, -1, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        chartTypeComboBox = new QComboBox(CreateChart);
        chartTypeComboBox->setObjectName("chartTypeComboBox");
        chartTypeComboBox->setMinimumSize(QSize(60, 0));

        verticalLayout_2->addWidget(chartTypeComboBox);

        classTypeCombo = new QComboBox(CreateChart);
        classTypeCombo->setObjectName("classTypeCombo");

        verticalLayout_2->addWidget(classTypeCombo);

        authorCombo = new QComboBox(CreateChart);
        authorCombo->setObjectName("authorCombo");

        verticalLayout_2->addWidget(authorCombo);

        textEdit = new QTextEdit(CreateChart);
        textEdit->setObjectName("textEdit");

        verticalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(verticalLayout_2);

        createChart = new QPushButton(CreateChart);
        createChart->setObjectName("createChart");

        verticalLayout->addWidget(createChart);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(CreateChart);

        QMetaObject::connectSlotsByName(CreateChart);
    } // setupUi

    void retranslateUi(QDialog *CreateChart)
    {
        CreateChart->setWindowTitle(QCoreApplication::translate("CreateChart", "\320\236\320\272\320\275\320\276 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270", nullptr));
        chartTypeComboBox->setPlaceholderText(QCoreApplication::translate("CreateChart", " \320\242\320\270\320\277 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\274\321\213..", nullptr));
        classTypeCombo->setPlaceholderText(QCoreApplication::translate("CreateChart", " \320\232\320\276\320\273\320\276\320\275\320\260...", nullptr));
        authorCombo->setPlaceholderText(QCoreApplication::translate("CreateChart", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205", nullptr));
        createChart->setText(QCoreApplication::translate("CreateChart", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateChart: public Ui_CreateChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECHART_H
