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
    class SFML : public Arcade::IGraphic {
        public:
            SFML();
            ~SFML() override;

            uint createForm(const Arcade::fVector position,
                const Arcade::fVector size) override;
            void process() override;
            bool windowIsOpen() override;

        private:
            sf::RenderWindow *_window;

            std::vector<sf::RectangleShape *> _forms;
    };
}



#endif //OOP_ARCADE_2019_SFML_HPP
