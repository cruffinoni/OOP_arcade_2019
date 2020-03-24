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
#include "game/IGame.hpp"
#include "graphic/IGraphic.hpp"
#include "soLoader/SoLoader.hpp"

namespace Core {
    class Core {
        public:
            Core();
            ~Core() = default;

            void useGraphic(const std::string &filename);
            void useGame(const std::string &filename);
            void run();

            static std::string loadScore(const std::string &gameName);
            constexpr static const char *SCORE_PATH = "./games/score/";

        private:
            static void createScoreFolder();

            SoLoader::SoLoader<IGame> _game;
            SoLoader::SoLoader<IGraphic> _graphic;
    };

    namespace Exceptions {
        class ScoreFolder : public std::exception {
            public:
                ScoreFolder() noexcept = default;

                const char *what() const noexcept override;
        };
    }
}

#endif
