/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "lib/graphic/Exceptions.hpp"
#include "SFML.hpp"

static Graphic::SFML *instance;

extern "C" {
    IGraphic *loadLibrary() {
        return (instance);
    }

    __attribute__((constructor)) void load() {
        printf("[graphic] constructor SFML called\n");
        instance = new Graphic::SFML();
    }

    __attribute__((destructor)) void unload() {
        printf("[graphic] destructor SFML called\n");
        delete instance;
    }
}

Graphic::SFML::SFML() : _operational(true) {
    this->_window = new sf::RenderWindow({
        Graphic::SFML::WINDOW_WIDTH, Graphic::SFML::WINDOW_HEIGHT
        }, "Arcade");
    this->_window->setFramerateLimit(60);
}

Graphic::SFML::~SFML() {
    printf("delete constructor\n");
    delete this->_window;
}

void Graphic::SFML::clearScreen() {
    this->_window->clear();
    for (auto &i: this->_entities) {
        sf::Text *typeText = dynamic_cast<sf::Text *>(i);
        if (typeText != nullptr)
            delete typeText->getFont();
        delete i;
    }
    this->_entities.clear();
}

void Graphic::SFML::drawCircle(Circle circle) {
    try {
        auto entity = new sf::CircleShape(PERCENTAGE(circle.getSizeX()) * Graphic::SFML::WINDOW_WIDTH);

        entity->setPosition(PERCENTAGE(circle.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
            PERCENTAGE(circle.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
        entity->setFillColor(sf::Color(circle.getColorRed(), circle.getColorGreen(), circle.getColorBlue()));
        this->_entities.push_back(entity);
    } catch (const std::bad_alloc &e) {
        throw e;
    }
}

void Graphic::SFML::drawRect(Rect rect) {
    try {
        auto entity = new sf::RectangleShape(sf::Vector2f {
            PERCENTAGE(rect.getSizeX()) * Graphic::SFML::WINDOW_WIDTH,
            PERCENTAGE(rect.getSizeY()) * Graphic::SFML::WINDOW_HEIGHT}
            );
        entity->setPosition(PERCENTAGE(rect.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
            PERCENTAGE(rect.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
        entity->setFillColor(sf::Color(rect.getColorRed(), rect.getColorGreen(), rect.getColorBlue()));
        this->_entities.push_back(entity);
    } catch (const std::bad_alloc &e) {
        throw e;
    }
}

void Graphic::SFML::drawSprite(Sprite sprite) {
    try {
        auto texture = new sf::Texture();
        texture->loadFromFile(sprite.getTextureName(), sf::IntRect {
            {0, 0},
            {
                static_cast<int>(PERCENTAGE(sprite.getSizeX()) * Graphic::SFML::WINDOW_WIDTH),
             static_cast<int>(PERCENTAGE(sprite.getSizeY()) * Graphic::SFML::WINDOW_HEIGHT)
             },
        });

        auto entity = new sf::Sprite(*texture);
        entity->setPosition(PERCENTAGE(sprite.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
            PERCENTAGE(sprite.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
        this->_entities.push_back(entity);
    } catch (const std::bad_alloc &e) {
        throw e;
    }
}

void Graphic::SFML::drawText(Text text) {
    try {
        auto font = new sf::Font();
        if (!font->loadFromFile(Graphic::SFML::FONT_PATH))
            throw Graphic::Exceptions::LoadFontFailed(Graphic::SFML::FONT_PATH);

        auto entity = new sf::Text(text.getText(), *font);
        entity->setCharacterSize(18);
        entity->setStyle(sf::Text::Bold);
        entity->setFillColor(sf::Color(text.getColorRed(), text.getColorGreen(), text.getColorBlue()));
        entity->setPosition(PERCENTAGE(text.getPositionX()) * Graphic::SFML::WINDOW_WIDTH,
            PERCENTAGE(text.getPositionY()) * Graphic::SFML::WINDOW_HEIGHT);
        this->_entities.push_back(entity);
    } catch (const std::bad_alloc &e) {
        throw e;
    }
}

void Graphic::SFML::drawScreen() {
    for (auto &i: this->_entities) {
        //printf("Display entity: %p\n", i);
        this->_window->draw(*i);
    }
    this->_window->display();
}

std::string Graphic::SFML::handleEvent() {
    auto event = sf::Event();

    while (this->_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_operational = false;
                return (IEventIterator::KEY_UNKNOWN);
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        this->_operational = false;
                        return (IEventIterator::KEY_UNKNOWN);
                    case sf::Keyboard::A:
                        return (IEventIterator::KEY_A);
                    case sf::Keyboard::B:
                        return (IEventIterator::KEY_B);
                    case sf::Keyboard::C:
                        return (IEventIterator::KEY_C);
                    case sf::Keyboard::D:
                        return (IEventIterator::KEY_D);
                    case sf::Keyboard::R:
                        return (IEventIterator::KEY_R);
                    case sf::Keyboard::Up:
                        return (IEventIterator::KEY_UP);
                    case sf::Keyboard::Down:
                        return (IEventIterator::KEY_DOWN);
                    case sf::Keyboard::Left:
                        return (IEventIterator::KEY_LEFT);
                    case sf::Keyboard::Right:
                        return (IEventIterator::KEY_RIGHT);
                    default:
                        return (IEventIterator::KEY_UNKNOWN);
                }
            default:
                break;
        }
    }
    return (IEventIterator::KEY_UNKNOWN);
}

bool Graphic::SFML::isOperational() {
    return (this->_operational);
}
