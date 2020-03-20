/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <iostream>
#include "SDL2.hpp"

static Graphic::SDL2 *instance;

extern "C" {
    IGraphicRenderer *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[graphic] constructor SDL2 called\n");
        instance = new Graphic::SDL2();
    }

    __attribute__((destructor)) void unload() {
        printf("[graphic] destructor SDL2 called\n");
        delete instance;
    }
}

Graphic::SDL2::SDL2() {
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _running = true;
}

Graphic::SDL2::~SDL2() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

void Graphic::SDL2::clearScreen() {
    SDL_RenderClear(_renderer);
}

void Graphic::SDL2::drawCircle(Circle circle) {
    int dx;
    int dy;
    int circleRadius = static_cast<int>(PERCENTAGE(circle.getSizeX()) * Graphic::SDL2::WINDOW_WIDTH);

    SDL_SetRenderDrawColor(this->_renderer, circle.getColor().red,
        circle.getColor().green, circle.getColor().blue, circle.getColor().alpha);
    for (int w = 0; w < circleRadius * 2; w++) {
        for (int h = 0; h < circleRadius * 2; h++) {
            dx = circleRadius - w;
            dy = circleRadius - h;
            if ((std::pow(dx, 2) + std::pow(dy, 2)) <= (circleRadius * circleRadius)) {
                SDL_RenderDrawPoint(this->_renderer,
                    static_cast<int>(PERCENTAGE(circle.getPositionX()) * Graphic::SDL2::WINDOW_WIDTH) + dx,
                    static_cast<int>(PERCENTAGE(circle.getPositionY()) * Graphic::SDL2::WINDOW_HEIGHT) + dy
                    );
            }
        }
    }
}

void Graphic::SDL2::drawRect(Rect rect) {
    SDL_Rect sdlRect = {(int) PERCENTAGE(rect.getPositionX() * Graphic::SDL2::WINDOW_WIDTH),
                        (int) PERCENTAGE(rect.getPositionY() * Graphic::SDL2::WINDOW_HEIGHT),
                        (int) PERCENTAGE(rect.getSizeX() * Graphic::SDL2::WINDOW_WIDTH),
                        (int) PERCENTAGE(rect.getSizeY() * Graphic::SDL2::WINDOW_HEIGHT)};

    SDL_SetRenderDrawColor(_renderer, rect.getColor().red, rect.getColor().green, rect.getColor().blue, rect.getColor().alpha);
    SDL_RenderFillRect(_renderer, &sdlRect);
}

void Graphic::SDL2::drawScreen() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(_renderer);
}

void Graphic::SDL2::drawSprite(Sprite sprite) {
    std::cerr << "Draw sprite is not supported in SDL2 (sprite name: " << sprite.getTextureName() << ")" << std::endl;
}

void Graphic::SDL2::drawText(Text text) {

}

std::string Graphic::SDL2::handleEvent() {
    SDL_Event events;

    SDL_PollEvent(&events);
    switch (events.type) {
        case SDL_QUIT:
            _running = false;
            return (IEventIterator::KEY_UNKNOWN);
        case SDL_KEYDOWN:
            if (events.key.repeat)
                return (IEventIterator::KEY_UNKNOWN);
            switch (events.key.keysym.sym) {
                case SDLK_a:
                    return (IEventIterator::KEY_A);
                case SDLK_b:
                    return (IEventIterator::KEY_B);
                case SDLK_ESCAPE:
                    this->_running = false;
                    return (IEventIterator::KEY_UNKNOWN);
                case SDLK_c:
                    return (IEventIterator::KEY_C);
                case SDLK_d:
                    return (IEventIterator::KEY_D);
                case SDLK_r:
                    return (IEventIterator::KEY_R);
                case SDLK_UP:
                    return (IEventIterator::KEY_UP);
                case SDLK_DOWN:
                    return (IEventIterator::KEY_DOWN);
                case SDLK_LEFT:
                    return (IEventIterator::KEY_LEFT);
                case SDLK_RIGHT:
                    return (IEventIterator::KEY_RIGHT);
                default:
                    return (IEventIterator::KEY_UNKNOWN);
            }
        default:
            break;
    }
    return (IEventIterator::KEY_UNKNOWN);
}

bool Graphic::SDL2::isOperational() {
    return (_running);
}
