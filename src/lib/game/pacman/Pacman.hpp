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
            enum ENTITY_DIRECTION {
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

            enum MOVES_STATES {
                WALL,
                ENEMY,
                PLAYER,
                NONE
            };

            struct player_s {
                player_s() : position(5, 5) {
                    this->elapsedTime = 0;
                    this->score = 0;
                    this->death = 0;
                    this->direction = IDLE;
                };

                int elapsedTime;
                Vector2i position;
                ENTITY_DIRECTION direction;
                std::size_t death;
                std::size_t score;
            };

            struct enemy_s {
                explicit enemy_s(const Vector2i &position) : position(position) {
                    this->elapsedTime = 0;
                    this->isDead = false;
                    this->isEatable = false;
                };

                int elapsedTime;
                Vector2i position;
                bool isDead;
                bool isEatable;
            };

            void drawGame(IGraphicRenderer &renderer);
            void drawScore(IGraphicRenderer &renderer);
            MOVES_STATES checkMove(Vector2i entityPos, ENTITY_DIRECTION playerDirection);
            void generateMap();
            void movePlayer();
            void moveEnemy(enemy_s &enemy);
            void checkEnemyStatus(enemy_s &enemy);
            void resetGame();

            void drawSquare(int x, int y, int sizeX, int sizeY);
            void drawPacGom(int x, int y, int sizeX, int sizeY);

            const ushort MAX_MAP_SIZE = 20;
            const Vector2f DEFAULT_SQUARE_SIZE = {5.f, 5.f};
            const Vector2f DEFAULT_ENTITY_SIZE = {2.f, 2.f};
            const Vector2f DEFAULT_PACGOM_SIZE = {1.f, 1.f};
            const Color WALL_COLOR = {0xB3, 0x00, 0x00, 0xFF};
            const Color PACGOM_COLOR = Color::Green();
            const Color ENEMY_COLOR = Color::Blue();
            const Color PACMAN_COLOR = Color(245, 189, 31, 0);

            #define IS_GAME_IN_PROGRESS(a) (a->_state == Pacman::GAME_STATE::GAME)

            player_s _player;
            std::vector<enemy_s> _enemies;
            GameDataType _data;
            std::vector<Vector2i> _map;
            std::list<Vector2i> _pacGoms;
    };
}
