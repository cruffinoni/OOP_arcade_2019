/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_EXCEPTIONS_HPP
#define OOP_ARCADE_2019_EXCEPTIONS_HPP

#include <string>

namespace DLLoader {
    namespace Exceptions {
        class NotFound : std::exception {
            public:
            NotFound() noexcept = default;
            const char *what(const std::string &DLLPath) const noexcept override;
        };

        class InvalidEntryPoint : std::exception {
            public:
                InvalidEntryPoint() noexcept = default;
                const char *what(const std::string &)
        };
    }
}


#endif //OOP_ARCADE_2019_EXCEPTIONS_HPP
