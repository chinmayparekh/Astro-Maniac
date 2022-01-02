#include "../include/Cntrl_Window.hpp"
#include "../include/Background.hpp"
#include <SDL2/SDL_ttf.h>
using namespace std;

Background *bgnd1;
Background *bgnd2;

Cntrl_Window::Cntrl_Window()
{
}

Cntrl_Window::~Cntrl_Window()
{
}

void Cntrl_Window::init(const char *title, int width, int height, bool fullscreen)
{
    Window::init(title, width, height, fullscreen);

    bgnd1 = new Background("images/space.png", 0, 0, 900, 900);
	bgnd2 = new Background("images/space.png", 0, -900, 900, 900);
}

void Cntrl_Window::handleEvents()
{
    Window::handleEvents();
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_Running = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
                is_Running = false;
                break;
        }
        break;
    default:
        break;
    }
}

void Cntrl_Window::update()
{
    if (!is_Running)
        return;
	Window::update(1);
    bgnd1->update();
    bgnd2->update();
}

void Cntrl_Window::renderNew()
{
    SDL_RenderClear(renderer);
    bgnd1->Render();
    bgnd2->Render();
    SDL_RenderPresent(renderer);
}

void Cntrl_Window::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);    
    SDL_Quit();
}
