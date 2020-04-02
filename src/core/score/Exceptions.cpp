/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score Exceptions
*/

#include "core/score/Score.hpp"

const char *Score::Exceptions::InvalidFile::what() const noexcept {
    return ("Unable to create or write inside the score file.");
}
