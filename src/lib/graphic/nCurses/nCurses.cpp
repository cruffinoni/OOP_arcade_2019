/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <cstring>
//#include <cstdlib>
#include "nCurses.hpp"

static Graphic::nCurses *instance;

extern "C" {
IGraphicRenderer *loadLibrary() {
//    return (instance);
}

__attribute__((constructor)) void load() {
    printf("constructor nCurses called\n");
    instance = new Graphic::nCurses();
}

__attribute__((destructor)) void unload() {
    printf("destructor nCurses called\n");
    delete instance;
}
}

Graphic::nCurses::nCurses() {
    char *msg= "Texte au centre";
    int taille= strlen(msg);

    initscr();
    while(1) {
        clear();
//        mvwchgat("arcade");
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);
//        drawRect(4);
        refresh();
        if(getch() != 410)
            break;
    }

    endwin();

}

Graphic::nCurses::~nCurses() {
    printf("delete constructor\n");
    endwin();
}

void Graphic::nCurses::clearScreen() {
    werase(this->_window);
    wclear(this->_window);
    free(this->_window);
}

void Graphic::nCurses::drawCircle(Circle circle) {
    // TODO: ...
}

void Graphic::nCurses::drawRect(Rect rect) {
//    int x = 0;
//    int y = 0;
//
//    while (x < LINES) {
//        move(x, COLS / 2);
//        addch('|');
//        ++x;
//    }
//    while (y < COLS) {
//        move(LINES / 2, y);
//        addch('-');
//        ++y;
//    }
//    attron(COLOR_PAIR(COLOR_GREEN));
//    attron(A_BOLD);
//    mvprintw(LINES / 2 - 1, COLS / 2 - 1, "1");
//    mvprintw(LINES / 2 - 1, COLS / 2 + 1, "2");
//    mvprintw(LINES / 2 + 1, COLS / 2 - 1, "3");
//    mvprintw(LINES / 2 + 1, COLS / 2 + 1, "4");
//    attroff(A_BOLD);
//    attroff(COLOR_PAIR(COLOR_GREEN));
}

void Graphic::nCurses::drawScreen() {
    refresh();
}

void Graphic::nCurses::drawSprite(Sprite sprite) {
    // TODO: ...
}

void Graphic::nCurses::drawText(Text text) {
    // TODO: ...
}

std::string Graphic::nCurses::handleEvent() {
//    int keyboardCode;
//    keyboardCode = getch();
//    switch (keyboardCode) {
//        case KEY_RESIZE:
//            clear();
//            this->printScreen();
//            break;
//        case KEY_ESCAPE:
//        case 'q':
//            return MonitorDisplay::Status::KO;
//        case '1':
//            clear();
//            this->swapModule(0);
//            break;
//        case '2':
//            clear();
//            this->swapModule(1);
//            break;
//        case '3':
//            clear();
//            this->swapModule(2);
//            break;
//        case '4':
//            clear();
//            this->swapModule(3);
//            break;
//        case 'p':
//            clear();
//            return MonitorDisplay::Status::STATUS_CHANGE_GRAPHICS;
//    }
//    return MonitorDisplay::Status::STATUS_OK;
}

bool Graphic::nCurses::isOperational() {
    return false;
}
