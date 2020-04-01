/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_SCORE_HPP_
#define OOP_ARCADE_2019_SCORE_HPP_

#include <string>
#include <list>

namespace Score {
    class Game {
        public:
            Game() = default;

            void addLetter(const char &letter);
            const char &getLetter(const std::size_t idx) const;
            void setLetter(const std::size_t idx, const char c);
            void save() const;
            std::string getAuthor() const;
            void setScore(const std::size_t score);
            void setGame(const std::string &game);
            void reset();
            void removeLastLetter();

            static const std::size_t MAX_AUTHOR_NAME = 8;

        private:
            std::string _author;
            std::string _game;
            int _amount;
    };

    class File {
        public:
            explicit File(const std::string &content) noexcept;
            File() = default;

            class PlayerData {
                public:
                    PlayerData(const std::string &name, const long score);
                    std::string toStr() const;

                    bool operator>(const PlayerData &a) const {
                        return (this->_score < a._score);
                    }
                    std::string _name;
                    long _score;
            };
            void addEntry(const PlayerData &user);

            std::list<PlayerData> getListUser();
        private:
            void sort();
            std::list<PlayerData> _formatted;
    };


    namespace Exceptions {
        class InvalidFile : public std::exception {
            public:
                InvalidFile() = default;
                const char *what() const noexcept override;
        };
    }
}


#endif //OOP_ARCADE_2019_SCORE_HPP
