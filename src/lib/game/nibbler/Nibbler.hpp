/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_2019_NIBBLER_HPP
#define OOP_ARCADE_2019_NIBBLER_HPP

#include <vector>
#include <list>
#include "graphic/Drawables.hpp"
#include "game/IGame.hpp"
#include "core/score/Score.hpp"

namespace Game {
    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler() override = default;

            void handleEvent(std::string &name) override;
            void handleRender(IGraphicRenderer &renderer) override;
            void handleUpdate(int elapsedTime) override;
            void setGameData(GameDataType &data) override;
            GameDataType getGameData() override;

        private:
            void drawGame(IGraphicRenderer &renderer);
            void drawScore(IGraphicRenderer &renderer);

            void addNode();
            void resetPlayer();
            void spawnReward();

            const ushort MAX_MAP_SIZE = 20;
            const Vector2f DEFAULT_SQUARE_SIZE = {5.f, 5.f};
            const Color SNAKE_COLOR_1 = {0x00, 0x00, 0x66, 0xFF};
            const Color SNAKE_COLOR_2 = {0x33, 0x33, 0xCC, 0xFF};
            const Color WALL_COLOR = {0xB3, 0x00, 0x00, 0xFF};
            const Color REWARD_COLOR = {0x00, 0xff, 0xcc, 0xFF};


            enum PLAYER_DIRECTION {
                NORTH,
                SOUTH,
                EAST,
                WEST
            };

            enum GAME_STATE {
                GAME,
                SCORE
            };

            #define IS_GAME_IN_PROGRESS(a) (a->_state == Nibbler::GAME_STATE::GAME)

            struct player_s {
                player_s() : score(0) {
                    this->elapsedTime = 0;
                    this->direction = SOUTH;
                    this->death = 0;
                };

                int elapsedTime;
                std::list<Vector2f> position;
                PLAYER_DIRECTION direction;
                std::size_t death;
                std::size_t score;
            };
            player_s _player;
            Vector2f _reward;
            GameDataType _data;
            std::vector<Vector2f> _map;
            enum GAME_STATE _state;
    };
}


#endif //OOP_ARCADE_2019_NIBBLER_HPP
