/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Exceptions.hpp"

Graphic::Exceptions::LoadFontFailed::LoadFontFailed(
    const Graphic::Exceptions::LoadFontFailed &fontFailed) noexcept {
    this->_font = fontFailed._font;
}

Graphic::Exceptions::LoadFontFailed::LoadFontFailed(
    const std::string &fontName) noexcept {
    this->_font = fontName;
}

const char *Graphic::Exceptions::LoadFontFailed::what() const noexcept {
    static const std::string message =
        "The font " + this->_font + " can not be loaded. Please verify the entered path\n";
    return (message.c_str());
}

