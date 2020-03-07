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
        class InvalidDLL : std::exception {
            public:
                InvalidDLL(const InvalidDLL &a) noexcept;
                explicit InvalidDLL(const std::string &DLLPath) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _dllName;
        };

        class InvalidEntryPoint : std::exception {
            public:
                InvalidEntryPoint(const InvalidEntryPoint &a) noexcept;
                explicit InvalidEntryPoint(const std::string &DLLName) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _dllName;
        };
    }
}


#endif //OOP_ARCADE_2019_EXCEPTIONS_HPP
