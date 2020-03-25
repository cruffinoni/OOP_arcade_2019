/*
** EPITECH PROJECT, 2018
** include/Core
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <dirent.h>
#include <list>
#include "game/IGame.hpp"
#include "graphic/IGraphic.hpp"
#include "soLoader/SoLoader.hpp"

namespace Core {
    class Core {
        public:
            typedef void (Core::Core::*libChanger)(bool);

            Core();
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
            const static uint TIME_PER_FRAME = 17;

        private:
            static void createScoreFolder();
            void readFolder(const std::string &folderName);
            bool handleInternalKey(const std::string &key);

            const std::array<std::string, 2> MANDATORY_FOLDERS = {
                "games", "lib"
            };

            void previousLib(bool graphical);
            void nextLib(bool graphical);

            void menuEvents(std::string &event);
            void renderMenu();

            SoLoader::SoLoader<IGame> _game;
            SoLoader::SoLoader<IGraphic> _graphic;

            std::map<std::string, std::list<std::string>> _lib;
            bool _gameRunning;
            enum selectedGame {
                NIBBLER,
                PACMAN
            } _selectedGame;
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
                MissingMandatoryFolder(const MissingMandatoryFolder &a) noexcept;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };
        class EmptyMandatoryFolder : public std::exception {
            public:
                explicit EmptyMandatoryFolder(const std::string &name) noexcept;
                EmptyMandatoryFolder(const EmptyMandatoryFolder &a) noexcept;
                const char *what() const noexcept override;

            private:
                std::string _name;
        };
    }
}

#endif