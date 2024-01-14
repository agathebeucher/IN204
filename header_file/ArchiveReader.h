#pragma once
#include <string>
#include <opencv2/opencv.hpp>
extern "C"
{
#include "unarr.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#if !defined(NDEBUG) && defined(_MSC_VER)
#include <windows.h>
#include <crtdbg.h>
#endif
}
#include <vector>
#include "comic_book_reader_contract.h"
class ArchiveReader: public ArchiveInterface
{
public:
	//Constructeur par défait
	ArchiveReader();
	//Destructeur
	~ArchiveReader();
	//Charge les fichiers d'archive et extrait info
	bool loadArchivedFiles(std::string file_path);
	//Charge une seule image à partir d'une archive
	bool loadOneImage(int num, cv::Mat &a_image);
	//Renvoie le nb de fichier de l'archive
	int getPageNumTotal();
private:
	//Ouvre une archive en fonction de son type
	ar_archive * ar_open_any_archive(ar_stream *stream, const char *fileext);
	std::string archive_path;
	//pointeur vers le flux d'ouverture l'archive
	ar_stream *stream = NULL;
	//pointeur vers l'archive
	ar_archive *ar = NULL;

	//tampon de stockage lors de lecture de l'archive
	std::vector<unsigned char> read_buffer;
	std::vector<size_t> offset_cache;
	int page_num_total;
	bool isSingleImg;
};

