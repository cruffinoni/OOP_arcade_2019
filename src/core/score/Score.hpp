/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_SCORE_HPP_
#define OOP_ARCADE_2019_SCORE_HPP_

#include <string>

namespace Score {
    class Game {
        public:
            Game(const int amount, const std::string &gameName);

            void addLetter(std::string &letter);
            void handleEvent(std::string &letter);
            void saveScore() const;
            std::string getAuthor() const;
            void reset();

            Game operator++(const int);
            Game &operator=(const int);
            int operator*();

        private:
            std::string _author;
            std::string _game;
            int _amount;
    };

    class File {
        public:
            File(const std::string &file);


    };

    namespace Exceptions {
        class InvalidFile : public std::exception {
            public:
                InvalidFile() = default;
                const char *what() const noexcept override;
        };
        class FileSaved : public std::exception {
            public:
                FileSaved() = default;
                const char *what() const noexcept override;
        };
    }
}


#endif //OOP_ARCADE_2019_SCORE_HPP
