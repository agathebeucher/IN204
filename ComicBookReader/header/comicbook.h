#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QPixmap>
#include <QFileDialog>

class Book : public QObject
{
    Q_OBJECT
private:
    // Chemin vers tous les objets
    QString pathToDir;
    // tablau de chaque chemin d'image
    QVector<QString> tabPathToImage;
    // Le zoom actuel appliqué à l'image ("Custom", "Fit page" or "Fit width")
    QString ratio;
    // Page actuelle
    int currPage;
    // Nombre de pages
    int totalPage;
    // Une seule image affiché
    bool singleMode;
    // Seulement utilisé dans le mode double page (single page mode si true)
    bool coverPageMode;
    // Image actuelle sur l'écran sans zoom
    QPixmap currImage;

public:
    Book();
    ~Book();

    // Set the path to the dir with all the images and create the tab with all the path
    void setPathToDir (QString path);
    // Set the performed zoom
    void setRatio(QString r);
    // Set the page mode
    void setSingleMode(bool val);
    // Set if cover page mode
    void setCoverPageMode(bool val);
    // Set current page
    void setCurrPage(int val);
    // Update the current image according to the different parameters (current page, singleMode, coverPageMode, ...)
    void changeCurrImage();

    // Go to next page if possible
    void next();
    // Go to previous page if possible
    void previous();
    // Go to last page
    void last();
    // Go to first page
    void first();

    // Return the performed zoom
    QString getRatio();
    // Renvoie le nom de l'archive
    //QString getFileName();
    // Return number of pages of the Comic Book
    int getTotalPage();
    // Return current page number
    int getCurrPage();
    // Return current image shown on screen
    QPixmap getCurrImage();
    // Return fileInfoList of the pages in l, used to create an archive of the selected images
    QFileInfoList* getFileInfoList(QList<int> l);


signals:
    // Changing the image displayed on the screen, boolean tells if page number changed
    void pageChanged(bool numPageChanged);
    // Error/information msg
    void infoMsgBox(QString msg);


public slots:
};

#endif // BOOK_H
