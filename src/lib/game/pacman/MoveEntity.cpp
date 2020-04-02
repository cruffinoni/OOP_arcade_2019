/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** MoveEntity.cpp
*/

#include <algorithm>
#include "Pacman.hpp"

void Game::Pacman::movePlayer() {
    MOVES_STATES moveState;

    switch (this->_player.direction) {
        case NORTH:
            moveState = checkMove(this->_player.position, NORTH);
            switch (moveState) {
                case NONE:
                    this->_player.position.y -= DEFAULT_SQUARE_SIZE.y;
                    this->_player.direction = NORTH;
                    break;
                case WALL:
                    this->_player.direction = IDLE;
                    break;
                case ENEMY:
                    this->_player.direction = IDLE;
                    break;
                case PLAYER:
                    return;
            }
            break;
        case SOUTH:
            moveState = checkMove(this->_player.position, SOUTH);
            switch (moveState) {
                case NONE:
                    this->_player.position.y += DEFAULT_SQUARE_SIZE.y;
                    this->_player.direction = SOUTH;
                    break;
                case WALL:
                    this->_player.direction = IDLE;
                    break;
                case ENEMY:
                    this->_player.direction = IDLE;
                    break;
                case PLAYER:
                    return;
            }
            break;
        case EAST:
            moveState = checkMove(this->_player.position, EAST);
            switch (moveState) {
                case NONE:
                    this->_player.position.x += DEFAULT_SQUARE_SIZE.x;
                    this->_player.direction = EAST;
                    break;
                case WALL:
                    this->_player.direction = IDLE;
                    break;
                case ENEMY:
                    this->_player.direction = IDLE;
                    break;
                case PLAYER:
                    return;
            }
            break;
        case WEST:
            moveState = checkMove(this->_player.position, WEST);
            switch (moveState) {
                case NONE:
                    this->_player.position.x -= DEFAULT_SQUARE_SIZE.x;
                    this->_player.direction = WEST;
                    break;
                case WALL:
                    this->_player.direction = IDLE;
                    break;
                case ENEMY:
                    this->_player.direction = IDLE;
                    break;
                case PLAYER:
                    return;
            }
            break;
        case IDLE:
            break;
    }
    this->_player.elapsedTime = 0;
    if (std::count(this->_pacGoms.begin(), this->_pacGoms.end(), this->_player.position) > 0) {
        this->_pacGoms.remove(this->_player.position);
        this->_player.score += 10;
    }
}

void Game::Pacman::moveEnemy(enemy_s &enemy) {

}

Game::Pacman::MOVES_STATES
Game::Pacman::checkMove(Vector2i entityPos, PLAYER_DIRECTION playerDirection) {
    switch (playerDirection) {
        case IDLE:
            return (NONE);
        case NORTH:
            entityPos.y -= DEFAULT_SQUARE_SIZE.y;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            if (entityPos == this->_player.position)
                return (PLAYER);
            return (NONE);
        case SOUTH:
            entityPos.y += DEFAULT_SQUARE_SIZE.y;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            if (entityPos == this->_player.position)
                return (PLAYER);
            return (NONE);
        case EAST:
            entityPos.x += DEFAULT_SQUARE_SIZE.x;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            if (entityPos == this->_player.position)
                return (PLAYER);
            return (NONE);
        case WEST:
            entityPos.x -= DEFAULT_SQUARE_SIZE.x;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            if (entityPos == this->_player.position)
                return (PLAYER);
            return (NONE);
    }
}
