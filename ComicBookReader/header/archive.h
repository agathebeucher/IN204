#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QFileDialog>

// Creation d'une archive à cheminZIP/RAR comprenant tous les fichiers dans listeFichiers
void CompresserZIP(QFileInfoList listeFichiers, QString cheminZip);
void CompresserRAR(QFileInfoList listeFichiers, QString cheminRAR);

// Extraction des fichiers dans cheminZIP/RAR dans un fichier au nom de l'archive au cheminCible
void DecompresserZIP(QString cheminZip, QString cheminCible);
void DecompresserRAR(QString cheminRAR, QString cheminCible);

#endif // ARCHIVE_H
