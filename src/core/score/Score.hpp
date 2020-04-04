/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Header file class for score
*/

#ifndef OOP_ARCADE_2019_SCORE_HPP_
#define OOP_ARCADE_2019_SCORE_HPP_

#include <string>
#include <list>

/**
 * Namespace Score:

 * The score namespace group 2 classes which are related to the score made in game
 * and one class reserved to the exceptions.
 */
namespace Score {
    /**
     * Class Game:

     * The class is dedicated to the score produced directly in-game. It's composed of the
     * author and his score.
     */
    class Game {
        public:
            /**
             * Basic constructor which is initialize private values
             */
            Game();

            /**
             * Add a letter to the author's name
             * @param letter : The letter to be added
             */
            void addLetter(const char &letter);

            /**
             * Get a letter at an certain index
             * @param idx : The index of the letter
             * @throw std::out_of_range : If the index is not in the range
             * @return The letter as char
             */
            const char &getLetter(const std::size_t idx) const;

            /**
             * Set a letter at the certain index
             * @param idx : The index of the letter
             * @param c : The letter which will be replaced
             * @throw std::out_of_range : If the index is not in the range
             */
            void setLetter(const std::size_t idx, const char c);

            /**
             * Save the current score with the author's name into a file.
             * The file path is defined by class Core and the game's name
             * @throw Score::Exceptions::InvalidFile : Cannot create/open the file
             */
            void save() const;

            /**
             * Get the author's name saved in private
             * @return A string with the author's name
             */
            std::string getAuthor() const;

            /**
             * Set the score's amount to `score`
             * @param score New score's amount
             */
            void setScore(const std::size_t score);

            /**
             * Set the game's name which will be used when the file is saved
             * @param game : The game's name
             */
            void setGame(const std::string &game);

            /**
             * Reset the score's amount
             */
            void reset();

            /**
             * Remove the last letter of the author's name
             * @throw std::out_of_range : If the author's name is empty
             */
            void removeLastLetter();

            /**
             * The maximum length of the author's name
             */
            static const std::size_t MAX_AUTHOR_NAME = 8;

        private:
            int _amount;
            std::string _author;
            std::string _game;
    };

    class File {
        public:
             /**
              * Initialize a File instance with the content of a file.
              * @param content : Content of the file which will be initialized
              */
            explicit File(const std::string &content) noexcept;
            File() = default;

            /**
             * PlayerData is a class the represents a player in-game with his score and his name.
             */
            class PlayerData {
                public:
                    /**
                     * Initialize the class with his name and his score
                     * @param name : The author's name
                     * @param score : The author's score
                     */
                    PlayerData(const std::string &name, const long score);

                    /**
                     * Transform the internal information into a string
                     * @return : A string formatted as: ```Name = Score```
                     */
                    std::string toStr() const;

                    /**
                     * Player's name
                     */
                    std::string name;

                    /**
                     * Player's score
                     */
                    long score;
            };

            /**
             * Add an entry to the list of registered users. Users are PlayerData type
             * @param user The user to add in the list
             */
            void addEntry(const PlayerData &user);

            /**
             * Get a list of all registered users. Users are PlayerData type
             * @return A list of PlayerData
             */
            std::list<PlayerData> getListUser();

        private:
            void sort();
            std::list<PlayerData> _userList;
    };


    namespace Exceptions {
        /**
         * InvalidFile is an exception throw when a file cannot be open nor created
         */
        class InvalidFile : public std::exception {
            public:
                InvalidFile() = default;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred
                 */
                const char *what() const noexcept override;
        };
    }
}


#endif //OOP_ARCADE_2019_SCORE_HPP
