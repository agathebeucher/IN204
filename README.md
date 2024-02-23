# Comic-Book reader/Writer
Comic Book Reader réalisé en C++ dans le cadre du cours IN204 d'ENSTA Paris

## But du projet 
Ce projet d'IN204 consiste à réaliser un logiciel qui soit capable de fournir un **lecteur** permettant de prendre en charge les différents formats utilisés pour les bandes dessinées, à l’instar de certains logiciels présents. 
Cet outil offre une **interface agréable et performante** permettant de parcourir les différentes pages d’un livre au format *.CBR* ou au format *.CBZ*.

## Outils
* Qt version 6.1 (Gestion de l'interface)
* Libarchive (Gestion des archives)

## Compilation sous Linux
Pour compiler le proejt sous Linux, il suffit de se rendre dans le dossier *"IN204/ComicBookReader"* et de taper ces trois instructions dans un shell bash : 
```
qmake
make
./ComicBookReader
```

## Fonctionnalités
* Ouverture d'un Comic Book (formats acceptés : *.cbr, *.cbz, *.rar, *.zip, *.7zip, *.7z) contenant des images (formats acceptés : *.bmp, *.gif, *.jpeg, *.jpg, *.png)
* Possibilité de choisir et d'extraire des pages d'un ouvrage au format .cbz
* Navigation possible entre les différentes pages (première, dernière, suivante, précédente ou au choix) avec les boutons ou à l'aide de raccourci (Flèches directionnelles droite/gauche, bouton Début/Fin)
* Possibilité de redimensionner l'image (zoom, adapté à la page, adapté à la largeur) avec les boutons ou à l'aide de raccourci (Ctrl + Molette, Ctrl + +, Ctrl + -, Ctrl + 0)
* Affichage en mode double page avec choix si page de couverture ou non (première page unique ou double page)