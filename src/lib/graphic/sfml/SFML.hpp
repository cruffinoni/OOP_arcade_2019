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

            uint createForm(Arcade::Vector position, Arcade::Vector size) override;

        private:
            sf::RenderWindow *_window;
    };
}



#endif //OOP_ARCADE_2019_SFML_HPP
