#include "Game.hpp"
#include "Player.hpp"
#include "Alien.hpp"
#include "Obstacle.hpp"
#include "Fuel.hpp"
#include "Score.hpp"
#include "Background.hpp"
#include <bits/stdc++.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>

Player *player;
Obstacle *obstacle;
Fuel *fuel;
Background *background1;
Background *background2;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
Alien *aliens[3];

SDL_Rect rec;
SDL_Texture *tx;
Score *score = NULL;
int sb = 0;

using namespace std;
bool fuelCollected = false;
int a = 0;
bool collision = false;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int width, int height, bool fullscreen)
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
	player = new Player("images/rocket.png", 430, 710, 170, 170);
	obstacle = new Obstacle("images/meteor.png", 850, 400, 80, 80);
	fuel = new Fuel("images/fuel.jpg", 430, 0, 80, 80);
	background1 = new Background("images/space.png", 0, 0, 900, 900);
	background2 = new Background("images/space.png", 0, -900, 900, 900);
	score = new Score();

	for (int i = 0; i < 3; i++)
	{
		int ranIndex = randomNumberGenerator(123456) % 3;
		aliens[i] = new Alien(Alien::images[ranIndex], rand() % 800, 0, 80, 80, ranIndex);
	}
}

void Game::handleEvents()
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
		}
		break;
	default:
		break;
	}
	if (player != NULL)
	{
		player->handleEvents2();
		a = player->getVelX();
	}
}

bool IntersectRect(SDL_Rect *r1, SDL_Rect *r2) //checking collision
{
	return !(r2->x > (r1->x + r1->w / 2) ||
			 (r2->x + r2->w / 2) < r1->x ||
			 r2->y > (r1->y + r1->h / 2) ||
			 (r2->y + r2->h / 2) < r1->y);
}

bool isDead()
{
	if (IntersectRect(obstacle->getdestRect(), player->getdestRect()))
		return false;
	for (int i = 0; i < 3; i++)
	{
		if (IntersectRect(aliens[i]->getdestRect(), player->getdestRect()))
			return false;
	}
	if (fuel->getPlayerStatus())
	{
		return false;
	}
	return true;
}

void Game::update()
{
	if (!isRunning)
		return;
	if (player != NULL)
	{
		player->update(a, 0);
		obstacle->update(-2, 2);
		for (int i = 0; i < 3; i++)
			aliens[i]->update();
	}
	fuel->update(player);
	background1->update();
	background2->update();
	//put isRunnig at the end
	isRunning = isDead();
}

void Game::render()
{
	sb++;
	//sdl render clear always first
	SDL_RenderClear(renderer);
	background1->Render();
	background2->Render();
	if (player != NULL)
	{
		player->Render2();
		for (int i = 0; i < 3; i++)
		{
			aliens[i]->Render();
		}
		obstacle->Render();
		fuel->Render();
	}
	score->render(sb);

	//sdl render present at end
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}