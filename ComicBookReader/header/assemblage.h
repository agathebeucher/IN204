#ifndef COMBINEWINDOW_H
#define COMBINEWINDOW_H

#include <QDialog>
#include <QString>
#include <QList>

namespace Ui {
    class Assemblage;
}

class Assemblage : public QDialog {
    Q_OBJECT

private:
    Ui::Assemblage *ui;
    // Path of the archive
    QString zipPath;
    // List of all pages that have to be extracted
    QList<int> pageList;
    // Number of pages of the Comic Book
    int maxPage;

public:
    explicit Assemblage(QWidget *parent = 0);
    Assemblage(QWidget *parent = 0, int totalPage = 0);
    ~Assemblage();

private slots:
    // Choosing path and name of the new archive, adding .cbz extension if not already set
    void on_fileSelectButton_clicked();
    // Update pageList when user types desired pages that have to be extracted
    // Can only be number separated with '-' or ',' otherwise clear pageList
    void on_choosenPage_editingFinished();
    // When clicking on Ok button, error if pageList or path empty otherwise emit signal
    void on_AssemblerButton_clicked();
    // Cancel button
    void on_AnnulerButton_clicked();

signals:
    // Signal sent with pageList and zipPath
    void assemblerSignal(QList<int> l, QString s);
};

#endif // COMBINEWINDOW_H
