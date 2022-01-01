#include "../include/Window.hpp"
#include <SDL2/SDL_ttf.h>
#include "../include/Background.hpp"
#include "../include/Button.hpp"
#include "../include/Audio.hpp"
using namespace std;

Audio sound;
Background *bg1;
Background *bg2;
//Button *start;
//Button *help;
//Button *quit;

Window::Window()
{
}

Window::~Window()
{
}

void Window::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
        is_Running = true;
        TTF_Init();
    }
    bg1 = new Background("../images/space.png", 0, 0, 900, 900);
    bg2 = new Background("../images/space.png", 0, -900, 900, 900);
    //start = new Button("../images/startButton.png", WINDOW_W * 430 / 900, WINDOW_H * 710 / 900, 170 * WINDOW_W / 900, 170 * WINDOW_H / 900);
    //help = new Button("../images/helpButton.png", WINDOW_W * 430 / 900, WINDOW_H * 710 / 900, 170 * WINDOW_W / 900, 170 * WINDOW_H / 900);
    //quit = new Button("../images/quitButton.png", WINDOW_W * 430 / 900, WINDOW_H * 710 / 900, 170 * WINDOW_W / 900, 170 * WINDOW_H / 900);
    sound.load("../Music/progress-in-space-11756.wav");
    sound.play();
}

void Window::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;// is_Running = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            isRunning = false;
            break;
        /*case SDLK_RETURN:
            isRunning = false;
            break;
        case SDLK_SPACE:
            is_Running = false;
            break;*/
        }
        break;
    default:
        break;
    }
}

void Window::update()
{
    if (!isRunning)
        return;
    /*if (!is_Running)
        return;*/    
    bg1->update();
    bg2->update();
}

void Window::render()
{
    SDL_RenderClear(renderer);
    bg1->Render();
    bg2->Render();
    //start->Render();
    renderNew();
    SDL_RenderPresent(renderer);
    //sound.play();
}

void Window::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}