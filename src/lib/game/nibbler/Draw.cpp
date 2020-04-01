/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Nibbler.hpp"

static const Vector2f DEFAULT_TEXT_SIZE = {10.f, 5.f};

void Game::Nibbler::drawGame(IGraphicRenderer &renderer) {
    std::size_t count = 0;

    for (auto &node : this->_player.position) {
        if (count++ % 2 == 0) {
            renderer.drawRect(Rect {
                node,
                this->DEFAULT_SQUARE_SIZE,
                Game::Nibbler::SNAKE_COLOR_1,
            });
        } else {
            renderer.drawRect(Rect {
                node,
                this->DEFAULT_SQUARE_SIZE,
                Game::Nibbler::SNAKE_COLOR_2,
            });
        }
    }
    for (auto &mapNode : this->_map) {
        renderer.drawRect(Rect {
            mapNode,
            this->DEFAULT_SQUARE_SIZE,
            Game::Nibbler::WALL_COLOR,
        });
    }
    renderer.drawRect(Rect {
        this->_reward,
        this->DEFAULT_SQUARE_SIZE,
        Game::Nibbler::REWARD_COLOR,
    });
    renderer.drawText(Text {
        std::string("Score: " + std::to_string(this->_player.score)),
        {45.f, 0.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
}

void Game::Nibbler::drawScore(IGraphicRenderer &renderer) {
    renderer.drawText(Text {
        std::string("Your score: " + std::to_string(this->_player.score) +
        "\nPress R to restart the game\nPress ESC to exit the game"),
        {30.f, 40.f},
        DEFAULT_TEXT_SIZE,
        Color::Black(),
    });
}

void Game::Nibbler::handleRender(IGraphicRenderer &renderer) {
    if (this->_state == Nibbler::GAME_STATE::GAME)
        this->drawGame(renderer);
    else
        this->drawScore(renderer);
}
