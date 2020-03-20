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
            static void drawBackground(IGraphicRenderer &renderer);
            void addNode();
            void resetPlayer();
            void spawnReward();
            //void

            const ushort MAX_MAP_SIZE = 20;
            const Vector2f DEFAULT_SQUARE_SIZE = {5.f, 5.f};
            const Color SNAKE_COLOR_1 = {0x00, 0x66, 0x00, 0xFF};
            const Color SNAKE_COLOR_2 = {0x33, 0xCC, 0x33, 0xFF};
            const Color WALL_COLOR = {0xB3, 0x00, 0x00, 0xFF};
            const Color REWARD_COLOR = {0x00, 0xcc, 0xff, 0xFF};


            enum PLAYER_DIRECTION {
                NORTH,
                SOUTH,
                EAST,
                WEST
            };

            struct player_s {
                int elapsedTime;
                std::list<Vector2f> position;
                PLAYER_DIRECTION direction;
                std::size_t score;
            };

            player_s _player;
            Vector2f _reward;
            GameDataType _data;
            std::vector<Vector2f> _map;
    };
}


#endif //OOP_ARCADE_2019_NIBBLER_HPP
