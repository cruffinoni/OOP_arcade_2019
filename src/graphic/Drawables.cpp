/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Drawables.hpp"

Color Color::Black() {
    return {0x40, 0x40, 0x40, 0xFF};
}

Color Color::Red() {
    return {0xE6, 0x39, 0x00, 0xFF};
}

Color Color::Blue() {
    return {0x00, 0x66, 0xFF, 0xFF};
}

Color Color::Green() {
    return {0x00, 0x99, 0x00, 0xFF};
}

Sprite::Sprite(const std::string &name, Vector2f pos, Vector2f size) : APosition(pos), ASize(size) {
    this->_textureName = name;
}

const std::string &Sprite::getTextureName(void) const {
    return (this->_textureName);
}

Text::Text(const std::string &text, Vector2f pos, Vector2f size, Color color) : APosition(pos), ASize(size), AColor(color) {
    this->_text = text;
}

const std::string &Text::getText(void) const {
    return (this->_text);
}

void Text::setText(const std::string &newText) {
    this->_text = newText;
}

Circle::Circle(Vector2f pos, Vector2f size, Color color)
    : APosition(pos), ASize(size), AColor(color) {
}

Rect::Rect(Vector2f pos, Vector2f size, Color color)
    : APosition(pos), ASize(size), AColor(color) {

}

AColor::AColor(const Color &color) : _color(color) {
}

void AColor::setColor(const Color &color) {
    this->_color = color;
}

void AColor::setColorRed(unsigned char red) {
    this->_color.red = red;
}

void AColor::setColorGreen(unsigned char green) {
    this->_color.green = green;
}

void AColor::setColorBlue(unsigned char blue) {
    this->_color.blue = blue;
}

void AColor::setColorAlpha(unsigned char alpha) {
    this->_color.alpha = alpha;
}

Color AColor::getColor(void) const {
    return (this->_color);
}

unsigned char AColor::getColorRed(void) const {
    return (this->_color.red);
}

unsigned char AColor::getColorGreen(void) const {
    return (this->_color.green);
}

unsigned char AColor::getColorBlue(void) const {
    return (this->_color.blue);
}

unsigned char AColor::getColorAlpha(void) const {
    return (this->_color.alpha);
}

ASize::ASize(const Vector2f &size) : _size(size) {
}

void ASize::setSize(const Vector2f &size) {
    this->_size = size;
}

void ASize::setSizeX(float sizeX) {
    this->_size.x = sizeX;
}

void ASize::setSizeY(float sizeY) {
    this->_size.y = sizeY;
}

Vector2f ASize::getSize(void) const {
    return (this->_size);
}

float ASize::getSizeX(void) const {
    return (this->_size.x);
}

float ASize::getSizeY(void) const {
    return (this->_size.y);
}

Vector2f::Vector2f(float pX, float pY) {
    this->x = pX;
    this->y = pY;
}
