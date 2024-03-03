#include "../header/bookmark.h"
#include <QString>
#include <QDir>
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <QDebug>

// Constructeur
Bookmark::Bookmark() : 
    QObject(), page_marked(0), bookmarkFilename() {}

// Destructeur
Bookmark::~Bookmark()
{}

void Bookmark::set_bookmarkFilename(QString new_filename){
    int exemplePos = new_filename.lastIndexOf("/Exemple/") + QString("/Exemple/").length();
    int lastDotPos = new_filename.lastIndexOf(".");

    if (lastDotPos != -1) {
        // Construire le chemin en insérant "/Bookmark/" après "/Exemple/"
        QString pathBeforeExemple = new_filename.left(exemplePos);
        QString fileNameWithoutExtension = new_filename.mid(exemplePos, lastDotPos - exemplePos);
        bookmarkFilename = pathBeforeExemple + "Bookmark/" + fileNameWithoutExtension + "_bookmark.txt";
    }
    qDebug() << bookmarkFilename;
}

void Bookmark::set_pagemarked(int val){
    page_marked=val;
}

QString Bookmark::get_bookmarkFilename(){
    return(bookmarkFilename);
}

int Bookmark::get_pagemarked(){
    return(page_marked);
}

void Bookmark::initialize_bookmarkfile(QString bookmarkFilename, int val){
    std::ofstream bookmarkFile(bookmarkFilename.toStdString());
        if (bookmarkFile.is_open()) {
            bookmarkFile << val << std::endl;
            bookmarkFile.close();
        } 
        else {
            std::cerr << "Impossible de créer le fichier de marque-page." << std::endl;
        }
}

void Bookmark::change_bookmarkfile(QString bookmarkFileName,int val){
    std::ofstream bookmarkFile(bookmarkFileName.toStdString(), std::ios::app);
    if (bookmarkFile.is_open()) {
        bookmarkFile << val << std::endl;
        bookmarkFile.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier de marque-page pour écriture." << std::endl;
    }
}
