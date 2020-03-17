/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "Drawables.hpp"

Color Color::Black() {
    return {0x40, 0x40, 0x40, 0};
}

Color Color::Red() {
    return {0xE6, 0x39, 0x00, 0};
}

Color Color::Blue() {
    return {0x00, 0x66, 0xFF, 0};
}

Color Color::Green() {
    return {0x00, 0x99, 0x00, 0};
}

Color Color::White() {
    return {0xFF, 0xFF, 0xFF, 0};
}

Color Color::Transparent() {
    return {0, 0, 0, 255};
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

APosition::APosition(const Vector2f &pos) : _pos(pos) {
}

void APosition::setPosition(const Vector2f pos) {
    this->_pos = pos;
}

void APosition::setPositionX(float posX) {
    this->_pos.x = posX;
}

void APosition::setPositionY(float posY) {
    this->_pos.y = posY;
}

void APosition::move(const Vector2f pos) {
    this->_pos = pos;
}

void APosition::moveX(float movx) {
    this->_pos.x = movx;
}

void APosition::moveY(float movy) {
    this->_pos.y = movy;
}

Vector2f APosition::getPosition(void) const {
    return Vector2f(_pos.x, _pos.y);
}

float APosition::getPositionX(void) const {
    return this->_pos.x;
}

float APosition::getPositionY(void) const {
    return this->_pos.x;
}

