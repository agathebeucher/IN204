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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionCombine;
    QAction *actionAbout;
    QAction *actionSingle_Page;
    QAction *actionRaw;
    QAction *actionText_focused;
    QAction *actionDrawing_focused;
    QAction *actionCover_page;
    QAction *actionNo_cover_page;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Bookmark;
    QPushButton *Gotobookmark;
    QLabel *Last_Bookmark;
    QLabel *page_Bookmark;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *screen;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ZoomIn;
    QPushButton *ZoomOut;
    QPushButton *firstPage;
    QPushButton *previousPage;
    QPushButton *nextPage;
    QPushButton *lastPage;
    QLineEdit *currPageDisplay;
    QLabel *totalPageDisplay;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOption;
    QMenu *menuDisplay_Mode;
    QMenu *menuDouble_page;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(940, 656);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionCombine = new QAction(MainWindow);
        actionCombine->setObjectName(QString::fromUtf8("actionCombine"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSingle_Page = new QAction(MainWindow);
        actionSingle_Page->setObjectName(QString::fromUtf8("actionSingle_Page"));
        actionRaw = new QAction(MainWindow);
        actionRaw->setObjectName(QString::fromUtf8("actionRaw"));
        actionText_focused = new QAction(MainWindow);
        actionText_focused->setObjectName(QString::fromUtf8("actionText_focused"));
        actionDrawing_focused = new QAction(MainWindow);
        actionDrawing_focused->setObjectName(QString::fromUtf8("actionDrawing_focused"));
        actionCover_page = new QAction(MainWindow);
        actionCover_page->setObjectName(QString::fromUtf8("actionCover_page"));
        actionNo_cover_page = new QAction(MainWindow);
        actionNo_cover_page->setObjectName(QString::fromUtf8("actionNo_cover_page"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Bookmark = new QPushButton(centralWidget);
        Bookmark->setObjectName(QString::fromUtf8("Bookmark"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Bookmark->sizePolicy().hasHeightForWidth());
        Bookmark->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat"));
        Bookmark->setFont(font);
        Bookmark->setLayoutDirection(Qt::LeftToRight);
        Bookmark->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(Bookmark);

        Gotobookmark = new QPushButton(centralWidget);
        Gotobookmark->setObjectName(QString::fromUtf8("Gotobookmark"));
        sizePolicy1.setHeightForWidth(Gotobookmark->sizePolicy().hasHeightForWidth());
        Gotobookmark->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Montserrat"));
        font1.setBold(true);
        Gotobookmark->setFont(font1);

        verticalLayout->addWidget(Gotobookmark);

        Last_Bookmark = new QLabel(centralWidget);
        Last_Bookmark->setObjectName(QString::fromUtf8("Last_Bookmark"));
        sizePolicy1.setHeightForWidth(Last_Bookmark->sizePolicy().hasHeightForWidth());
        Last_Bookmark->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Montserrat"));
        font2.setUnderline(true);
        Last_Bookmark->setFont(font2);

        verticalLayout->addWidget(Last_Bookmark, 0, Qt::AlignHCenter);

        page_Bookmark = new QLabel(centralWidget);
        page_Bookmark->setObjectName(QString::fromUtf8("page_Bookmark"));
        sizePolicy1.setHeightForWidth(page_Bookmark->sizePolicy().hasHeightForWidth());
        page_Bookmark->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Montserrat"));
        font3.setBold(true);
        font3.setItalic(true);
        page_Bookmark->setFont(font3);

        verticalLayout->addWidget(page_Bookmark, 0, Qt::AlignHCenter);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(453, 119, 16, 16));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        screen = new QLabel(scrollAreaWidgetContents);
        screen->setObjectName(QString::fromUtf8("screen"));
        sizePolicy1.setHeightForWidth(screen->sizePolicy().hasHeightForWidth());
        screen->setSizePolicy(sizePolicy1);
        screen->setMinimumSize(QSize(0, 0));
        screen->setFrameShape(QFrame::NoFrame);
        screen->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(screen, 6, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        ZoomIn = new QPushButton(centralWidget);
        ZoomIn->setObjectName(QString::fromUtf8("ZoomIn"));

        horizontalLayout->addWidget(ZoomIn);

        ZoomOut = new QPushButton(centralWidget);
        ZoomOut->setObjectName(QString::fromUtf8("ZoomOut"));

        horizontalLayout->addWidget(ZoomOut);

        firstPage = new QPushButton(centralWidget);
        firstPage->setObjectName(QString::fromUtf8("firstPage"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(firstPage->sizePolicy().hasHeightForWidth());
        firstPage->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Montserrat"));
        font4.setPointSize(10);
        font4.setBold(true);
        firstPage->setFont(font4);

        horizontalLayout->addWidget(firstPage);

        previousPage = new QPushButton(centralWidget);
        previousPage->setObjectName(QString::fromUtf8("previousPage"));
        sizePolicy3.setHeightForWidth(previousPage->sizePolicy().hasHeightForWidth());
        previousPage->setSizePolicy(sizePolicy3);
        previousPage->setFont(font4);

        horizontalLayout->addWidget(previousPage);

        nextPage = new QPushButton(centralWidget);
        nextPage->setObjectName(QString::fromUtf8("nextPage"));
        sizePolicy3.setHeightForWidth(nextPage->sizePolicy().hasHeightForWidth());
        nextPage->setSizePolicy(sizePolicy3);
        nextPage->setFont(font4);

        horizontalLayout->addWidget(nextPage);

        lastPage = new QPushButton(centralWidget);
        lastPage->setObjectName(QString::fromUtf8("lastPage"));
        sizePolicy3.setHeightForWidth(lastPage->sizePolicy().hasHeightForWidth());
        lastPage->setSizePolicy(sizePolicy3);
        lastPage->setFont(font4);

        horizontalLayout->addWidget(lastPage);

        currPageDisplay = new QLineEdit(centralWidget);
        currPageDisplay->setObjectName(QString::fromUtf8("currPageDisplay"));
        sizePolicy1.setHeightForWidth(currPageDisplay->sizePolicy().hasHeightForWidth());
        currPageDisplay->setSizePolicy(sizePolicy1);
        currPageDisplay->setFont(font1);
        currPageDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(currPageDisplay);

        totalPageDisplay = new QLabel(centralWidget);
        totalPageDisplay->setObjectName(QString::fromUtf8("totalPageDisplay"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(totalPageDisplay->sizePolicy().hasHeightForWidth());
        totalPageDisplay->setSizePolicy(sizePolicy4);
        totalPageDisplay->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(totalPageDisplay);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaxVisibleItems(10);

        horizontalLayout->addWidget(comboBox);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 940, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuDisplay_Mode = new QMenu(menuOption);
        menuDisplay_Mode->setObjectName(QString::fromUtf8("menuDisplay_Mode"));
        menuDouble_page = new QMenu(menuDisplay_Mode);
        menuDouble_page->setObjectName(QString::fromUtf8("menuDouble_page"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionCombine);
        menuFile->addSeparator();
        menuFile->addAction(actionAbout);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuOption->addAction(menuDisplay_Mode->menuAction());
        menuDisplay_Mode->addAction(actionSingle_Page);
        menuDisplay_Mode->addAction(menuDouble_page->menuAction());
        menuDouble_page->addAction(actionCover_page);
        menuDouble_page->addAction(actionNo_cover_page);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionCombine->setText(QCoreApplication::translate("MainWindow", "Combine", nullptr));
#if QT_CONFIG(shortcut)
        actionCombine->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "AboutQt", nullptr));
        actionSingle_Page->setText(QCoreApplication::translate("MainWindow", "Single page", nullptr));
        actionRaw->setText(QCoreApplication::translate("MainWindow", "Raw", nullptr));
        actionText_focused->setText(QCoreApplication::translate("MainWindow", "Text focused", nullptr));
        actionDrawing_focused->setText(QCoreApplication::translate("MainWindow", "Drawing focused", nullptr));
        actionCover_page->setText(QCoreApplication::translate("MainWindow", "Cover page", nullptr));
        actionNo_cover_page->setText(QCoreApplication::translate("MainWindow", "No cover page", nullptr));
        Bookmark->setText(QCoreApplication::translate("MainWindow", "BookMark", nullptr));
        Gotobookmark->setText(QCoreApplication::translate("MainWindow", "Go to last boomark", nullptr));
        Last_Bookmark->setText(QCoreApplication::translate("MainWindow", "Last Bookmark :", nullptr));
        page_Bookmark->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        screen->setText(QString());
        ZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
        ZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
        firstPage->setText(QCoreApplication::translate("MainWindow", "Front Page", nullptr));
#if QT_CONFIG(tooltip)
        previousPage->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        previousPage->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        nextPage->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        lastPage->setText(QCoreApplication::translate("MainWindow", "Last Page", nullptr));
        totalPageDisplay->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Fit page", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Fit width", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Custom", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOption->setTitle(QCoreApplication::translate("MainWindow", "Option", nullptr));
        menuDisplay_Mode->setTitle(QCoreApplication::translate("MainWindow", "Page Mode", nullptr));
        menuDouble_page->setTitle(QCoreApplication::translate("MainWindow", "Double page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
