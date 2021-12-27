#include "../include/Score.hpp"
#include "../include/Game.hpp"
#include <SDL2/SDL_ttf.h>

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Texture **texture, SDL_Rect* rect)
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


Score::Score()
{
    TTF_Init();
}

void Score::render(int cnt, int highScore)
{

	int time = cnt/10;
	std::string tmp = "Score: " + std::to_string(time);
    TTF_Font *font1 = TTF_OpenFont("../fonts/digital-7.ttf", 40);
	if (font1 == NULL)
	{
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
        // return;
	}
	std::string hs;
	if(highScore < time)
		hs = "High Score: " + std::to_string(time);
	else
		hs = "High Score: " + std::to_string(highScore);
        
	get_text_and_rect(Game::renderer, 0, 0, tmp.c_str(), font1, &tx, &r);
    SDL_RenderCopy(Game::renderer, tx, NULL, &r);
	get_text_and_rect(Game::renderer, WINDOW_W * 650/900, 0, hs.c_str(), font1, &tx1, &r1);
    SDL_RenderCopy(Game::renderer, tx1, NULL, &r1);
    
}
