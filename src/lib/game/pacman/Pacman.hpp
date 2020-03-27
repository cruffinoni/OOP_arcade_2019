/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.hpp
*/

#include "game/IGame.hpp"

namespace Game {
    class Pacman : public IGame {
        public:
            Pacman();
            ~Pacman() override = default;

            void handleEvent(std::string &name) override;
            void handleRender(IGraphicRenderer &renderer) override;
            void handleUpdate(int elapsedTime) override;
            void setGameData(GameDataType &data) override;
            GameDataType getGameData() override;

        private:
            
    };
}
