/*
** EPITECH PROJECT, 2018
** include/Core
** File description:
** Core
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
     * BLABLA class CORE
     */
    class Core {
        public:
            /**
             * typedef changer
             */
            typedef void (Core::Core::*libChanger)(bool);

            explicit Core(const std::string &graphicalLib);
            ~Core() = default;

            void useGraphic(const std::string &filename);
            void useGame(const std::string &filename);
            void run();

            static std::string loadScore(const std::string &gameName);
            constexpr static const char *SCORE_PATH = "./games/score/";

            /* 1000 / 60 = 17 (~ 16,666666667)
                - 1000 milliseconds = 1 sec
                - 60 FPS (frame per seconds) or the number of total images that we want per second
                -> 17 = number of frame / millisecond
                + We choose millisecond as the architecture stipulate it
            */
            const static uint FRAME_PER_TIME = 17;

        private:
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

            std::map<std::string, std::string> _scores;
            std::map<std::string, std::list<std::experimental::filesystem::path>> _lib;
            Score::Game _score;
    };

    namespace Exceptions {
        class UnableCreateFolder : public std::exception {
            public:
                UnableCreateFolder() noexcept = default;

                const char *what() const noexcept override;
        };

        class MissingMandatoryFolder : public std::exception {
            public:
                explicit MissingMandatoryFolder(const std::string &name) noexcept;
                MissingMandatoryFolder() = delete;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        class EmptyMandatoryFolder : public std::exception {
            public:
                explicit EmptyMandatoryFolder(const std::string &name) noexcept;
                EmptyMandatoryFolder() = delete;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        class InvalidScorePath : public std::exception {
            public:
                explicit InvalidScorePath(const std::string &name) noexcept;
                InvalidScorePath() = delete;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        class UnknownGraphicalLib : public std::exception {
            public:
                explicit UnknownGraphicalLib(const std::string &name) noexcept;
                UnknownGraphicalLib() = delete;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };

        class ExitGame : public std::exception {
            public:
                ExitGame() noexcept = default;

                const char *what() const noexcept override;
        };
    }
}

#endif
