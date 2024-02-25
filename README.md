# Comic-Book reader/Writer
Comic Book Reader réalisé en C++ dans le cadre du cours IN204 d'ENSTA Paris

## But du projet 
Ce projet d'IN204 consiste à réaliser un logiciel qui soit capable de fournir un **lecteur** permettant de prendre en charge les différents formats utilisés pour les bandes dessinées, à l’instar de certains logiciels présents. 
Cet outil offre une **interface agréable et performante** permettant de parcourir les différentes pages d’un livre au format *.CBR* ou au format *.CBZ*.

## Outils
* Qt version 5 (Gestion de l'interface)
* Libarchive (Gestion des archives)
```
$ sudo apt-get install qtbase5-dev
$ sudo apt-get install libarchive-dev

```

## Build sous Linux
Pour compiler le projet sous Linux, placez-vous dans le dossier *"IN204/ComicBookReader"* et tapez ces trois instructions dans un shell bash : 
```
$ qmake
$ make
$ ./ComicBookReader
```

## Fonctionnalités
* Ouverture d'un fichier Comic Book (formats acceptés : *.cbr, *.cbz, *.rar, *.zip, *.7zip, *.7z) contenant des images (formats acceptés : *.bmp, *.gif, *.jpeg, *.jpg, *.png)
* Possibilité de choisir et d'extraire des pages d'un ouvrage au format .cbz
* Navigation possible entre les différentes pages (première, dernière, suivante, précédente ou au choix) avec les boutons ou à l'aide de raccourci (Flèches directionnelles droite/gauche, bouton Début/Fin)
* Possibilité de redimensionner l'image (zoom, adapté à la page, adapté à la largeur) avec les boutons ou à l'aide de raccourci (Ctrl + Molette, Ctrl + +, Ctrl + -, Ctrl + 0)
* Affichage en mode double page avec choix si page de couverture ou non (première page unique ou double page)

## Diagramme UML (diagramme de classe)

Un diagramme UML (Unified Modeling Language) est un type de diagramme utilisé dans le domaine de l'ingénierie logicielle pour représenter visuellement la structure et le comportement d'un système logiciel. Ici, on représente un diagramme de classe, qui représente les classes et les relations entre elles dans un système logiciel, y compris les attributs et les méthodes.

