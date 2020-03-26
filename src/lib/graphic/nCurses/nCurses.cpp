/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <cstring>
#include <chrono>
//#include <cstdlib>
#include "core/Core.hpp"
#include "nCurses.hpp"

static Graphic::nCurses *instance;

extern "C" {
    IGraphicRenderer *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[graphic] constructor nCurses called\n");
        instance = new Graphic::nCurses();
    }

    __attribute__((destructor)) void unload() {
        printf("[graphic] destructor nCurses called\n");
        delete instance;
    }
}

Graphic::nCurses::nCurses() : _alive(true) {
    initscr();
    noecho();
    start_color();
    keypad(stdscr, TRUE);
    timeout(3);
    for (short i = 0; i < 8; i++)
        init_pair(i, i, COLOR_BLACK);
}

Graphic::nCurses::~nCurses() {
    printf("delete constructor\n");
    endwin();
}

void Graphic::nCurses::clearScreen() {
    this->_tick = std::chrono::high_resolution_clock::now();
    //werase(this->_window);
    //wclear(this->_window);
    erase();
    clear();
}

void Graphic::nCurses::drawCircle(Circle circle) {
    // TODO: ...
}

void Graphic::nCurses::drawRect(Rect rect) {
    int maxSizeX = static_cast<int>(PERCENTAGE(rect.getSizeX()) * static_cast<float>(COLS));
    int maxSizeY = static_cast<int>(PERCENTAGE(rect.getSizeY()) * static_cast<float>(LINES));
    int posX = static_cast<int>(PERCENTAGE(rect.getPositionX()) * static_cast<float>(COLS));
    int posY = static_cast<int>(PERCENTAGE(rect.getPositionY()) * static_cast<float>(LINES));

    //attron(A_BOLD);
    //for (int i = 0; i < maxSizeX; i++)
    //    mvprintw(posY, i + posX, "-");
    //for (int x = 0; x < maxSizeX; x++) {
    //    for (int y = 1; y < maxSizeY; y++) {
    //        if (x == 0 || x + 1 == maxSizeX)
    //            mvprintw(y + posY, x + posX, "|");
    //        else
    //            mvprintw(y + posY, x + posX, "X");
    //    }
    //}
    //for (int i = 0; i < maxSizeX; i++)
    //    mvprintw(maxSizeY + posY, i + posX, "-");
    int color = COLOR_WHITE;

    if (rect.getColor() == Color::Red())
        color = COLOR_RED;
    else if (rect.getColor() == Color::Blue())
        color = COLOR_BLUE;
    else if (rect.getColor() == Color::Green())
        color = COLOR_GREEN;
    else if (rect.getColor() == Color::Black())
        color = COLOR_BLACK;
    attron(color);
    for (int x = 0; x < maxSizeX; x++) {
        for (int y = 0; y < maxSizeY; y++) {
            mvprintw(y + posY, x + posX, "X");
        }
    }
    //attroff(A_BOLD);
    attroff(color);
}

#include <thread>

void Graphic::nCurses::drawScreen() {
    refresh();
    auto now = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_tick).count();

    std::cerr << delta << std::endl;
    if (delta < Core::Core::TIME_PER_FRAME)
        std::this_thread::sleep_for(std::chrono::milliseconds(Core::Core::TIME_PER_FRAME - delta));
    this->_tick = now;
    //exit(0);
}

void Graphic::nCurses::drawSprite(Sprite sprite) {
    // TODO: ...
}

void Graphic::nCurses::drawText(Text text) {
    // TODO: ...
}

std::string Graphic::nCurses::handleEvent() {
    switch (getch()) {
        //case KEY_RESIZE:
        //    break;
        //case 'q':
        case KEY_ESCAPE:
            this->_alive = false;
            return (IEventIterator::KEY_UNKNOWN);
        case KEY_UP:
            return "EVENT_KEY_UP";//(IEventIterator::KEY_UP);
        case KEY_DOWN:
            return "EVENT_KEY_DOWN";//(IEventIterator::KEY_DOWN);
        case KEY_LEFT:
            return "EVENT_KEY_LEFT";//(IEventIterator::KEY_LEFT);
        case KEY_RIGHT:
            return "EVENT_KEY_RIGHT";//(IEventIterator::KEY_RIGHT);
        default:
            return (IEventIterator::KEY_UNKNOWN);
    }
    return (IEventIterator::KEY_UNKNOWN);
}

bool Graphic::nCurses::isOperational() {
    return (this->_alive);
}
