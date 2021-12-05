#include "Player.hpp"

Player::Player(const char *texturesheet, int x, int y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}

// void Player::update()
// {
//     if (event.type == SDL_KEYDOWN)
//     {
//         switch (event.key.keysym.sym)
//         {
//         case SDLK_a:
//             a -= 5;
//             break;
//         case SDLK_d:
//             a += 5;
//             break;
//         }
//     }
// }