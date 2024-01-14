/*
BIBLIOTHEQUES : 
- unarr(ar_open_file, r_parse_entry, ar_entry_get_offset, ar_entry_get_size)
- openCV (cv::imdecode, cv::IMREAD_COLOR)
*/

#include "header_file/ArchiveReader.h"

//Constructeur de la classe Archive reader
ArchiveReader::ArchiveReader(){}

//Destructeur de la classe
ArchiveReader::~ArchiveReader(){}


bool ArchiveReader::loadArchivedFiles(std::string file_path)
{
	offset_cache.clear();
	archive_path = file_path;
	//'file_type_pos' cherche l'indice de l'information du type de fichier
	//'file_type_pos' contiend la position de la dernière occurrence de "." dans la chaîne 'archive_path'
	size_t file_type_pos = archive_path.rfind(".");
	//création de 'file_type' contenant le TYPE DE FICHIER
	std::string file_type(archive_path.begin() + file_type_pos + 1, archive_path.end());
	std::transform(file_type.begin(), file_type.end(), file_type.begin(), ::tolower);
	
	//Si le type de fichier est "png", "jpg" ou "bmp", cela signifie qu'il s'agit d'une image unique. 
	if (file_type == "png" || file_type == "jpg" || file_type == "bmp") {
		page_num_total = 1;
		isSingleImg = true;
		return true;
	}

	//Sinon, le type de fichier indique une archive cbr ou cbz
	isSingleImg = false;
	char *path = &archive_path[0]; //adresse mémoire du premier caractère de la chaîne du chemin du fichier
	stream = ar_open_file(path);//voir bibliothèque unarr, renvoie un pointeur vers un flux associé au fichier
	if (stream == NULL) return false;//echec
	ar = ar_open_any_archive(stream, strrchr(path, '.'));//ouverture de l'archive, renvoie pointeur vers archive ouverte
	if (!ar) return false;//echec
	int count = 0;
	while (ar_parse_entry(ar)) //parcours les entrées de l'archive
	{
		size_t offset = ar_entry_get_offset(ar);//offset = position relative dans l'archive
		offset_cache.push_back(offset);
		count++;
	}
	page_num_total = count;
	return true;
}


//Charger une seul image à partir d'un fichier d'archive
//num : index de l'image à charger
//cv::Mat charge l'image stockée
//renvoie l'état de chargement de l'archive
bool ArchiveReader::loadOneImage(int num, cv::Mat &a_image)
{
	if (num > page_num_total || num < 1) return false;//plage de l'index d'image invalide

	//L'archive ne contient qu'une image donc chargement de toute l'archive
	if (isSingleImg == true)
	{
		a_image = cv::imread(archive_path, cv::IMREAD_COLOR);//Chargement de l'image unique avec fonction d'openCV
		return true;
	}

	//archive plus d'une image
	if(!ar_parse_entry_at(ar, offset_cache[num-1])) return false;
	size_t size = ar_entry_get_size(ar);//taille de l'archive
	if (size <= 0) {
		const char* zero_file = ar_entry_get_name(ar);
		std::cout << zero_file << std::endl;
		return false;
	}
	//check buffer size 
	read_buffer.resize(size);//alloue un tampon de lecture de la taille de l'image (size), espace mémoire stockant donnée image compressée
	unsigned char *buffer = &read_buffer[0];//pointeur vers le début du buffer
	if(!ar_entry_uncompress(ar, buffer, size)) return false;//décompresse données de l'entrée de l'archuve ar 

	a_image = cv::imdecode(read_buffer, cv::IMREAD_COLOR);//décoder l'image à partir du tampon de lecture, création de l'image

	return true;
}



int ArchiveReader::getPageNumTotal()
{
	return page_num_total; //provient de la fonction ArchiveReader::loadArchivedFiles
}

//ouvre les archives rar,zip,7z,tar ==> renvoie le pointeur vers l'archive ouverte
ar_archive* ArchiveReader::ar_open_any_archive(ar_stream * stream, const char * fileext)
{
	ar_archive *ar = ar_open_rar_archive(stream);
	if (!ar)
		ar = ar_open_zip_archive(stream, fileext && (strcmp(fileext, ".xps") == 0 || strcmp(fileext, ".epub") == 0));
	if (!ar)
		ar = ar_open_7z_archive(stream);
	if (!ar)
		ar = ar_open_tar_archive(stream);
	return ar;
}
