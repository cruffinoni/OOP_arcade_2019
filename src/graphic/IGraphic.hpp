/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Interface for graphic libraries
*/

#ifndef SRC_ARCADE_IGRAPHIC
#define SRC_ARCADE_IGRAPHIC

namespace Arcade {
    struct fVector {
        float x;
        float y;
    };
    struct uVector {
        uint x;
        uint y;
    };

    enum Color {
        WHITE,
        BLACK,
        RED,
        BLUE,
        CYAN,
        PURPLE,
        GREEN,
        YELLOW,
        GREY
    };

    class IGraphic {
        public:
            virtual ~IGraphic() = default;

            virtual uint createForm(const Arcade::fVector position,
                const Arcade::fVector size) = 0;
            virtual void process() = 0;
            virtual bool windowIsOpen() = 0;
    };
}

#endif
