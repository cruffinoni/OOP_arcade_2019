/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.hpp
*/

#include <list>
#include <core/score/Score.hpp>
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
            void drawGame(IGraphicRenderer &renderer);
            void drawScore(IGraphicRenderer &renderer);

            enum PLAYER_DIRECTION {
                NORTH,
                SOUTH,
                EAST,
                WEST
            };

            enum GAME_STATE {
                GAME,
                SCORE
            } _state;

            #define IS_GAME_IN_PROGRESS(a) (a->_state == Nibbler::GAME_STATE::GAME)

            struct player_s {
                player_s() : score(0, "nibbler") {};

                int elapsedTime;
                std::list<Vector2f> position;
                PLAYER_DIRECTION direction;
                std::size_t death;
                Score::Game score;
            };
            player_s _player;
            GameDataType _data;
    };
}
