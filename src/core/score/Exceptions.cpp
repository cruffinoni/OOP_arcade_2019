/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "core/score/Score.hpp"

const char *Score::Exceptions::InvalidFile::what() const noexcept {
    return ("Unable to create or write inside the score file.\n");
}

const char *Score::Exceptions::FileSaved::what() const noexcept {
    return ("No error so far, you may not display that\n");
}