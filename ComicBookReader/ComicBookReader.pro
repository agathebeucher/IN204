#-------------------------------------------------
#
# Project created by QtCreator 2023-12-27T10:23:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComicBookReader
TEMPLATE = app

LIBS += -larchive -unrar

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/comicbook.cpp \
    src/image.cpp \
    src/archive.cpp \
    src/combinewindow.cpp\
    src/bookmark.cpp

HEADERS  += header/mainwindow.h \
    header/comicbook.h \
    header/image.h \
    header/archive.h \
    header/combinewindow.h \
    header/bookmark.h


FORMS    += mainwindow.ui \
    combinewindow.ui
