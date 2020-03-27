/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Draw.cpp - File used to draw on screen Pacman game elements
*/

#include "Pacman.hpp"

static const Vector2f DEFAULT_TEXT_SIZE = {10.f, 5.f};

void Game::Pacman::drawGame(IGraphicRenderer &renderer) {
    for (auto &mapNode : this->_map) {
        renderer.drawRect(Rect {
            mapNode,
            this->DEFAULT_SQUARE_SIZE,
            Game::Pacman::WALL_COLOR,
        });
    }
    renderer.drawText(Text {
        std::string("Score: " + std::to_string(*this->_player.score)),
        {45.f, 0.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
}

void Game::Pacman::drawScore(IGraphicRenderer &renderer) {
    renderer.drawRect(Rect {
        {40.f, 49.f},
        {25.f, 10.f},
        {0xBF, 0xBF, 0xBF, 0xFF},
    });
    renderer.drawText(Text {
        std::string("Your score: " + std::to_string(*this->_player.score) +
                    "\nEnter you name:"),
        {40.f, 40.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
    renderer.drawText(Text {
        std::string("Press enter to confirm"),
        {40.f, 60.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
    renderer.drawText(Text {
        this->_player.score.getAuthor(),
        {40.f, 49.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
}

void Game::Pacman::handleRender(IGraphicRenderer &renderer) {
    if (this->_state == Pacman::GAME_STATE::GAME)
        this->drawGame(renderer);
    else
        this->drawScore(renderer);
}
