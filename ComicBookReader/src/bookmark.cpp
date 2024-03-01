#include "../header/bookmark.h"
#include <QString>
#include <QDir>
#include <QPixmap>
#include <QMessageBox>

// Constructeur
Bookmark::Bookmark() : 
    QObject(), page_marked(0) {}

// Destructeur
Bookmark::~Bookmark()
{}

void Bookmark::set_page_marked(int val){
    page_marked=val;
}

void Bookmark::initialize_bookmarkfile(QString bookmarkFilename, int val){
    std::ofstream bookmarkFile(bookmarkFileName.toStdString());
        if (bookmarkFile.is_open()) {
            bookmarkFile << val << std::endl;
            bookmarkFile.close();
        } 
        else {
            std::cerr << "Impossible de créer le fichier de marque-page." << std::endl;
        }
}

void Bookmark::change_bookmark_file(QString bookmarkFileName,int val){
    std::ofstream bookmarkFile(bookmarkFileName.toStdString(), std::ios::app);
    if (bookmarkFile.is_open()) {
        bookmarkFile << val << std::endl;
        bookmarkFile.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier de marque-page pour écriture." << std::endl;
    }
}
