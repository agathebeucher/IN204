#include "../header/mainwindow.h"
#include "../ui_mainwindow.h"
#include "../header/comicbook.h"
#include "../header/archive.h"
#include "../header/image.h"
#include "../header/bookmark.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <QScrollArea>
#include <QScrollBar>
#include <QShortcut>
#include <QWheelEvent>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDebug> 
#include <string>
#include <iostream>
#include <fstream>


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
    QTreeWidget *tree=ui->treeWidget;
// Shortcut part
    QShortcut *zoomInShortcut = new QShortcut(QKeySequence("CTRL++"), this);
    QShortcut *zoomOutShortcut = new QShortcut(QKeySequence("CTRL+-"), this);
    QShortcut *resetZoom = new QShortcut(QKeySequence("CTRL+0"), this);
    QAction *actionBookmark = new QAction("Double Page", this);
    QAction *actionGotobookmark = new QAction("Simple Page", this);
    QAction *actionDoublePage = new QAction("Double Page", this);
    QAction *actionSimplePage = new QAction("Simple Page", this);
    QAction *actionRedimVertical = new QAction("RedimVertical", this);
    QAction *actionRedimHorizontal = new QAction("RedimHorizontal", this);
    connect(zoomInShortcut, &QShortcut::activated, this, &MainWindow::on_ZoomIn_clicked);
    connect(zoomOutShortcut, &QShortcut::activated, this, &MainWindow::on_ZoomOut_clicked);
    connect(resetZoom, &QShortcut::activated, this, &MainWindow::setDefaultZoom);
    connect(actionBookmark,  &QAction::triggered, this, &MainWindow::on_actionBookmark_triggered);// Dans le constructeur de MainWindow ou dans une autre fonction d'initialisation
    connect(actionGotobookmark,  &QAction::triggered, this, &MainWindow::on_actionGotobookmark_triggered);
    connect(actionDoublePage, &QAction::triggered, this, &MainWindow::on_actionDoublePage_triggered);
    connect(actionSimplePage, &QAction::triggered, this, &MainWindow::on_actionSimplePage_triggered);
    connect(actionRedimHorizontal, &QAction::triggered, this, &MainWindow::on_actionRedimHorizontal_triggered);
    connect(actionRedimVertical, &QAction::triggered, this, &MainWindow::on_actionRedimVertical_triggered);
    connect(tree, &QTreeWidget::itemClicked, this, &MainWindow::on_treeWidget_itemClicked);
    }

MainWindow::~MainWindow()
{
    delete ui;
    delete currentBook;
    delete currentBookmark;
    QDir dir("../data/");
    dir.removeRecursively();
}

void MainWindow::loadConfigTDM(QString configTDMFilePath)
{
    QFile file(configTDMFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossible d'ouvrir le fichier de configuration:" << configTDMFilePath;
        return;
    }
    QByteArray fileContent = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(fileContent);

    if (!document.isObject()) {
        qWarning("Le document JSON n'est pas un objet.");
        return;
    }

    QJsonObject rootObject = document.object();
    QJsonArray items = rootObject.value("chapters").toArray();

    ui->treeWidget->clear(); // Nettoyez le QTreeWidget avant de le remplir
    populateTreeWidget(items);
}

