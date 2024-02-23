#-------------------------------------------------
#
# Project created by QtCreator 2023-02-27T03:55:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComicBookReader
TEMPLATE = app

LIBS += -larchive

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/book.cpp \
    src/image.cpp \
    src/archiveManager.cpp \
    src/combinewindow.cpp

HEADERS  += header/mainwindow.h \
    header/book.h \
    header/image.h \
    header/archiveManager.h \
    header/combinewindow.h

FORMS    += mainwindow.ui \
    combinewindow.ui
