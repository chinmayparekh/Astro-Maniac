#include "../include/Window.hpp"
#include <SDL2/SDL_ttf.h>
#include "../include/Background.hpp"
#include "../include/Audio.hpp"
#include "../include/textwindow.hpp"
using namespace std;

Audio sound;
Background *bg1;
Background *bg2;

textwindow *txt = NULL;

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
    txt = new textwindow();
    sound.load("../Music/progress-in-space-11756.wav");
    sound.play();
}

void Window::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            isRunning = false;
            break;
        case SDLK_SPACE:
            isRunning = false;
            break;
        case SDLK_n:
            t += 1;
            break;
        case SDL_SCANCODE_RETURN2:
            isRunning = false;
            break;
        }
        break;
    default:
        break;
    }
}

void Window::update(int wn)
{
    if (!isRunning)
        return;
    bg1->update();
    bg2->update();
    winno = wn;
}

void Window::render()
{
    SDL_RenderClear(renderer);
    bg1->Render();
    bg2->Render();
    if (winno == 0)
    {
        txt->render(t);
    }
    renderNew();
    SDL_RenderPresent(renderer);
}

void Window::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}