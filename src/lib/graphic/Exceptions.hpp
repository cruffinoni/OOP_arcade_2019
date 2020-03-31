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
                LoadFontFailed(const LoadFontFailed &a) noexcept  {
                    this->_font = a._font;
                }
                explicit LoadFontFailed(const std::string &fontName) noexcept {
                    this->_font = fontName;
                }
                const char *what() const noexcept override  {
                    static const std::string message =
                        "The font " + this->_font + " can not be loaded. Please verify the entered path\n";
                    return (message.c_str());
                }

            private:
                std::string _font;
        };
    }
}


#endif //OOP_ARCADE_2019_EXCEPTIONS_HPP
