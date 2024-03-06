/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionAssembler;
    QAction *actionAbout;
    QAction *actionRaw;
    QAction *actionText_focused;
    QAction *actionDrawing_focused;
    QAction *actionSimplePage;
    QAction *actionDoublePage;
    QAction *actionBookmark;
    QAction *actionGotobookmark;
    QAction *actionRedimVertical;
    QAction *actionRedimHorizontal;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *totalPageDisplay;
    QLabel *page_Bookmark;
    QPushButton *ZoomOut;
    QPushButton *previousPage;
    QListWidget *Infos;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *screen;
    QPushButton *ZoomIn;
    QPushButton *firstPage;
    QLineEdit *currPageDisplay;
    QPushButton *lastPage;
    QLabel *Last_Bookmark;
    QPushButton *nextPage;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAffichage;
    QMenu *menuRedimensionnement;
    QMenu *menuBookmark;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1150, 656);
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setFont(font);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setFont(font);
        actionAssembler = new QAction(MainWindow);
        actionAssembler->setObjectName(QString::fromUtf8("actionAssembler"));
        actionAssembler->setFont(font);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRaw = new QAction(MainWindow);
        actionRaw->setObjectName(QString::fromUtf8("actionRaw"));
        actionText_focused = new QAction(MainWindow);
        actionText_focused->setObjectName(QString::fromUtf8("actionText_focused"));
        actionDrawing_focused = new QAction(MainWindow);
        actionDrawing_focused->setObjectName(QString::fromUtf8("actionDrawing_focused"));
        actionSimplePage = new QAction(MainWindow);
        actionSimplePage->setObjectName(QString::fromUtf8("actionSimplePage"));
        actionSimplePage->setFont(font);
        actionDoublePage = new QAction(MainWindow);
        actionDoublePage->setObjectName(QString::fromUtf8("actionDoublePage"));
        actionBookmark = new QAction(MainWindow);
        actionBookmark->setObjectName(QString::fromUtf8("actionBookmark"));
        actionBookmark->setFont(font);
        actionGotobookmark = new QAction(MainWindow);
        actionGotobookmark->setObjectName(QString::fromUtf8("actionGotobookmark"));
        actionGotobookmark->setFont(font);
        actionRedimVertical = new QAction(MainWindow);
        actionRedimVertical->setObjectName(QString::fromUtf8("actionRedimVertical"));
        actionRedimVertical->setFont(font);
        actionRedimHorizontal = new QAction(MainWindow);
        actionRedimHorizontal->setObjectName(QString::fromUtf8("actionRedimHorizontal"));
        actionRedimHorizontal->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        totalPageDisplay = new QLabel(centralWidget);
        totalPageDisplay->setObjectName(QString::fromUtf8("totalPageDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(totalPageDisplay->sizePolicy().hasHeightForWidth());
        totalPageDisplay->setSizePolicy(sizePolicy1);
        totalPageDisplay->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(totalPageDisplay, 5, 7, 1, 1);

        page_Bookmark = new QLabel(centralWidget);
        page_Bookmark->setObjectName(QString::fromUtf8("page_Bookmark"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(page_Bookmark->sizePolicy().hasHeightForWidth());
        page_Bookmark->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat"));
        font1.setBold(true);
        font1.setItalic(true);
        page_Bookmark->setFont(font1);

        gridLayout_2->addWidget(page_Bookmark, 0, 4, 1, 1);

        ZoomOut = new QPushButton(centralWidget);
        ZoomOut->setObjectName(QString::fromUtf8("ZoomOut"));

        gridLayout_2->addWidget(ZoomOut, 5, 1, 1, 1);

        previousPage = new QPushButton(centralWidget);
        previousPage->setObjectName(QString::fromUtf8("previousPage"));
        sizePolicy2.setHeightForWidth(previousPage->sizePolicy().hasHeightForWidth());
        previousPage->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Montserrat"));
        font2.setPointSize(10);
        font2.setBold(true);
        previousPage->setFont(font2);

        gridLayout_2->addWidget(previousPage, 5, 3, 1, 1);

        Infos = new QListWidget(centralWidget);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Montserrat"));
        font3.setBold(true);
        font3.setUnderline(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(Infos);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font3);
        Infos->setObjectName(QString::fromUtf8("Infos"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Infos->sizePolicy().hasHeightForWidth());
        Infos->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(Infos, 1, 9, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(427, 275, 16, 16));
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        screen = new QLabel(scrollAreaWidgetContents);
        screen->setObjectName(QString::fromUtf8("screen"));
        sizePolicy2.setHeightForWidth(screen->sizePolicy().hasHeightForWidth());
        screen->setSizePolicy(sizePolicy2);
        screen->setMinimumSize(QSize(0, 0));
        screen->setFrameShape(QFrame::NoFrame);
        screen->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(screen, 6, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 4, 8);

        ZoomIn = new QPushButton(centralWidget);
        ZoomIn->setObjectName(QString::fromUtf8("ZoomIn"));

        gridLayout_2->addWidget(ZoomIn, 5, 0, 1, 1);

        firstPage = new QPushButton(centralWidget);
        firstPage->setObjectName(QString::fromUtf8("firstPage"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(firstPage->sizePolicy().hasHeightForWidth());
        firstPage->setSizePolicy(sizePolicy5);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Montserrat"));
        font4.setPointSize(8);
        font4.setBold(true);
        firstPage->setFont(font4);

        gridLayout_2->addWidget(firstPage, 5, 2, 1, 1);

        currPageDisplay = new QLineEdit(centralWidget);
        currPageDisplay->setObjectName(QString::fromUtf8("currPageDisplay"));
        sizePolicy2.setHeightForWidth(currPageDisplay->sizePolicy().hasHeightForWidth());
        currPageDisplay->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Montserrat"));
        font5.setBold(true);
        currPageDisplay->setFont(font5);
        currPageDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(currPageDisplay, 5, 6, 1, 1);

        lastPage = new QPushButton(centralWidget);
        lastPage->setObjectName(QString::fromUtf8("lastPage"));
        sizePolicy5.setHeightForWidth(lastPage->sizePolicy().hasHeightForWidth());
        lastPage->setSizePolicy(sizePolicy5);
        lastPage->setFont(font4);

        gridLayout_2->addWidget(lastPage, 5, 5, 1, 1);

        Last_Bookmark = new QLabel(centralWidget);
        Last_Bookmark->setObjectName(QString::fromUtf8("Last_Bookmark"));
        sizePolicy2.setHeightForWidth(Last_Bookmark->sizePolicy().hasHeightForWidth());
        Last_Bookmark->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Montserrat"));
        font6.setUnderline(true);
        Last_Bookmark->setFont(font6);

        gridLayout_2->addWidget(Last_Bookmark, 0, 3, 1, 1);

        nextPage = new QPushButton(centralWidget);
        nextPage->setObjectName(QString::fromUtf8("nextPage"));
        sizePolicy2.setHeightForWidth(nextPage->sizePolicy().hasHeightForWidth());
        nextPage->setSizePolicy(sizePolicy2);
        nextPage->setFont(font2);

        gridLayout_2->addWidget(nextPage, 5, 4, 1, 1);

        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Table des mati\303\250res"));
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font3);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(treeWidget, 2, 9, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1150, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuRedimensionnement = new QMenu(menuAffichage);
        menuRedimensionnement->setObjectName(QString::fromUtf8("menuRedimensionnement"));
        menuRedimensionnement->setFont(font);
        menuBookmark = new QMenu(menuBar);
        menuBookmark->setObjectName(QString::fromUtf8("menuBookmark"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuBookmark->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionAssembler);
        menuFile->addSeparator();
        menuFile->addAction(actionAbout);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuAffichage->addAction(actionSimplePage);
        menuAffichage->addAction(actionDoublePage);
        menuAffichage->addAction(menuRedimensionnement->menuAction());
        menuRedimensionnement->addAction(actionRedimVertical);
        menuRedimensionnement->addAction(actionRedimHorizontal);
        menuBookmark->addAction(actionBookmark);
        menuBookmark->addAction(actionGotobookmark);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Ouvrir", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        actionAssembler->setText(QCoreApplication::translate("MainWindow", "Assembler", nullptr));
#if QT_CONFIG(shortcut)
        actionAssembler->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "A propos de Qt", nullptr));
        actionRaw->setText(QCoreApplication::translate("MainWindow", "Raw", nullptr));
        actionText_focused->setText(QCoreApplication::translate("MainWindow", "Text focused", nullptr));
        actionDrawing_focused->setText(QCoreApplication::translate("MainWindow", "Drawing focused", nullptr));
        actionSimplePage->setText(QCoreApplication::translate("MainWindow", "Simple page", nullptr));
        actionDoublePage->setText(QCoreApplication::translate("MainWindow", "Double page", nullptr));
        actionBookmark->setText(QCoreApplication::translate("MainWindow", "Marquer la page", nullptr));
        actionGotobookmark->setText(QCoreApplication::translate("MainWindow", "Aller au dernier marque-page", nullptr));
        actionRedimVertical->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        actionRedimHorizontal->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        totalPageDisplay->setText(QString());
        page_Bookmark->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        previousPage->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        previousPage->setText(QCoreApplication::translate("MainWindow", "<", nullptr));

        const bool __sortingEnabled = Infos->isSortingEnabled();
        Infos->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = Infos->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Informations", nullptr));
        Infos->setSortingEnabled(__sortingEnabled);

        screen->setText(QString());
        ZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
        firstPage->setText(QCoreApplication::translate("MainWindow", "Premi\303\250re page", nullptr));
        lastPage->setText(QCoreApplication::translate("MainWindow", "Derni\303\250re Page", nullptr));
        Last_Bookmark->setText(QCoreApplication::translate("MainWindow", "Last Bookmark :", nullptr));
        nextPage->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        menuRedimensionnement->setTitle(QCoreApplication::translate("MainWindow", "Redimensionnement", nullptr));
        menuBookmark->setTitle(QCoreApplication::translate("MainWindow", "Bookmark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
