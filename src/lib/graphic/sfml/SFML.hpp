/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_SFML_HPP
#define OOP_ARCADE_2019_SFML_HPP

#include <SFML/Graphics.hpp>
#include "graphic/IGraphic.hpp"

namespace Graphic {
    class SFML : public IGraphic {
        public:
            SFML();
            ~SFML();

            #ifndef PERCENTAGE
                #define PERCENTAGE(a) (a / 100.f)
            #endif

            void clearScreen() override;

            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

            std::string handleEvent() override;
            bool isOperational() override;

            static const uint WINDOW_WIDTH = 800;
            static const uint WINDOW_HEIGHT = 600;

        private:
            sf::RenderWindow *_window;
            std::vector<sf::Drawable *> _entities;
            sf::Font *_font;
            bool _operational;
    };
}



#endif //OOP_ARCADE_2019_SFML_HPP
