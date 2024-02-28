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
