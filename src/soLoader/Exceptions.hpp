/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_EXCEPTIONS_HPP
#define OOP_ARCADE_2019_EXCEPTIONS_HPP

#include <string>

namespace SoLoader {
    namespace Exceptions {
        class InvalidSO : std::exception {
            public:
                explicit InvalidSO(const std::string &DLLPath) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _dllName;
        };

        class InvalidEntryPoint : std::exception {
            public:
                explicit InvalidEntryPoint(const std::string &DLLName) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _dllName;
        };
    }
}


#endif //OOP_ARCADE_2019_EXCEPTIONS_HPP
