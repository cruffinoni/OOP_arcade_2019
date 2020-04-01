/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Pacman.hpp
*/

#include <vector>
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
            void generateMap();
            void resetPlayer();

            void drawSquare(int x, int y, int sizeX, int sizeY);
            void drawPacGom(int x, int y, int sizeX, int sizeY);

            const ushort MAX_MAP_SIZE = 20;
            const Vector2f DEFAULT_SQUARE_SIZE = {5.f, 5.f};
            const Vector2f DEFAULT_PACGOM_SIZE = {1.f, 1.f};
            const Color WALL_COLOR = {0xB3, 0x00, 0x00, 0xFF};
            const Color PACGOM_COLOR = Color::Green();
            enum PLAYER_DIRECTION {
                NORTH,
                SOUTH,
                EAST,
                WEST,
                IDLE
            };

            enum GAME_STATE {
                GAME,
                SCORE
            } _state;

            #define IS_GAME_IN_PROGRESS(a) (a->_state == Pacman::GAME_STATE::GAME)

            struct player_s {
                player_s() : score(0, "pacman") {};

                int elapsedTime;
                Vector2f position;
                PLAYER_DIRECTION direction;
                std::size_t death;
                Score::Game score;
            };
            player_s _player;
            GameDataType _data;
            std::vector<Vector2f> _map;
            std::list<Vector2f> _pacGoms;
    };
}
