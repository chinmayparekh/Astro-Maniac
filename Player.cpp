#include "Player.hpp"
#include "Game.hpp"


Player::Player(const char *texturesheet, int x, int y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}

void Player::handleEvents()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_a:
            vel_X = 5;
            break;
        case SDLK_d:
            vel_X = -5;
            break;
        }
    }
    else
    {
        vel_X = 0;
    }
}
