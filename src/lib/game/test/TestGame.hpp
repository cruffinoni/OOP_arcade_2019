/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_TESTGAME_HPP
#define OOP_ARCADE_2019_TESTGAME_HPP

#include "game/IGame.hpp"

namespace Game {
    class TestGame : public IGame {
        public:
            TestGame() = default;
            ~TestGame() override = default;

            void handleEvent(std::string &name) override;
            void handleRender(IGraphicRenderer &renderer) override;
            void handleUpdate(int elapsedTime) override;
            void setGameData(GameDataType &data) override;
            GameDataType getGameData() override;

        private:
            GameDataType _event;
            uint _tick;
    };
}


#endif //OOP_ARCADE_2019_TESTGAME_HPP
