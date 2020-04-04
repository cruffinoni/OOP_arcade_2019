/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Class header file for SFML graphic lib
*/

#ifndef OOP_ARCADE_2019_SFML_HPP
#define OOP_ARCADE_2019_SFML_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "graphic/IGraphic.hpp"

/**
 * Graphic namespace include all graphical library.
 */
namespace Graphic {
    class SFML : public IGraphic {
        public:
            /**
             * Basic constructor for SFML. It creates the window with some
             * specific parameters (framerate, window's name, ...).
             */
            SFML();
            ~SFML() override = default;
            void clearScreen() override;

            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

            std::string handleEvent() override;
            bool isOperational() override;

            static const uint WINDOW_WIDTH = 800;
            static const uint WINDOW_HEIGHT = 800;

        private:
            std::shared_ptr<sf::RenderWindow> _window;
            std::vector<std::shared_ptr<sf::Drawable>> _entities;
            std::shared_ptr<sf::Font> _font;
            bool _operational;
    };
}

#endif //OOP_ARCADE_2019_SFML_HPP
