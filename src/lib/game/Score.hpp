/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_SCORE_HPP_
#define OOP_ARCADE_2019_SCORE_HPP_

namespace Game {
    namespace Score {
        class Score {
            public:
                Score(const int amount, const std::string &gameName);

                void addLetter(std::string &letter);
                void handleEvent(std::string &letter);
                void saveScore() const;
                std::string getAuthor() const;
                void reset();

                Score operator++(const int);
                Score &operator=(const int);
                int operator*();

            private:
                std::string _author;
                std::string _game;
                int _amount;
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
}


#endif //OOP_ARCADE_2019_SCORE_HPP
