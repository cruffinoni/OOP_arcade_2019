/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pathfinding.cpp
*/

#include "Pacman.hpp"

Game::Pacman::ENTITY_DIRECTION
Game::Pacman::findPathToPlayer(Vector2i startingPoint, Vector2i goalPoint) {
    std::vector<std::pair<ENTITY_DIRECTION, MOVES_STATES>> movesPossible;
    MOVES_STATES tmpState;

    tmpState = this->checkMove(startingPoint, NORTH);
    if (tmpState != WALL && tmpState != ENEMY)
        movesPossible.emplace_back(std::pair<ENTITY_DIRECTION, MOVES_STATES>(NORTH, tmpState));
    tmpState = this->checkMove(startingPoint, SOUTH);
    if (tmpState != WALL && tmpState != ENEMY)
        movesPossible.emplace_back(std::pair<ENTITY_DIRECTION, MOVES_STATES>(SOUTH, tmpState));
    tmpState = this->checkMove(startingPoint, WEST);
    if (tmpState != WALL && tmpState != ENEMY)
        movesPossible.emplace_back(std::pair<ENTITY_DIRECTION, MOVES_STATES>(WEST, tmpState));
    tmpState = this->checkMove(startingPoint, EAST);
    if (tmpState != WALL && tmpState != ENEMY)
        movesPossible.emplace_back(std::pair<ENTITY_DIRECTION, MOVES_STATES>(EAST, tmpState));
    if (movesPossible.empty())
        return (IDLE);
    return (WEST);
}