/********************************************************************************
** Form generated from reading UI file 'combinewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBINEWINDOW_H
#define UI_COMBINEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CombineWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *choosenPage;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *pathSelected;
    QPushButton *fileSelectButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CancelButton;
    QPushButton *OkButton;

    void setupUi(QDialog *CombineWindow)
    {
        if (CombineWindow->objectName().isEmpty())
            CombineWindow->setObjectName(QString::fromUtf8("CombineWindow"));
        CombineWindow->resize(360, 223);
        verticalLayout = new QVBoxLayout(CombineWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CombineWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        choosenPage = new QLineEdit(CombineWindow);
        choosenPage->setObjectName(QString::fromUtf8("choosenPage"));

        verticalLayout->addWidget(choosenPage);

        label_2 = new QLabel(CombineWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pathSelected = new QLineEdit(CombineWindow);
        pathSelected->setObjectName(QString::fromUtf8("pathSelected"));

        horizontalLayout->addWidget(pathSelected);

        fileSelectButton = new QPushButton(CombineWindow);
        fileSelectButton->setObjectName(QString::fromUtf8("fileSelectButton"));

        horizontalLayout->addWidget(fileSelectButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CancelButton = new QPushButton(CombineWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);

        OkButton = new QPushButton(CombineWindow);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));

        horizontalLayout_2->addWidget(OkButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CombineWindow);

        QMetaObject::connectSlotsByName(CombineWindow);
    } // setupUi

    void retranslateUi(QDialog *CombineWindow)
    {
        CombineWindow->setWindowTitle(QCoreApplication::translate("CombineWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CombineWindow", "Pages (separated with - or ,)", nullptr));
        label_2->setText(QCoreApplication::translate("CombineWindow", "Path", nullptr));
        fileSelectButton->setText(QCoreApplication::translate("CombineWindow", "...", nullptr));
        CancelButton->setText(QCoreApplication::translate("CombineWindow", "Cancel", nullptr));
        OkButton->setText(QCoreApplication::translate("CombineWindow", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CombineWindow: public Ui_CombineWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBINEWINDOW_H