void MainWindow::loadConfigInfos(QString configInfosFilePath)
{
    QFile file(configInfosFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossible d'ouvrir le fichier de configuration:" << configInfosFilePath;
        return;
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    QJsonObject jsonObject = document.object();
    QListWidget *listWidget = ui->Infos;
    QStringList keys = {"Serie", "Edition", "Titre","Tome", "Identifiant", "Scenario", "Dessin", "Couleurs", "DepotLegal", "Estimation", "Editeur", "Collection", "Format", "EAN_ISBN", "Planches", "AutresInfos", "DateCreation", "DateMiseAJour"};
    for (const QString &key : keys) {
        if (jsonObject.contains(key)) {
            // Créez un nouveau widget qui servira de conteneur
            QWidget *widget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(widget); // Utilisez un QHBoxLayout
            layout->setContentsMargins(0, 0, 0, 0); // Réduit les marges autour des widgets
            layout->setSpacing(0); // Réduit l'espacement entre les widgets
            QLabel *label = new QLabel();
            // Appliquez le formatage HTML pour mettre la clé en gras
            QString itemText = "<b>" + key + " :</b> " + jsonObject.value(key).toString();
            label->setText(itemText);
            label->setTextFormat(Qt::RichText); // Assurez-vous que le formatage RichText est activé
            layout->addWidget(label);

            // Créez un QListWidgetItem
            QListWidgetItem *item = new QListWidgetItem(ui->Infos);
            // Ajustez la taille de l'élément à celle du widget
            item->setSizeHint(widget->sizeHint());
            
            // Ajoutez le widget contenant le QLabel à la liste
            ui->Infos->setItemWidget(item, widget);
        }
    }
    file.close();
}

void MainWindow::populateTreeWidget(const QJsonArray &items)
{
    ui->treeWidget->clear(); // Nettoyer le QTreeWidget avant de le peupler
    for (int i = 0; i < items.size(); ++i) {
        QJsonObject itemObject = items[i].toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, itemObject.value("title").toString());
        item->setData(0, Qt::UserRole, itemObject.value("page").toInt()); // Stocker le numéro de page dans l'élément
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    int pageNumber = item->data(0, Qt::UserRole).toInt();
    currentBook->setCurrPage(pageNumber);
    currentBook->changeCurrImage();
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
    if (filename.isEmpty()) return;

    QString path = "../data/" + QFileInfo(filename).baseName();
    DecompresserZIP(filename, path);
    QDir dir(path);
    dir.setNameFilters(Image::imageFilters);
    if (dir.isEmpty()) {
        msgBox("No image or no supported image found");
        return;
    }
    currentBook = new ComicBook();
    
    QString configTDMFilePath = QFileInfo(filename).absolutePath() + "/Config/Table_des_matieres/" + QFileInfo(filename).baseName() + "_tdm.json";
    loadConfigTDM(configTDMFilePath);
    QString configInfoFilePath = QFileInfo(filename).absolutePath() + "/Config/Infos/" + QFileInfo(filename).baseName() + "_infos.json";
    currentBookmark= new Bookmark();
    loadConfigInfos(configInfoFilePath);
    currentBookmark->set_bookmarkFilename(filename+"Bookmark/");
    
    // Vérifier si un fichier de marque-page existe et le charger s'il existe
    QString bookmarkFile=currentBookmark->get_bookmarkFilename();
    if (fileExists(bookmarkFile)) {
        std::string bookmarkFilename = bookmarkFile.toStdString();
        std::ifstream file(bookmarkFilename); // Ouvre le fichier en mode lecture
        if (file.is_open()) {
            std::vector<int> values; // Stocker les valeurs lues
            int value;
            while (file >> value) {
                values.push_back(value); // Stocker chaque valeur lue dans le vecteur
            }
            if (!values.empty()) {
                int lastPage = values.back(); // Prendre la dernière valeur du vecteur
                currentBookmark->set_pagemarked(lastPage);
                currentBook->setCurrPage(lastPage-1);
                // Obtenir le chemin de l'image correspondant à la dernière page marquée

            } else {
                std::cerr << "Le fichier est vide." << std::endl;
            }
             // Utilisez bookmarkedPage pour initialiser votre interface graphique
            ui->page_Bookmark->setText(QString::number(currentBookmark->get_pagemarked()));
            file.close();
            }
        else {
            std::cerr << "Impossible d'ouvrir le fichier de marque-page." << std::endl;
        }
    }
    else {
        currentBookmark->initialize_bookmarkfile(bookmarkFile,0);
        ui->page_Bookmark->setText(QString("0"));
        currentBookmark->set_pagemarked(0);
    }

    // Charger l'image
    QPixmap image(path); // Charger l'image à partir du chemin spécifié
    
    // Afficher l'image dans le QLabel
    ui->screen->setPixmap(image);

    currentBook->setRatio(QString("RedimVertical"));

    connect(currentBook, SIGNAL(pageChanged(bool)), this, SLOT(refreshScreen(bool) ));
    connect(currentBook, SIGNAL(infoMsgBox(QString)), this, SLOT(msgBox(QString)));
    currentBook->setPathToDir(path); 
}

void MainWindow::on_actionAssembler_triggered()
{
    if (currentBook) {
        assemblerDialogWindow = new Assemblage(this, currentBook->getTotalPage());
        assemblerDialogWindow->show();
        connect(assemblerDialogWindow, SIGNAL(assemblerSignal(QList<int>,QString)), this, SLOT(assemblerSlot(QList<int>,QString)));
    } else {
        msgBox(QString("No Comic Book"));
    }
}

void MainWindow::on_actionSimplePage_triggered()
{
    if (!currentBook) return;
    currentBook->setDoubleMode(false);
    currentBook->setSimpleMode(true);
    refreshScreen(false);
}

void MainWindow::on_actionDoublePage_triggered(){
    if (!currentBook) return;
    currentBook->setSimpleMode(false);
    currentBook->setDoubleMode(true);
    refreshScreen(false);
}

void MainWindow::on_actionRedimHorizontal_triggered(){ 
    if (!currentBook) return;
    currentBook->setRatio(QString("RedimHorizontal"));
    refreshScreen(false);
}

void MainWindow::on_actionRedimVertical_triggered(){ 
    if (!currentBook) return;
    currentBook->setRatio(QString("RedimVertical"));
    refreshScreen(false);
}

void MainWindow::on_actionBookmark_triggered() {
    int currentPageNumber = currentBook->getCurrPage();

    // Ouverture du fichier bookmark en mode écriture pour mettre à jour le nouveau marque-page
    currentBookmark->change_bookmarkfile(currentBookmark->get_bookmarkFilename(),currentPageNumber);
    currentBookmark->set_pagemarked(currentPageNumber+1);
    ui->page_Bookmark->setText(QString::number(currentBookmark->get_pagemarked()));
}

void MainWindow::on_actionGotobookmark_triggered()
{
    currentBook->setCurrPage(currentBookmark->get_pagemarked()-1);
    refreshScreen(true);
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
    currentBook->setRatio(QString("RedimVertical"));
    refreshScreen(false);
}

void MainWindow::assemblerSlot(QList<int> l, QString s) {
    QFileInfoList* fileList = currentBook->getFileInfoList((QList<int>) l);
    CompresserZIP(*fileList, s);
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

bool MainWindow::fileExists(QString fileName) {
    QFileInfo fileInfo(fileName);
    return fileInfo.exists() && fileInfo.isFile();
}

