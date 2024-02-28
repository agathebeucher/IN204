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

public:
    Bookmark();
    ~Bookmark();

    void set_page_marked(int val);
};

#endif // BOOKMARK_H