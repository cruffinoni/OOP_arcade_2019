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
    for (Vector2i &superGom : this->_superGoms) {
        pos.x = static_cast<float>(superGom.x);
        pos.y = static_cast<float>(superGom.y);
        renderer.drawCircle(Circle {
                pos,
                this->DEFAULT_SUPERGOM_SIZE,
                this->PACGOM_COLOR
        });
    }
    for (enemy_s &enemy : this->_enemies) {
        pos.x = static_cast<float>(enemy.position.x);
        pos.y = static_cast<float>(enemy.position.y);
        if (!enemy.isDead)
            renderer.drawCircle(Circle {
                pos,
                this->DEFAULT_ENTITY_SIZE,
                this->_player.super ? this->FEAR_ENEMY_COLOR : this->ENEMY_COLOR
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
    renderer.drawText(Text {
        std::string("Your score: " + std::to_string(this->_player.score) +
        "\nPress R to restart the game\nPress ESC to exit the game"),
        {30.f, 40.f},
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
