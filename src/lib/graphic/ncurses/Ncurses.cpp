/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <cstring>
#include <chrono>
#include <algorithm>
#include <thread>
#include <cmath>
#include "core/Core.hpp"
#include "Ncurses.hpp"

static Graphic::Ncurses *instance;

extern "C" {
    IGraphicRenderer *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[graphic] constructor Ncurses called\n");
        instance = new Graphic::Ncurses();
    }

    __attribute__((destructor)) void unload() {
        printf("[graphic] destructor Ncurses called\n");
        delete instance;
    }
}

Graphic::Ncurses::Ncurses() : _alive(true) {
    initscr();
    noecho();
    start_color();
    keypad(stdscr, TRUE);
    timeout(3);
    for (short i = 0; i < 8; i++)
        init_pair(i, i, COLOR_BLACK);
}

Graphic::Ncurses::~Ncurses() {
    endwin();
}

void Graphic::Ncurses::clearScreen() {
    this->_tick = std::chrono::high_resolution_clock::now();
    erase();
    clear();
}

void Graphic::Ncurses::drawCircle(Circle circle) {
    int radius = static_cast<int>(PERCENTAGE(circle.getSizeX()) * static_cast<float>(COLS));
    int posX = static_cast<int>(PERCENTAGE(circle.getPositionX()) * static_cast<float>(COLS));
    int posY = static_cast<int>(PERCENTAGE(circle.getPositionY()) * static_cast<float>(LINES));
    int color = this->getNcursesColor(circle.getColor());

    attron(COLOR_PAIR(color));
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int x = radius - w;
            int y = radius - h;
            if ((std::pow(x, 2) + std::pow(y, 2)) <= (radius * radius))
                mvprintw(y + posY, x + posX, "o");
        }
    }
    attroff(COLOR_PAIR(color));
}

void Graphic::Ncurses::drawRect(Rect rect) {
    int maxSizeX = static_cast<int>(PERCENTAGE(rect.getSizeX()) * static_cast<float>(COLS));
    int maxSizeY = static_cast<int>(PERCENTAGE(rect.getSizeY()) * static_cast<float>(LINES));
    int posX = static_cast<int>(PERCENTAGE(rect.getPositionX()) * static_cast<float>(COLS));
    int posY = static_cast<int>(PERCENTAGE(rect.getPositionY()) * static_cast<float>(LINES));
    int color = this->getNcursesColor(rect.getColor());

    attron(COLOR_PAIR(color));
    for (int x = 0; x < maxSizeX; x++)
        for (int y = 0; y < maxSizeY; y++)
            mvprintw(y + posY, x + posX, "X");
    attroff(COLOR_PAIR(color));
}

void Graphic::Ncurses::drawScreen() {
    refresh();
    auto now = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_tick).count();

    std::cerr << delta << std::endl;
    if (delta < Core::Core::FRAME_PER_TIME)
        std::this_thread::sleep_for(std::chrono::milliseconds(Core::Core::FRAME_PER_TIME - delta));
    this->_tick = now;
}

void Graphic::Ncurses::drawSprite(Sprite sprite) {
    (void) sprite;
    std::cerr << "Draw sprite cannot be implemented in ncurses" << std::endl;
}

void Graphic::Ncurses::drawText(Text text) {
    mvprintw(
        static_cast<int>(PERCENTAGE(text.getPositionY()) * static_cast<float>(LINES)),
        static_cast<int>(PERCENTAGE(text.getPositionX()) * static_cast<float>(COLS)),
        "%s", text.getText().c_str());
}

std::string Graphic::Ncurses::handleEvent() {
    int c = getch();

    switch (c) {
        case 'r':
            return (KeyboardEvent_s::RESTART);
        case 'c':
            return (KeyboardEvent_s::PREV_GAME);
        case 'a':
            return (KeyboardEvent_s::NEXT_GRAPHIC);
        case 'w':
            return (KeyboardEvent_s::PREV_GRAPHIC);
        case 'e':
            return (KeyboardEvent_s::NEXT_GAME);
        case KEY_ESCAPE:
            return (KeyboardEvent_s::ESC);
        case KEY_UP:
        case 'z':
            return (KeyboardEvent_s::UP);
        case KEY_DOWN:
        case 's':
            return (KeyboardEvent_s::DOWN);
        case KEY_LEFT:
        case 'q':
            return (KeyboardEvent_s::LEFT);
        case KEY_RIGHT:
        case 'd':
            return (KeyboardEvent_s::RIGHT);
        case KEY_ENTER:
            return (KeyboardEvent_s::ENTER);
        default:
            return (KeyboardEvent_s::UNKNOWN);
    }
}

bool Graphic::Ncurses::isOperational() {
    return (this->_alive);
}

int Graphic::Ncurses::getNcursesColor(Color color) {
    auto index = std::find(Ncurses::TRANSLATE_COLORS.begin(),
        Ncurses::TRANSLATE_COLORS.end(), color);
    if (index != Ncurses::TRANSLATE_COLORS.end())
        return (std::distance(Ncurses::TRANSLATE_COLORS.begin(), index));
    return (COLOR_WHITE);
}
