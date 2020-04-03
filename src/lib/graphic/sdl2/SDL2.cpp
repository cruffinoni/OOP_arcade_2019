/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mainfile for SDL2 graphic lib
*/

#include <iostream>
#include "core/Core.hpp"
#include "SDL2.hpp"

static std::shared_ptr<Graphic::SDL2 *> instance;

extern "C" {
    IGraphic *loadLibrary() {
        return (*instance);
    }

    __attribute__((constructor)) void load() {
        instance = std::make_shared<Graphic::SDL2 *>(new Graphic::SDL2());
    }

    __attribute__((destructor)) void unload() {
    }
}

Graphic::SDL2::SDL2() : _ticks(0) {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _font = TTF_OpenFont(FONT_FILENAME, 18);
    if (this->_font == nullptr)
        throw Graphic::Exceptions::LoadFontFailed(FONT_FILENAME);
    _running = true;
}

Graphic::SDL2::~SDL2() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

void Graphic::SDL2::clearScreen() {
    this->_ticks = SDL_GetTicks();
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
    SDL_Rect sdlRect = {static_cast<int>PERCENTAGE(rect.getPositionX() * Graphic::SDL2::WINDOW_WIDTH),
                        static_cast<int>PERCENTAGE(rect.getPositionY() * Graphic::SDL2::WINDOW_HEIGHT),
                        static_cast<int>PERCENTAGE(rect.getSizeX() * Graphic::SDL2::WINDOW_WIDTH),
                        static_cast<int>PERCENTAGE(rect.getSizeY() * Graphic::SDL2::WINDOW_HEIGHT)};

    SDL_SetRenderDrawColor(_renderer, rect.getColor().red, rect.getColor().green, rect.getColor().blue, rect.getColor().alpha);
    SDL_RenderFillRect(_renderer, &sdlRect);
}

void Graphic::SDL2::drawScreen() {
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(_renderer);
    uint32_t now = SDL_GetTicks();
    uint32_t delta = now - this->_ticks;

    if (delta < Core::Core::FRAME_PER_TIME)
        SDL_Delay(Core::Core::FRAME_PER_TIME - delta);
    this->_ticks = now;
}

void Graphic::SDL2::drawSprite(Sprite sprite) {
    std::cerr << "Draw sprite is not supported in SDL2 (sprite name: " << sprite.getTextureName() << ")" << std::endl;
}

void Graphic::SDL2::drawText(Text text) {
    SDL_Color color = {text.getColorRed(), text.getColorGreen(), text.getColorBlue(), text.getColorAlpha()};
    SDL_Surface *surface = TTF_RenderText_Solid(_font, text.getText().c_str(), color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect sdlRect = {static_cast<int>(PERCENTAGE(text.getPositionX()) * Graphic::SDL2::WINDOW_WIDTH),
                        static_cast<int>(PERCENTAGE(text.getPositionY()) * Graphic::SDL2::WINDOW_HEIGHT),
                        static_cast<int>(PERCENTAGE(text.getSizeX()) * Graphic::SDL2::WINDOW_WIDTH),
                        static_cast<int>(PERCENTAGE(text.getSizeY()) * Graphic::SDL2::WINDOW_HEIGHT)};
    SDL_RenderCopy(_renderer, message, nullptr, &sdlRect);
}

std::string Graphic::SDL2::handleEvent() {
    SDL_Event events;

    SDL_PollEvent(&events);
    switch (events.type) {
        case SDL_QUIT:
            _running = false;
            return (KeyboardEvent_s::UNKNOWN);
        case SDL_KEYDOWN:
            if (events.key.repeat)
                return (KeyboardEvent_s::UNKNOWN);
            switch (events.key.keysym.sym) {
                case SDLK_a:
                    return (KeyboardEvent_s::NEXT_GRAPHIC);
                case SDLK_ESCAPE:
                    return (KeyboardEvent_s::ESC);
                case SDLK_c:
                    return (KeyboardEvent_s::PREV_GAME);
                case SDLK_e:
                    return (KeyboardEvent_s::NEXT_GAME);
                case SDLK_w:
                    return (KeyboardEvent_s::PREV_GRAPHIC);
                case SDLK_RETURN:
                    return (KeyboardEvent_s::ENTER);
                case SDLK_r:
                    return (KeyboardEvent_s::RESTART);
                case SDLK_UP:
                case SDLK_z:
                    return (KeyboardEvent_s::UP);
                case SDLK_DOWN:
                case SDLK_s:
                    return (KeyboardEvent_s::DOWN);
                case SDLK_LEFT:
                case SDLK_q:
                    return (KeyboardEvent_s::LEFT);
                case SDLK_RIGHT:
                case SDLK_d:
                    return (KeyboardEvent_s::RIGHT);
                case SDLK_SPACE:
                    return (KeyboardEvent_s::SPACE);
                default:
                    return (KeyboardEvent_s::UNKNOWN);
            }
        default:
            break;
    }
    return (KeyboardEvent_s::UNKNOWN);
}

bool Graphic::SDL2::isOperational() {
    return (_running);
}
