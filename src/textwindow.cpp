#include "../include/textwindow.hpp"
#include "../include/Game.hpp"
#include <SDL2/SDL_ttf.h>

void get_tar(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Texture **texture, SDL_Rect* rect)
{
    
    int text_width;
	int text_height;
	SDL_Surface *surface;
	SDL_Color textColor = {255, 255, 255, 0};
	SDL_Color bColor = {0, 0, 0, 0};

	surface = TTF_RenderText_Shaded(font, text, textColor, bColor);
	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	text_width = surface->w;
	text_height = surface->h;
	SDL_FreeSurface(surface);
	rect->x = x;
	rect->y = y;
	rect->w = text_width;
	rect->h = text_height;
}


textwindow::textwindow()
{
    TTF_Init();
}

void textwindow::render(int clickn)
{

	std::string temp = "ASTRO MANIAC" ;
    TTF_Font *font1 = TTF_OpenFont("../fonts/TheConfessionRegular-YBpv.ttf", 40);
	TTF_Font *font2 = TTF_OpenFont("../fonts/TheConfessionFullRegular-8qGz.ttf", 100);
	if (font1 == NULL)
	{
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
        // return;
	}
	std::string hs = " ";
	// if(highScore < time)
	// 	hs = "High Score: " + std::to_string(time);
	// else
	// 	hs = "High Score: " + std::to_string(highScore);
        
	if(clickn == 0)
    {
        get_tar(Game::renderer, 180, 200, temp.c_str(), font2, &tx, &r);
		SDL_RenderCopy(Game::renderer, tx, NULL, &r);
		std::string cmd = "Press 'N' to know the controls";
		get_tar(Game::renderer, 250, 700, cmd.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);
    }
	else if(clickn == 1)
	{
		get_tar(Game::renderer, 180, 200, temp.c_str(), font2, &tx, &r);
		SDL_RenderCopy(Game::renderer, tx, NULL, &r);
		std::string ctr = "Rules and Controls:";
		get_tar(Game::renderer, 150, 400, ctr.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);
		std::string str = "Click A to move right";
		get_tar(Game::renderer, 150, 450, str.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);
		std::string str1 = "Click D to move left";
		get_tar(Game::renderer, 150, 500, str.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);

		std::string cmd = "Press 'N' and space bar to play game";
		get_tar(Game::renderer, 225, 740, cmd.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);


	}
    else
    {
        get_tar(Game::renderer, 0, 0, hs.c_str(), font1, &tx, &r);
        SDL_RenderCopy(Game::renderer, tx, NULL, &r);
    }

    
}
