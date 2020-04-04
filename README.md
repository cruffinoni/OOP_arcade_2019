# OOP_arcade_2019
## Introduction

Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of
player scores.

To be able to deal with the elements of your gaming plateform at run-time,
your graphic libraries and your games must be implemented as dynamic libraries, loaded at runtime.

Each GUI available for the program must be used as a shared
library that will be loaded and used dynamically by the main program.

## Add a dynamic library
**[!] Your library must be have an entry point (a.k.a a function) named `entry`. [!]**

Place your library (only the `.so` extension is supported) in the `lib` or `games` folder depending if
it's a graphical library or a game. Your file name must be respect the following pattern:
`lib_arcade_$gamename.so` or `lib_arcade_$libraryname.so`.


**[!] The graphical library's entry point must return a `IGraphic *` instance. [!]**

**[!] The game library's entry point must return a `IGame *` instance [!]**


## Installation

### SFML installation:
https://www.sfml-dev.org/download/sfml/2.5.1/

### SDL installation:
##### Debian-based:
```bash
sudo apt-get install libsdl-dev;
sudo apt-get install libsdl2-ttf-dev;
```
##### Red hat-based:
```bash
sudo yum install SDL2-devel;
sudo yum install SDL2_ttf-devel;
```

### Documentation with Doxygen:
The documentation can be generated with Doxygen. All the public methods, static variables and class
are documented.
##### Installation:
- First, you need to install Doxygen: http://www.doxygen.nl/manual/install.html
- You can now generate all HTML files by running:
```bash
doxygen DocFileDoxygen;
```
- When it's done, navigate to the `html` folder and open the file `index.html`.
- Done, you have the whole documentation.

##### PDF version:
Associated with Doxygen, we use PDF Latex. You can download it at: https://miktex.org/download

You may require some additional package, if so download them by running:
```bash
sudo apt-get install texlive-latex-base texlive-fonts-recommended texlive-fonts-extra texlive-latex-extra
```
- You can now generate the PDF file:
```bash
doxygen DocFileDoxygen;
cd latex;
make;
```

## Collaboration

The project has been made in collaboration with:
- Louise KLEIVER - Leo KAIDER - Loic BRANSTETT
- Victor LIMBACH - Leo SEICHEPINE - Maxime SCHAEFFER

###### Authors: Clément RUFFINONI - Quentin HALTER - Antoine PRONNIER
