/*
DEFINITION DE LA CLASSE "BOOK" et de ses méthodes
*/

#include "../header/book.h"
#include "../header/image.h"
#include <QString>
#include <QDir>
#include <QPixmap>
#include <QMessageBox>

// Constructeur de la classe : Initialisation de ses méthodes, hérite de QObject
Book::Book() : 
    QObject(), pathToDir(""), currPage(0), totalPage(0), ratio(QString("Fit page")), singleMode(true), coverPageMode(true) {}

// Destructeur de la classe
Book::~Book() {
}

/*
Définit "path" comme chemin du repértoire contenant les images du livres
*/
void Book::setPathToDir(QString path) {
    pathToDir = path;
    QDir dir(path);//crée 'dir'
    dir.setNameFilters(Image::imageFilters);//définit filtre de nom de fichiers avec ceux de la classe Image::imagesFilters
    foreach (QFileInfo var, dir.entryInfoList()) //itère sur chaque fichier d'info sur les entrée de dir
    {
        tabPathToImage.append(var.absoluteFilePath());//liste qui contient les chemins de toutes les images du livre
        totalPage = totalPage + 1;//Nb total de page
    }
    changeCurrImage();
    emit pageChanged(true);
}

void Book::setRatio(QString r) {
    ratio = r;//stocke mode de rapport d'affichage de l'image ("Fit page" ou "Stretch")
}

// Modifie le mode d'affichage vers le mode 'une seule page'
void Book::setSingleMode(bool value) {
    singleMode = value;
    changeCurrImage();
    emit pageChanged(false);
}

// Modifie le mode de la page de couverture du livre électronique.
void Book::setCoverPageMode(bool value) {
    setSingleMode(false);
    coverPageMode = value;
    if ((coverPageMode && currPage) != 0)//vérifie si le mode de page de couverture activé & si page actuelle pas première page.
    {
        currPage = currPage - 1 + (currPage % 2);
    } else {
        currPage = currPage - (currPage % 2);
    }
    changeCurrImage();
    emit pageChanged(true);
}

void Book::setCurrPage(int val) {
    if (val>=0 && val<totalPage) {
        currPage=val;
        changeCurrImage();
        emit pageChanged(true);
    }
}

// Mise à jour de l'image  affichée en fonction du mode de page et de la page actuelle
void Book::changeCurrImage() {
    if (singleMode || currPage==totalPage-1 || (!singleMode && coverPageMode && currPage==0)) {
        currImage = QPixmap(tabPathToImage[currPage]);
    } else {
        currImage = Image::combine(QPixmap(tabPathToImage[currPage]), tabPathToImage[currPage+1] );
    }
}

// Passage à la page suivante
void Book::next() {
    if ((currPage<totalPage-1 && singleMode) || currPage<totalPage-2 ) {
        if (singleMode || currPage+1==totalPage-1 || (!singleMode && currPage==0 && coverPageMode)) {
            currPage = currPage + 1;
        } else {
            currPage = currPage + 2;
        }

        changeCurrImage();
        emit pageChanged(true);

    } else {
        emit infoMsgBox("Last page");
    }
}

// Revenir à la page précédente
void Book::previous() {
    if (currPage>0) {
        if (singleMode || currPage-1==0) {
            currPage = currPage - 1;
        } else {
            currPage = currPage - 2;
        }
        changeCurrImage();
        emit pageChanged(true);
    } else {
        emit infoMsgBox("First page");
    }
}

void Book::first() {
    currPage=0;
    changeCurrImage();
    emit pageChanged(true);
}

void Book::last() {
    if (singleMode) {
        currPage = totalPage - 1;
    } else if (!singleMode && coverPageMode) {
        currPage = totalPage - 1 - (totalPage % 2);
    } else {
        currPage = totalPage - 1 - ((totalPage - 1) % 2);
    }
    changeCurrImage();
    emit pageChanged(true);
}


QString Book::getRatio() {
    return ratio;
}

QPixmap Book::getCurrImage() {
    return currImage;
}

int Book::getCurrPage() {
    return currPage;
}

int Book::getTotalPage() {
    return totalPage;
}

QFileInfoList* Book::getFileInfoList(QList<int> l) {
    QFileInfoList* fileList = new QFileInfoList();
    foreach(int i, l) {
        fileList->append(QFileInfo(tabPathToImage[i-1]));
    }
    return fileList;
}
