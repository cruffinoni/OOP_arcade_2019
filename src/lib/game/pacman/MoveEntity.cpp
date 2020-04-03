/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** MoveEntity.cpp
*/

#include <algorithm>
#include "Pacman.hpp"

Game::Pacman::MOVES_STATES
Game::Pacman::checkMove(Vector2i entityPos, ENTITY_DIRECTION playerDirection) {
    switch (playerDirection) {
        case IDLE:
            return (NONE);
        case NORTH:
            entityPos.y -= DEFAULT_SQUARE_SIZE.y;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            if (entityPos == this->_player.position)
                return (PLAYER);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            return (NONE);
        case SOUTH:
            entityPos.y += DEFAULT_SQUARE_SIZE.y;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            if (entityPos == this->_player.position)
                return (PLAYER);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            return (NONE);
        case EAST:
            entityPos.x += DEFAULT_SQUARE_SIZE.x;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            if (entityPos == this->_player.position)
                return (PLAYER);
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            return (NONE);
        case WEST:
            entityPos.x -= DEFAULT_SQUARE_SIZE.x;
            if (std::count(this->_map.begin(), this->_map.end(), entityPos) > 0)
                return (WALL);
            if (entityPos == this->_player.position) {
                return (PLAYER);
            }
            for (enemy_s &enemy : this->_enemies) {
                if (entityPos == enemy.position)
                    return (ENEMY);
            }
            return (NONE);
    }
    return (NONE);
}
