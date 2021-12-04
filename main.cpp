// #include "Game.hpp"

// Game *game = nullptr;
// int main(int argc, char *argv[])
// {
//     game = new Game();
//     // while (game is running)
//     // {
//     //     handle any user input
//     //     update all objects in the scene
//     //     render changes to the display
//     // }
//     game->init("Astro Maniac",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
//     while (game->running())
//     {
//         game->handleEvents();
//         game->update();
//         game->render();
//     }
//     game->clean();
//     return 0;
// }

#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("GameWindow", 600, 900, true);//wdith height

    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
