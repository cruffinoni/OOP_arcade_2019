/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Draw.cpp - File used to draw on screen Pacman game elements
*/

#include "Pacman.hpp"

static const Vector2f DEFAULT_TEXT_SIZE = {10.f, 5.f};

void Game::Pacman::drawGame(IGraphicRenderer &renderer) {
    Vector2f pos(0.0f, 0.0f);
    for (Vector2i &mapNode : this->_map) {
        pos.x = static_cast<float>(mapNode.x);
        pos.y = static_cast<float>(mapNode.y);
        renderer.drawRect(Rect {
            pos,
            this->DEFAULT_SQUARE_SIZE,
            Game::Pacman::WALL_COLOR,
        });
    }
    for (Vector2i &pacGom : this->_pacGoms) {
        pos.x = static_cast<float>(pacGom.x);
        pos.y = static_cast<float>(pacGom.y);
        renderer.drawCircle(Circle {
            pos,
            this->DEFAULT_PACGOM_SIZE,
            this->PACGOM_COLOR
        });
    }
    for (enemy_s &enemy : this->_enemies) {
        pos.x = static_cast<float>(enemy.position.x);
        pos.y = static_cast<float>(enemy.position.y);
        renderer.drawCircle(Circle {
            pos,
            this->DEFAULT_ENTITY_SIZE,
            this->ENEMY_COLOR
        });
    }
    pos.x = static_cast<float>(this->_player.position.x);
    pos.y = static_cast<float>(this->_player.position.y);
    renderer.drawCircle(Circle {
        pos,
        this->DEFAULT_ENTITY_SIZE,
        this->PACMAN_COLOR
    });
    renderer.drawText(Text {
        std::string("Score: " + std::to_string(this->_player.score)),
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
        std::string("Your score: " + std::to_string(this->_player.score) +
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
        "this->_player.score.getAuthor()", //TODO : change for new score owner
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
