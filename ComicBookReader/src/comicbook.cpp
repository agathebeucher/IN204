/*
DEFINITION DE LA CLASSE "BOOK" et de ses méthodes
*/

#include "../header/comicbook.h"
#include "../header/image.h"
#include <QString>
#include <QDir>
#include <QPixmap>
#include <QMessageBox>

// Constructeur de la classe : Initialisation de ses méthodes, hérite de QObject
ComicBook::ComicBook() : 
    QObject(), pathToDir(""), currPage(0), totalPage(0), ratio(QString("RedimVertical")), simpleMode(true), doubleMode(false) {}

// Destructeur de la classe
ComicBook::~ComicBook() {
}

/*
Définit "path" comme chemin du repértoire contenant les images du livres
*/
void ComicBook::setPathToDir(QString path) {
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

void ComicBook::setRatio(QString r) {
    ratio = r;//stock le mode de rapport d'affichage de l'image ("RedimVertical" ou "RedimHorizontal")
}

// Modifie le mode d'affichage vers le mode 'une seule page'
void ComicBook::setSimpleMode(bool value) {
    simpleMode = value;
    changeCurrImage();
    emit pageChanged(false);
}

void ComicBook::setDoubleMode(bool value) {
    doubleMode = value;
    changeCurrImage();
    emit pageChanged(false);
}

void ComicBook::setCurrPage(int val) {
    if (val>=0 && val<totalPage) {
        currPage=val;
        changeCurrImage();
        emit pageChanged(true);
    }
}

// Mise à jour de l'image  affichée en fonction du mode de page et de la page actuelle
void ComicBook::changeCurrImage() {
    if (simpleMode || currPage==totalPage-1 || (!simpleMode && currPage==0)) {
        currImage = QPixmap(tabPathToImage[currPage]);
    } else {
        currImage = Image::combine(QPixmap(tabPathToImage[currPage]), tabPathToImage[currPage+1] );
    }
}

// Passage à la page suivante
void ComicBook::next() {
    if ((currPage<totalPage-1 && simpleMode) || currPage<totalPage-2 ) {
        if (simpleMode || currPage+1==totalPage-1 || (!simpleMode && currPage==0)) {
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
void ComicBook::previous() {
    if (currPage>0) {
        if (simpleMode || currPage-1==0) {
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

void ComicBook::first() {
    currPage=0;
    changeCurrImage();
    emit pageChanged(true);
}

void ComicBook::last() {
    if (simpleMode) {
        currPage = totalPage - 1;
    } else if (!simpleMode) {
        currPage = totalPage - 1 - (totalPage % 2);
    } else {
        currPage = totalPage - 1 - ((totalPage - 1) % 2);
    }
    changeCurrImage();
    emit pageChanged(true);
}


QString ComicBook::getRatio() {
    return ratio;
}


QPixmap ComicBook::getCurrImage() {
    return currImage;
}

int ComicBook::getCurrPage() {
    return currPage;
}

int ComicBook::getTotalPage() {
    return totalPage;
}

QFileInfoList* ComicBook::getFileInfoList(QList<int> l) {
    QFileInfoList* fileList = new QFileInfoList();
    foreach(int i, l) {
        fileList->append(QFileInfo(tabPathToImage[i-1]));
    }
    return fileList;
}
