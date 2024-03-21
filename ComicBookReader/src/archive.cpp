/* 
GESTION DES ARCHIVES : Compression et décompression de fichiers
FONCTIONNALITÉS : Compression (COMPRESSER) et Décompression (DECOMPRESSER)
DÉPENDANCE : libarchive
*/

#include "../header/archive.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <QProcess>
#include <QDebug>

// En-têtes de Libarchive
#include <archive.h>
#include <archive_entry.h>

void CompresserZIP(QFileInfoList listeFichiers, QString cheminZip) {
  std::string cheminSortie = cheminZip.toStdString();
  const char* nomArchive = cheminSortie.c_str();

  // Initialisation de l'archive 
  struct archive *archive;
  struct archive_entry *entree;
  struct stat infosFichier;
  char buffer[8192];
  int longueur;
  int descripteurFichier;

  

  archive = archive_write_new();
  archive_write_set_format_zip(archive);
  archive_write_open_filename(archive, nomArchive);
  for(int i = 0; i < listeFichiers.size(); ++i) {
    QString cheminFichier = listeFichiers.at(i).filePath();
    QFile fichier(cheminFichier);

    std::string cheminFichierStr = cheminFichier.toStdString();
    const char* cheminFichierC = cheminFichierStr.c_str();
    std::string nomFichierStd = fichier.fileName().section("/", -1, -1).toStdString();
    const char* nomFichier = nomFichierStd.c_str();

    stat(cheminFichierC, &infosFichier);
    entree = archive_entry_new();
    archive_entry_set_pathname(entree, nomFichier);
    archive_entry_set_size(entree, infosFichier.st_size);
    archive_entry_set_filetype(entree, AE_IFREG);
    archive_entry_set_perm(entree, 0644);
    archive_write_header(archive, entree);
    descripteurFichier = open(cheminFichierC, O_RDONLY);
    longueur = read(descripteurFichier, buffer, sizeof(buffer));
    while (longueur > 0) {
      archive_write_data(archive, buffer, longueur);
      longueur = read(descripteurFichier, buffer, sizeof(buffer));
    }
    close(descripteurFichier);
    archive_entry_free(entree);
  }
  archive_write_close(archive);
  archive_write_free(archive);
}

void CompresserRAR(QFileInfoList listeFichiers, QString cheminRAR) {
    // Construire la commande rar pour compresser les fichiers
    QStringList arguments;
    arguments << "a" << "-r" << cheminRAR;
    for (const auto& fileInfo : listeFichiers) {
        arguments << fileInfo.absoluteFilePath();
    }

    // Exécuter la commande
    QProcess process;
    process.start("rar", arguments);
    process.waitForFinished();

    // Vérifier si la compression a réussi
    if (process.exitCode() == 0) {
        qDebug() << "Compression réussie.";
    } else {
        qWarning() << "Erreur lors de la compression:" << process.errorString();
    }
}

void DecompresserZIP(QString cheminZip, QString cheminCible) {
    std::string cheminArchive = cheminZip.toStdString();
    const char* nomFichier = cheminArchive.c_str();

    struct archive *archiveLecture, *archiveEcriture;
    struct archive_entry *entree;
    int drapeaux;
    int resultat;

    auto copierDonnees = [](struct archive *ar, struct archive *aw) {
        const void *buff;
        size_t taille;
        la_int64_t decalage;
        int resultat;

        while (true) {
            resultat = archive_read_data_block(ar, &buff, &taille, &decalage);
            if (resultat == ARCHIVE_EOF)
                return ARCHIVE_OK;
            if (resultat < ARCHIVE_OK)
                return resultat;
            resultat = archive_write_data_block(aw, buff, taille, decalage);
            if (resultat < ARCHIVE_OK) {
                fprintf(stderr, "%s\n", archive_error_string(aw));
                return resultat;
            }
        }
    };

    std::string cheminDestination = cheminCible.toStdString() + '/';

    drapeaux = ARCHIVE_EXTRACT_TIME | ARCHIVE_EXTRACT_PERM | ARCHIVE_EXTRACT_ACL | ARCHIVE_EXTRACT_FFLAGS;

    archiveLecture = archive_read_new();
    archive_read_support_format_all(archiveLecture);
    archive_read_support_filter_all(archiveLecture);
    archiveEcriture = archive_write_disk_new();
    archive_write_disk_set_options(archiveEcriture, drapeaux);
    archive_write_disk_set_standard_lookup(archiveEcriture);
    if ((resultat = archive_read_open_filename(archiveLecture, nomFichier, 10240)))
        exit(1);
    while (true) {
        resultat = archive_read_next_header(archiveLecture, &entree);
        if (resultat == ARCHIVE_EOF)
            break;
        if (resultat < ARCHIVE_OK)
            fprintf(stderr, "%s\n", archive_error_string(archiveLecture));
        if (resultat < ARCHIVE_WARN)
            exit(1);
        std::string cheminFichierActuel = std::string(archive_entry_pathname(entree));
        size_t pos = cheminFichierActuel.find_last_of('/');
        if (pos != std::string::npos) {
            cheminFichierActuel = cheminFichierActuel.substr(pos + 1);
        }
        std::string cheminCompletSortie = cheminDestination + cheminFichierActuel;
        archive_entry_set_pathname_utf8(entree, cheminCompletSortie.c_str());
        resultat = archive_write_header(archiveEcriture, entree);
        if (resultat < ARCHIVE_OK)
            fprintf(stderr, "%s\n", archive_error_string(archiveEcriture));
        else if (archive_entry_size(entree) > 0) {
            resultat = copierDonnees(archiveLecture, archiveEcriture);
            if (resultat < ARCHIVE_OK)
                fprintf(stderr, "%s\n", archive_error_string(archiveEcriture));
            if (resultat < ARCHIVE_WARN)
                exit(1);
        }
        resultat = archive_write_finish_entry(archiveEcriture);
        if (resultat < ARCHIVE_OK)
            fprintf(stderr, "%s\n", archive_error_string(archiveEcriture));
        if (resultat < ARCHIVE_WARN)
            exit(1);
    }
    archive_read_close(archiveLecture);
    archive_read_free(archiveLecture);
    archive_write_close(archiveEcriture);
    archive_write_free(archiveEcriture);
}

void DecompresserRAR(QString cheminRAR, QString cheminCible) {
  // Construire la commande unrar pour extraire l'archive.rar vers le répertoire cible
  QString commande = "unrar x \"" + cheminRAR + "\" -d \"" + cheminCible + "\"";

  // Exécuter la commande
  int resultat = std::system(commande.toStdString().c_str());

  // Vérifier si l'exécution de la commande a réussi
  if (resultat == 0) {
      std::cout << "Extraction réussie." << std::endl;
  } else {
      std::cerr << "Erreur lors de l'extraction." << std::endl;
  }
}