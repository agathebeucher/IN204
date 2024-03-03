#include "../header/assemblage.h"
#include "../ui_assemblage.h"
#include <QFileDialog>
#include <stdlib.h>
#include <QMessageBox>

#include <iostream>

Assemblage::Assemblage(QWidget *parent) :
    Assemblage::Assemblage(parent, 0)
{

}

Assemblage::Assemblage(QWidget *parent, int totalPage) :
    QDialog(parent),
    zipPath(QString("")),
    pageList(QList<int>()),
    maxPage(totalPage),
    ui(new Ui::Assemblage)
{
    ui->setupUi(this);
    ui->pathSelected->setReadOnly(true);
    setWindowTitle(tr("Assemblage"));
    resize(360, 120);

    ui->choosenPage->setText(QString("1-")+QString::number(maxPage));
}

Assemblage::~Assemblage()
{
    delete ui;
}

void Assemblage::on_fileSelectButton_clicked()
{
    zipPath = QFileDialog::getSaveFileName(this, tr("Assemblage"), "../data");
    if (zipPath.right(4)!=QString(".cbz")) {
        zipPath = zipPath + QString(".cbz");
    }
    ui->pathSelected->setText(zipPath);
}

void Assemblage::on_choosenPage_editingFinished()
{
    QStringList splitList = ui->choosenPage->text().split(u',');
    QString s;
    foreach(s, splitList) {
        if (s.contains('-')) {
            QStringList tmp = s.split('-');
            if (tmp.size()!=2) {
                pageList.clear();
                break;
            }
            int fst = tmp[0].toInt();
            int scd = tmp[1].toInt();
            if (fst<1 || fst>maxPage || scd<1 || scd>maxPage || fst>scd) {
                pageList.clear();
                break;
            }
            for (int i=fst; i<=scd; i++) {
                pageList.append(i);
            }

        } else {
            int elt = s.toInt();
            if (elt<1 || elt>maxPage) {
                pageList.clear();
                break;
            }
            pageList.append(elt);
        }
    }
}

void Assemblage::on_AssemblerButton_clicked()
{
    if (zipPath == QString("") || pageList.empty()) {
        QMessageBox::information(this, "Assemblage", QString("Error"));
    } else {
        emit assemblerSignal(pageList, zipPath);
        close();
    }
}

void Assemblage::on_AnnulerButton_clicked()
{
    close();
}
