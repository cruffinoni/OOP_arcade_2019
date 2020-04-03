/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Regroup multiple core classes
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <list>
#include <core/score/Score.hpp>
#include <experimental/filesystem>
#include "game/IGame.hpp"
#include "graphic/IGraphic.hpp"
#include "soLoader/SoLoader.hpp"

namespace Core {
    /**
     * Class Core:

     * This class is the main one which is coordinate the graphic and
     * the games libraries.
     */
    class Core {
        public:

            /**
             * Constructor for the Core class.
             * @param graphicalLib : The path to the graphical library to load.
             * @throw SoLoader::Exceptions::InvalidSO
             * @throw SoLoader::Exceptions::InvalidEntryPoint
             * @throw Core::Exceptions::EmptyMandatoryFolder
             * @throw Core::Exceptions::UnknownGraphicalLib
             * @throw Core::Exceptions::UnableCreateFolder
             * @throw Core::Exceptions::MissingMandatoryFolder
             */
            explicit Core(const std::string &graphicalLib);
            ~Core() = default;

            /**
             * Load a graphical library and store the instance. Can throw exceptions.
             * @param filename : The path to the graphical library.
             * @throw SoLoader::Exceptions::InvalidSO
             * @throw SoLoader::Exceptions::InvalidEntryPoint
             */
            void useGraphic(const std::string &filename);

            /**
             * Load a game library and store the instance. Can throw exceptions.
             * @param filename : The path to the game library.
             * @throw SoLoader::Exceptions::InvalidSO
             * @throw SoLoader::Exceptions::InvalidEntryPoint
             */
            void useGame(const std::string &filename);

            /**
             * Launch the main loop for the project. If the loop is over, the programme ends.
             */
            void run();

             /**
              * Load a score file. The score's files path is defined by the static public variable `SCORE_PATH`.
              * @param gameName : The game's name score to load.
              * @throw Core::Exceptions::InvalidScorePath
              * @return
              */
            static Score::File loadScore(const std::string &gameName);

            /**
             * See `loadScore` description.
             */
            constexpr static const char *SCORE_PATH = "./games/score/";

            /**
             * 1000 / 60 = 17 (~ 16,666666667)
             *  - 1000 milliseconds = 1 sec
             *  - 60 FPS (frame per seconds) or the number of total images that we want per second
             *  -> 17 = number of frame / millisecond
             *  + We choose millisecond as the architecture stipulate it
             */
            const static uint FRAME_PER_TIME = 17;

        private:
            /**
             * typedef changer
             */
            typedef void (Core::Core::*libChanger)(bool);
            static void createScoreFolder();
            void readFolder(const std::string &folderName);
            bool handleInternalKey(const std::string &key);

            const std::array<std::string, 2> MANDATORY_FOLDERS = {
                "games", "lib"
            };

            // Handling key
            void previousLib(bool graphical);
            void nextLib(bool graphical);
            void exitKey(bool);
            void enterGame(bool);

            // Handling key
            void nameLeftAction(bool);
            void nameRightAction(bool);
            void nameUpAction(bool);
            void nameDownAction(bool);

            struct playerName {
                playerName() : currentLetter('_'), currentIndex(0) {}
                char currentLetter;
                unsigned char currentIndex;
            } _playerName;
            void updateCurrentLetter();

            // Menu
            void renderMenu();
            std::string drawGames(Vector2f &final_pos);
            void drawGraphicalLib(Vector2f &position);
            void drawScore(const std::string &game, Vector2f &pos);
            void drawPlayerName(Vector2f &position);
            static std::string getLibName(std::string libName, bool uppercase = true);
            std::map<std::string, short> _selection;
            #define IS_IN_GAME(a) (a->_selection["games"] == -1)
            void createStripGame();
            void createStripMenu();
            const Vector2f DEFAULT_SMALL_TEXT_SIZE = {10.f, 7.5f};
            const Vector2f DEFAULT_TEXT_SIZE = {20.f, 15.f};
            const Vector2f DEFAULT_MEDIUM_TEXT_SIZE = {25.f, 20.f};
            const Vector2f DEFAULT_TITLE_SIZE = {40.f, 30.f};

            // Libraries
            SoLoader::SoLoader<IGame> _game;
            SoLoader::SoLoader<IGraphic> _graphic;

            std::map<std::string, Score::File> _scores;
            std::map<std::string, std::list<std::experimental::filesystem::path>> _lib;
            Score::Game _score;
    };

    namespace Exceptions {
        /**
         * UnableCreateFolder is an exception throw when the program cannot create the folder
         * which will gather score files together.
         */
        class UnableCreateFolder : public std::exception {
            public:
                UnableCreateFolder() noexcept = default;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;
        };

        /**
         * MissingMandatoryFolder is an exception throw when the mandatory folders are missing.
         * These folders are required by the project 'Arcade'.
         */
        class MissingMandatoryFolder : public std::exception {
            public:
                explicit MissingMandatoryFolder(const std::string &name) noexcept;
                MissingMandatoryFolder() = delete;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        /**
         * EmptyMandatoryFolder is an exception throw when the mandatory folders are empty.
         * That means there is no library (games or graphical libraries) inside one nor both empty.
         */
        class EmptyMandatoryFolder : public std::exception {
            public:
                explicit EmptyMandatoryFolder(const std::string &name) noexcept;
                EmptyMandatoryFolder() = delete;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        /**
         * InvalidScorePath is a minor exception throw when the path to load a score file is invalid.
         * The program must handle this exception since it's a minor one.
         */
        class InvalidScorePath : public std::exception {
            public:
                explicit InvalidScorePath(const std::string &name) noexcept;
                InvalidScorePath() = delete;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        /**
         * UnknownGraphicalLib is a minor exception throw when the initial graphical library has been
         * correctly loaded but cannot be found anymore, anywhere.
         */
        class UnknownGraphicalLib : public std::exception {
            public:
                explicit UnknownGraphicalLib(const std::string &name) noexcept;
                UnknownGraphicalLib() = delete;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        /**
         * ExitGame is a minor exception throw when the program must exit gracefully.
         */
        class ExitGame : public std::exception {
            public:
                ExitGame() noexcept = default;

                /**
                 * Required by std::exception
                 * @return An explicit message explaining why the error occurred.
                 */
                const char *what() const noexcept override;
        };
    }
}

#endif
