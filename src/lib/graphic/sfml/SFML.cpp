/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mainfile for SFML graphic lib
*/

#include <memory>
#include "lib/graphic/Exceptions.hpp"
#include "SFML.hpp"

static std::shared_ptr<Graphic::SFML *> instance;

extern "C" {
    IGraphic *entry() {
        return (*instance);
    }

    __attribute__((constructor)) void load() {
        instance = std::make_shared<Graphic::SFML *>(new Graphic::SFML());
    }

    __attribute__((destructor)) void unload() {
    }
}

Graphic::SFML::SFML() : _operational(true) {
    this->_font = std::make_shared<sf::Font>();
    this->_window = std::make_shared<sf::RenderWindow>();
    this->_window->setFramerateLimit(60);
    this->_window->create({Graphic::SFML::WINDOW_WIDTH, Graphic::SFML::WINDOW_HEIGHT},
        "Arcade", sf::Style::Titlebar);
    if (!this->_font->loadFromFile(FONT_FILENAME))
        throw Graphic::Exceptions::LoadFontFailed(FONT_FILENAME);
}

void Graphic::SFML::clearScreen() {
    this->_window->clear();
    this->_entities.clear();
}

void Graphic::SFML::drawCircle(Circle circle) {
    auto entity = std::make_shared<sf::CircleShape>(PERCENTAGE(circle.getSizeX()) * Graphic::SFML::WINDOW_WIDTH);

    entity->setPosition(PERCENTAGE(circle.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
        PERCENTAGE(circle.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
    entity->setFillColor(sf::Color(circle.getColorRed(), circle.getColorGreen(), circle.getColorBlue()));
    this->_entities.push_back(entity);
}

void Graphic::SFML::drawRect(Rect rect) {
    auto entity = std::make_shared<sf::RectangleShape>(sf::Vector2f {
        PERCENTAGE(rect.getSizeX()) * Graphic::SFML::WINDOW_WIDTH,
        PERCENTAGE(rect.getSizeY()) * Graphic::SFML::WINDOW_HEIGHT}
        );
    entity->setPosition(PERCENTAGE(rect.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
        PERCENTAGE(rect.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
    entity->setFillColor(sf::Color(rect.getColorRed(), rect.getColorGreen(), rect.getColorBlue()));
    this->_entities.push_back(entity);
}

void Graphic::SFML::drawSprite(Sprite sprite) {
    auto texture = new sf::Texture();
    texture->loadFromFile(sprite.getTextureName(), sf::IntRect {
        {0, 0},
        {
            static_cast<int>(PERCENTAGE(sprite.getSizeX()) * Graphic::SFML::WINDOW_WIDTH),
         static_cast<int>(PERCENTAGE(sprite.getSizeY()) * Graphic::SFML::WINDOW_HEIGHT)
         },
    });

    auto entity = std::make_shared<sf::Sprite>(*texture);
    entity->setPosition(PERCENTAGE(sprite.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
        PERCENTAGE(sprite.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
    this->_entities.push_back(entity);
}

void Graphic::SFML::drawText(Text text) {
    auto entity = std::make_shared<sf::Text>(text.getText(), *this->_font);

    entity->setCharacterSize(static_cast<int>((PERCENTAGE(text.getSizeX()) + 0.8) * 25));
    entity->setStyle(sf::Text::Bold);
    entity->setFillColor(sf::Color(text.getColorRed(), text.getColorGreen(), text.getColorBlue()));
    entity->setPosition(PERCENTAGE(text.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
        PERCENTAGE(text.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
    this->_entities.push_back(entity);
}

void Graphic::SFML::drawScreen() {
    for (auto &i: this->_entities)
        this->_window->draw(*i);
    this->_window->display();
}

std::string Graphic::SFML::handleEvent() {
    auto event = sf::Event();

    while (this->_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_operational = false;
                return (KeyboardEvent_s::UNKNOWN);
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        return (KeyboardEvent_s::ESC);
                    case sf::Keyboard::A:
                        return (KeyboardEvent_s::NEXT_GRAPHIC);
                    case sf::Keyboard::C:
                        return (KeyboardEvent_s::PREV_GAME);
                    case sf::Keyboard::E:
                        return (KeyboardEvent_s::NEXT_GAME);
                    case sf::Keyboard::R:
                        return (KeyboardEvent_s::RESTART);
                    case sf::Keyboard::W:
                        return (KeyboardEvent_s::PREV_GRAPHIC);
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Z:
                        return (KeyboardEvent_s::UP);
                    case sf::Keyboard::Down:
                    case sf::Keyboard::S:
                        return (KeyboardEvent_s::DOWN);
                    case sf::Keyboard::Left:
                    case sf::Keyboard::Q:
                        return (KeyboardEvent_s::LEFT);
                    case sf::Keyboard::Right:
                    case sf::Keyboard::D:
                        return (KeyboardEvent_s::RIGHT);
                    case sf::Keyboard::Return:
                        return (KeyboardEvent_s::ENTER);
                    case sf::Keyboard::Space:
                        return (KeyboardEvent_s::SPACE);
                    default:
                        return (KeyboardEvent_s::UNKNOWN);
                }
            default:
                break;
        }
    }
    return (KeyboardEvent_s::UNKNOWN);
}

bool Graphic::SFML::isOperational() {
    return (this->_operational);
}
