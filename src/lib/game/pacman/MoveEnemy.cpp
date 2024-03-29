/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** MoveEnemy.cpp
*/

#include "Pacman.hpp"

void Game::Pacman::moveEnemy(enemy_s &enemy) {
    MOVES_STATES tmpState;
    ENTITY_DIRECTION enemyDirection;

    if (!enemy.isEatable) {
        enemyDirection = this->randomPosition(enemy.position);
    } else {
        enemyDirection = this->randomPosition(enemy.position);
    }
    switch (enemyDirection) {
        case NORTH:
            tmpState = checkMove(enemy.position, NORTH);
            switch (tmpState) {
                case NONE:
                    enemy.position.y -= DEFAULT_SQUARE_SIZE.y;
                    break;
                case PLAYER:
                    if (!enemy.isEatable) {
                        this->_state = SCORE;
                    }
                    break;
                default:
                    break;
            }
            break;
        case SOUTH:
            tmpState = checkMove(enemy.position, SOUTH);
            switch (tmpState) {
                case NONE:
                    enemy.position.y += DEFAULT_SQUARE_SIZE.y;
                    break;
                case PLAYER:
                    if (!enemy.isEatable) {
                        this->_state = SCORE;
                    }
                    break;
                default:
                    break;
            }
            break;
        case EAST:
            tmpState = checkMove(enemy.position, EAST);
            switch (tmpState) {
                case NONE:
                    enemy.position.x += DEFAULT_SQUARE_SIZE.x;
                    break;
                case PLAYER:
                    if (!enemy.isEatable) {
                        this->_state = SCORE;
                    }
                    break;
                default:
                    break;
            }
            break;
        case WEST:
            tmpState = checkMove(enemy.position, WEST);
            switch (tmpState) {
                case NONE:
                    enemy.position.x -= DEFAULT_SQUARE_SIZE.x;
                    break;
                case PLAYER:
                    if (!enemy.isEatable) {
                        this->_state = SCORE;
                    }
                    break;
                default:
                    break;
            }
            break;
        case IDLE:
            break;
    }
    enemy.elapsedTime = 0;
}
