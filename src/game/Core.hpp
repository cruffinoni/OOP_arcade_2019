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

        private:
            static void createScoreFolder();
            void readFolder(const std::string &folderName);
            bool handleInternalKey(const std::string &key);

            void previousLib(bool graphical);
            void nextLib(bool graphical);

            SoLoader::SoLoader<IGame> _game;
            SoLoader::SoLoader<IGraphic> _graphic;

            std::map<std::string, std::list<std::string>> _lib;
    };

    namespace Exceptions {
        class ScoreFolder : public std::exception {
            public:
                ScoreFolder() noexcept = default;

                const char *what() const noexcept override;
        };
        class MissingFolder : public std::exception {
            public:
                explicit MissingFolder(const std::string &name) noexcept;
                MissingFolder(const MissingFolder &a) noexcept;

                const char *what() const noexcept override;

            private:
                std::string _name;
        };
    }
}

#endif
