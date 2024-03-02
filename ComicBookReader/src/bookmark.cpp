#include "../header/bookmark.h"
#include <QString>
#include <QDir>
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>

// Constructeur
Bookmark::Bookmark() : 
    QObject(), page_marked(0), bookmarkFilename() {}

// Destructeur
Bookmark::~Bookmark()
{}

void Bookmark::set_bookmarkFilename(QString new_filename){
    int lastDotPos = new_filename.lastIndexOf(".");
    if (lastDotPos != -1) {
        // Extraire le nom du fichier sans l'extension
        bookmarkFilename = new_filename.left(lastDotPos);
    }
    // Ajouter "_bookmark.txt" comme nouvelle extension
    bookmarkFilename += "_bookmark.txt";
}

void Bookmark::set_pagemarked(int val){
    page_marked=val+1;
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
