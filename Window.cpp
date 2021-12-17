#include "Window.hpp"
#include <SDL2/SDL_ttf.h>
#include "Background.hpp"
using namespace std;

Background *bg1;
Background *bg2;

Window::Window()
{
}

Window::~Window()
{
}

// void get_text_and_rect(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Texture **texture, SDL_Rect* rect)
// {
    
//     int text_width;
// 	int text_height;
// 	SDL_Surface *surface;
// 	SDL_Color textColor = {255, 255, 255, 0};
// 	SDL_Color bColor = {0, 0, 0, 0};

// 	surface = TTF_RenderText_Shaded(font, text, textColor, bColor);
// 	*texture = SDL_CreateTextureFromSurface(renderer, surface);
// 	text_width = surface->w;
// 	text_height = surface->h;
// 	SDL_FreeSurface(surface);
// 	rect->x = x;
// 	rect->y = y;
// 	rect->w = text_width;
// 	rect->h = text_height;
// }

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
        TTF_Init();
    }
    bg1 = new Background("images/space.png", 0, 0, 900, 900);
	bg2 = new Background("images/space.png", 0, -900, 900, 900);
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
            case SDLK_KP_ENTER:
                isRunning = false;
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

void Window::update()
{
    if (!isRunning)
        return;
    bg1->update();
    bg2->update();
}

void Window::render()
{
    SDL_RenderClear(renderer);
    bg1->Render();
    bg2->Render();
    renderNew();
    SDL_RenderPresent(renderer);

    // std::string tmp = "Enter your name: ";
    // TTF_Font *font1 = TTF_OpenFont("digital-7.ttf", 40);
    // get_text_and_rect(Window::renderer, 0, 0, tmp.c_str(), font1, &tx, &r);
    // SDL_RenderCopy(Window::renderer, tx, NULL, &r);
}

void Window::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}