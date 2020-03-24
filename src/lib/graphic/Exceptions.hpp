/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_EXCEPTIONS_GRAPHIC_HPP_
#define OOP_ARCADE_2019_EXCEPTIONS_GRAPHIC_HPP_

#include <string>

namespace Graphic {
    namespace Exceptions {
        class LoadFontFailed : public std::exception {
            public:
                LoadFontFailed(const LoadFontFailed &) noexcept;
                explicit LoadFontFailed(const std::string &fontName) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _font;
        };
    }
}


#endif //OOP_ARCADE_2019_EXCEPTIONS_HPP
