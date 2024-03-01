#include "../header/mainwindow.h"
#include "../ui_mainwindow.h"
#include "../header/book.h"
#include "../header/archiveManager.h"
#include "../header/image.h"
#include "../header/bookmark.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QPixmap>
#include <QDir>
#include <QScrollArea>
#include <QScrollBar>
#include <QShortcut>
#include <QWheelEvent>
#include <QDebug> 


QString MainWindow::filter = QString("Supported Files (*.cbr *.cbz *.rar *zip *.7z *.7zip)");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), currentBook(0), currentBookmark(0)
{
// Initialisation
    ui->setupUi(this);
    setMinimumSize(800,600);
    resize(1000,500);
    // Set size of the scroll area to get good size for the image
    ui->scrollArea->resize(978, 483);
    Image::setSize(ui->scrollArea->width(), ui->scrollArea->height());
    ui->screen->resize(ui->scrollArea->width(), ui->scrollArea->height());
    // Set an event filter to the mouse wheel so that if ctrl key is pressed and we use the mouse wheel a zoom is performed instead of scrolling
    ui->scrollArea->verticalScrollBar()->installEventFilter(this);
    setWindowTitle(tr("Comic Book Reader"));
    ui->page_Bookmark->setText(QString(""));

// Shortcut part
    QShortcut *zoomInShortcut = new QShortcut(QKeySequence("CTRL++"), this);
    QShortcut *zoomOutShortcut = new QShortcut(QKeySequence("CTRL+-"), this);
    QShortcut *resetZoom = new QShortcut(QKeySequence("CTRL+0"), this);
    QShortcut *bookmarkShortcut = new QShortcut(QKeySequence("CTRL+B"), this);
    connect(zoomInShortcut, &QShortcut::activated, this, &MainWindow::on_ZoomIn_clicked);
    connect(zoomOutShortcut, &QShortcut::activated, this, &MainWindow::on_ZoomOut_clicked);
    connect(resetZoom, &QShortcut::activated, this, &MainWindow::setDefaultZoom);
    connect(bookmarkShortcut, &QShortcut::activated, this, &MainWindow::on_Bookmark_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentBook;
    delete currentBookmark;
    QDir dir("../data/");
    dir.removeRecursively();
}

void MainWindow::on_previousPage_clicked()
{
    if (currentBook) {
        currentBook->previous();
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_nextPage_clicked()
{
    if (currentBook) {
        currentBook->next();
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_lastPage_clicked()
{
    if (currentBook) {
        currentBook->last();
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_firstPage_clicked()
{
    if (currentBook) {
        currentBook->first();
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_ZoomOut_clicked()
{
    if (!currentBook) return; // Vérifier si currentBook est nul
    if (!ui || !ui->screen || !ui->screen->pixmap()) return; // Vérifier si les pointeurs sont nuls
    
    QPixmap image = currentBook->getCurrImage();
    if (!image.isNull()) { // Vérifier si l'image n'est pas nulle
        QSize pixmapSize = ui->screen->pixmap()->size();
        setImage(Image::zoomOut(image, pixmapSize));
    }
}

void MainWindow::on_ZoomIn_clicked()
{
    if (!currentBook) return; // Vérifier si currentBook est nul
    if (!ui || !ui->screen || !ui->screen->pixmap()) return; // Vérifier si les pointeurs sont nuls
    
    QPixmap image = currentBook->getCurrImage();
    if (!image.isNull()) { // Vérifier si l'image n'est pas nulle
        QSize pixmapSize = ui->screen->pixmap()->size();
        setImage(Image::zoomIn(image, pixmapSize));
    }
}

void MainWindow::on_comboBox_activated(const QString &r)
{
    if (!currentBook) return;
    currentBook->setRatio(r);
    refreshScreen(false);

}

void MainWindow::on_currPageDisplay_editingFinished()
{
    int page = ui->currPageDisplay->text().toInt();
    if (!currentBook) {
        return;
    }
    if (page<=0 || page>currentBook->getTotalPage()) {
        ui->currPageDisplay->setText(QString::number(currentBook->getCurrPage()+1));
    } else {
        currentBook->setCurrPage(page-1);
    }
}


void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open", "../", filter);
    QString bookmarkFileName = currentBook->getFileName() + ".bookmark"; 

    if (filename.isEmpty()) return;
    QString path = "../data/" + QFileInfo(filename).baseName();
    Unzip(filename, path);
    QDir dir(path);
    dir.setNameFilters(Image::imageFilters);
    if (dir.isEmpty()) {
        msgBox("No image or no supported image found");
        return;
    }
    currentBook = new Book();
    currentBookmark= new Bookmark();
    // Charger l'image
    QPixmap image(path); // Charger l'image à partir du chemin spécifié
    
    // Afficher l'image dans le QLabel
    ui->screen->setPixmap(image);
    ui->page_Bookmark->setText(QString("0"));

    ui->comboBox->setCurrentIndex(0);
    connect(currentBook, SIGNAL(pageChanged(bool)), this, SLOT(refreshScreen(bool) ));
    connect(currentBook, SIGNAL(infoMsgBox(QString)), this, SLOT(msgBox(QString)));
    currentBook->setPathToDir(path);
    
    // Vérifier si un fichier de marque-page existe et le charger s'il existe
    if (fileExists(bookmarkFileName)) {
        std::ifstream bookmarkFile(bookmarkFileName.toStdString());
        if (bookmarkFile.is_open()) {
            int bookmarkedPage;
            if (bookmarkFile >> bookmarkedPage) {
                // Utilisez bookmarkedPage pour initialiser votre interface graphique
                ui->page_Bookmark->setText(QString("%1").arg(bookmarkedPage));
                // Assurez-vous que currentBookmark est mis à jour si nécessaire
                currentBookmark->set_page_marked(bookmarkedPage);
            }
            bookmarkFile.close();
        } else {
            std::cerr << "Impossible d'ouvrir le fichier de marque-page." << std::endl;
        }
    }
    else {
        currentBookmark->initialize_bookmarkfile(bookmarkFileName,0)
        ui->page_Bookmark->setText(QString("0"));
        currentBookmark->set_page_marked(0);
    }
}

void MainWindow::on_actionCombine_triggered()
{
    if (currentBook) {
        combineDialogWindow = new CombineWindow(this, currentBook->getTotalPage());
        combineDialogWindow->show();
        connect(combineDialogWindow, SIGNAL(combineSignal(QList<int>,QString)), this, SLOT(combineSlot(QList<int>,QString)));
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_actionSingle_Page_triggered()
{
    if (!currentBook) return;
    currentBook->setSingleMode(true);
    refreshScreen(false);
}

void MainWindow::on_actionCover_page_triggered()
{
    if (!currentBook) return;
    currentBook->setCoverPageMode(true);
    refreshScreen(false);
}

void MainWindow::on_actionNo_cover_page_triggered()
{
    if (!currentBook) return;
    currentBook->setCoverPageMode(false);
    refreshScreen(false);
}

void MainWindow::on_Bookmark_clicked() {
    int currentPageNumber = currentBook->getCurrPage();
    QString bookmarkFileName = currentBook->getFileName() + ".bookmark"; // Nom du fichier de marque-page basé sur le nom de l'archive

    // Ouverture du fichier bookmark en mode écriture pour mettre à jour le nouveau marque-page
    currentBookmark->change_bookmark_file(bookmarkFileName,currentPageNumber);
    ui->page_Bookmark->setText(QString("0"));
}

void MainWindow::setImage(QPixmap image) {
    ui->screen->setPixmap(image);
}


void MainWindow::refreshScreen(bool numPageChanged) {
    if (!currentBook || !ui || !ui->screen || !ui->screen->pixmap()) {
        return; // Vérifier si les pointeurs sont nuls
    }

    QPixmap image = currentBook->getCurrImage();
    if (image.isNull()) {
        qDebug() << "Image is null"; // Ajout d'un log pour vérifier si l'image est nulle
        return; // Vérifier si l'image n'est pas nulle
    }
    
    QSize valRatio;
    if (ui->screen->pixmap()->isNull()) {
        valRatio = image.size();
    } else {
        valRatio = QSize(image.scaledToHeight(ui->screen->pixmap()->height()).size());
    }
    QPixmap scaledImage = Image::resize(image, currentBook->getRatio(), valRatio);
    ui->screen->setPixmap(scaledImage);
    ui->scrollArea->verticalScrollBar()->setSliderPosition(ui->scrollArea->verticalScrollBar()->minimum());
    ui->scrollArea->horizontalScrollBar()->setSliderPosition(ui->scrollArea->horizontalScrollBar()->minimum());
    if (numPageChanged) {
        ui->totalPageDisplay->setText("/" + QString::number(currentBook->getTotalPage()));
        ui->currPageDisplay->setText(QString::number(currentBook->getCurrPage() + 1));
    }
}

void MainWindow::msgBox(QString msg) {
    QMessageBox::information(this, "", msg);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    Image::setSize(ui->scrollArea->width(), ui->scrollArea->height());
    refreshScreen(false);
}

void MainWindow::setDefaultZoom() {
    if (!currentBook) return;
    currentBook->setRatio(QString("Fit page"));
    ui->comboBox->setCurrentIndex(0);
    refreshScreen(false);
}


void MainWindow::combineSlot(QList<int> l, QString s) {
    QFileInfoList* fileList = currentBook->getFileInfoList((QList<int>) l);
    Zip(*fileList, s);
    delete fileList;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::Wheel) {
        QWheelEvent* we = static_cast<QWheelEvent*>(event);
        wheelEvent(we);
        event->accept();
        return true;
    }
    return false;
}

void MainWindow::wheelEvent(QWheelEvent *event) {
    if (event->modifiers().testFlag(Qt::ControlModifier)) {
        if ((event->angleDelta()).y()>0) {
            on_ZoomIn_clicked();
        } else if ((event->angleDelta()).y()<0){
            on_ZoomOut_clicked();
        }
    } else {
        if ((event->angleDelta()).y()<0) {
            int newValue = ui->scrollArea->verticalScrollBar()->value() + 3*ui->scrollArea->verticalScrollBar()->singleStep();
            ui->scrollArea->verticalScrollBar()->setValue(newValue);
        } else if ((event->angleDelta()).y()> 0) {
            int newValue = ui->scrollArea->verticalScrollBar()->value() - 3*ui->scrollArea->verticalScrollBar()->singleStep();
            ui->scrollArea->verticalScrollBar()->setValue(newValue);
        }
    }
    event->accept();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (!currentBook) return;
    switch (event->key()) {
        case Qt::Key_Left :
            if (ui->scrollArea->horizontalScrollBar()->value()==ui->scrollArea->horizontalScrollBar()->minimum()
                    && currentBook->getCurrPage()!=0) {
                on_previousPage_clicked();
                ui->scrollArea->horizontalScrollBar()->setValue(ui->scrollArea->horizontalScrollBar()->maximum());
            }
            break;
        case Qt::Key_Right :
            if (ui->scrollArea->horizontalScrollBar()->value()==ui->scrollArea->horizontalScrollBar()->maximum()
                       && currentBook->getCurrPage()!=currentBook->getTotalPage() - 1) {
                on_nextPage_clicked();
            }
            break;
        case Qt::Key_End :
            on_lastPage_clicked();
            break;
    case Qt::Key_Home :
        on_firstPage_clicked();
        break;
    }
}

bool fileExists(const QString& fileName) {
    QFileInfo fileInfo(fileName);
    return fileInfo.exists() && fileInfo.isFile();
}

