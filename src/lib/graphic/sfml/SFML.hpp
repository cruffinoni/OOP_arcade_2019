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
    class SFML : public IGraphicRenderer {
        public:
            SFML();
            ~SFML();

            void clearScreen() override;
            void drawCircle(Circle circle) override;
            void drawRect(Rect rect) override;
            void drawScreen() override;
            void drawSprite(Sprite sprite) override;
            void drawText(Text text) override;

        private:
            sf::RenderWindow *_window;

            std::vector<sf::RectangleShape *> _forms;
            IEventIterator *event;
    };
}



#endif //OOP_ARCADE_2019_SFML_HPP
