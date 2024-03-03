#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPixmap>
#include <QList>
#include "../header/comicbook.h"
#include "../header/bookmark.h"
#include "../header/assemblage.h"
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Book* currentBook;
    Bookmark* currentBookmark;
    // Dialog window used when combining images
    Assemblage* assemblerDialogWindow;
    // Supported files filter
    static QString filter;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
// Push buttons
    void on_previousPage_clicked();
    void on_nextPage_clicked();
    void on_lastPage_clicked();
    void on_firstPage_clicked();
    void on_ZoomOut_clicked();
    void on_ZoomIn_clicked();
    // Changing the performed zoom
    void on_comboBox_activated(const QString &r);
    // Set the current page
    void on_currPageDisplay_editingFinished();
    

// Action on Menu
    // Fermeture de la fenêtre    
    void on_actionClose_triggered();
    // Donne info sur Qt
    void on_actionAbout_triggered();
    // Ouverture du Comicbook, affichage de la page de garde et du dernier bookmark
    void on_actionOpen_triggered();
    // Création d'une archive avec les pages séléctionnées
    void on_actionAssembler_triggered();
    // Mode une seule page
    void on_actionSimplePage_triggered();
    // Mode double page
    void on_actionDoublePage_triggered();
    // Définir un marque-page
    void on_actionBookmark_triggered();
    // Aller à la dernière page marquée
    void on_actionGotobookmark_triggered();

// Display
    void setImage(QPixmap image);
    // Refresh l'image affichée en fonction des paramètres et mise à jour de la page number
    void refreshScreen(bool numPageChanged);
    // Affichage d'un message
    void msgBox(QString msg);
    // Redimensionnement de l'image quand 'event'
    void resizeEvent(QResizeEvent *event);
    // Set "Page fit" zoom, only used for the reset zoom shortcut
    void setDefaultZoom();

    // Create an archive with path s containing all images in l, only used after successful call of on_actionCombine_triggered
    void assemblerSlot(QList<int> l, QString s);
    // Event filter : Ctrl + mouse wheel applies a zoom instead of a scroll
    bool eventFilter(QObject *watched, QEvent *event);
    void wheelEvent(QWheelEvent *event) override;
    // Key shortcuts
    void keyReleaseEvent(QKeyEvent *event);
    bool fileExists(QString fileName);


signals:
};

#endif // MAINWINDOW_H
