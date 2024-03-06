/********************************************************************************
** Form generated from reading UI file 'assemblage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSEMBLAGE_H
#define UI_ASSEMBLAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Assemblage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *choosenPage;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileSelectButton;
    QLineEdit *pathSelected;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AnnulerButton;
    QPushButton *AssemblerButton;

    void setupUi(QDialog *Assemblage)
    {
        if (Assemblage->objectName().isEmpty())
            Assemblage->setObjectName(QString::fromUtf8("Assemblage"));
        Assemblage->resize(360, 223);
        verticalLayout = new QVBoxLayout(Assemblage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Assemblage);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat"));
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        choosenPage = new QLineEdit(Assemblage);
        choosenPage->setObjectName(QString::fromUtf8("choosenPage"));

        verticalLayout->addWidget(choosenPage);

        label_2 = new QLabel(Assemblage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fileSelectButton = new QPushButton(Assemblage);
        fileSelectButton->setObjectName(QString::fromUtf8("fileSelectButton"));
        sizePolicy.setHeightForWidth(fileSelectButton->sizePolicy().hasHeightForWidth());
        fileSelectButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(fileSelectButton);


        verticalLayout->addLayout(horizontalLayout);

        pathSelected = new QLineEdit(Assemblage);
        pathSelected->setObjectName(QString::fromUtf8("pathSelected"));

        verticalLayout->addWidget(pathSelected);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        AnnulerButton = new QPushButton(Assemblage);
        AnnulerButton->setObjectName(QString::fromUtf8("AnnulerButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat"));
        font1.setBold(true);
        AnnulerButton->setFont(font1);

        horizontalLayout_2->addWidget(AnnulerButton);

        AssemblerButton = new QPushButton(Assemblage);
        AssemblerButton->setObjectName(QString::fromUtf8("AssemblerButton"));
        AssemblerButton->setFont(font1);

        horizontalLayout_2->addWidget(AssemblerButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Assemblage);

        QMetaObject::connectSlotsByName(Assemblage);
    } // setupUi

    void retranslateUi(QDialog *Assemblage)
    {
        Assemblage->setWindowTitle(QCoreApplication::translate("Assemblage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Assemblage", "Pages \303\240 assembler :", nullptr));
        label_2->setText(QCoreApplication::translate("Assemblage", "Lieu d'archivage  : ", nullptr));
        fileSelectButton->setText(QCoreApplication::translate("Assemblage", "...", nullptr));
        AnnulerButton->setText(QCoreApplication::translate("Assemblage", "Annuler", nullptr));
        AssemblerButton->setText(QCoreApplication::translate("Assemblage", "Assembler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assemblage: public Ui_Assemblage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSEMBLAGE_H
