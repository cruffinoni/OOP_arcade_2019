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

            const ushort MAX_MAP_SIZE = 20;
            const Vector2f DEFAULT_SQUARE_SIZE = {5.f, 5.f};

            enum PLAYER_DIRECTION {
                NORTH,
                SOUTH,
                EAST,
                WEST
            };

            int _elapsedTime;
            std::list<Vector2f> _player;
            PLAYER_DIRECTION _direction;
            GameDataType _data;
            std::vector<Vector2f> _map;
            std::size_t _score;
    };
}


#endif //OOP_ARCADE_2019_NIBBLER_HPP
