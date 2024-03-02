#ifndef BOOKMARK_H
#define BOOKMARK_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QPixmap>
#include <QFileDialog>


class Bookmark : public QObject
{
    Q_OBJECT
private:
    int page_marked;
    QString bookmarkFilename;

public:
    Bookmark();
    ~Bookmark();
    
    void set_bookmarkFilename(QString new_filename);
    void set_pagemarked(int val);
    int get_pagemarked();
    QString get_bookmarkFilename();
    
    void initialize_bookmarkfile(QString bookmarkFilename, int val);
    void change_bookmarkfile(QString bookmarkFilename,int val);
};

#endif // BOOKMARK_H