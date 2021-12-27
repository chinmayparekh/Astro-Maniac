#include "../include/Game.hpp"
#include "../include/Player.hpp"
#include "../include/Alien.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Fuel.hpp"
#include "../include/Score.hpp"
#include "../include/Background.hpp"
#include "../include/main.hpp"
#include <bits/stdc++.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>

Player *player;
Obstacle *obstacle;
Fuel *fuel;
Background *background1;
Background *background2;

SDL_Renderer *Window::renderer = nullptr;
SDL_Event Window::event;
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

void Game::init(const char *title, int width, int height, bool fullscreen, int highScore)
{
	Window::init(title, width, height, fullscreen);
	this->highScore = highScore;
	player = new Player("../images/rocket.png", WINDOW_W * 430 / 900, WINDOW_H * 710 / 900, 170 * WINDOW_W / 900, 170 * WINDOW_H / 900);
	obstacle = new Obstacle("../images/meteor.png", WINDOW_W * 850 / 900, WINDOW_H * 400 / 900, 80 * WINDOW_W / 900, 80 * WINDOW_H / 900);
	fuel = new Fuel("../images/fuel.jpg", WINDOW_W * 430 / 900, 0, 80 * WINDOW_W / 900, 80 * WINDOW_H / 900);
	background1 = new Background("../mages/space.png", WINDOW_W * 0, 0, WINDOW_W, WINDOW_H);
	background2 = new Background("../images/space.png", WINDOW_W * 0, -WINDOW_H, WINDOW_W, WINDOW_H);
	score = new Score();

	for (int i = 0; i < 3; i++)
	{
		int ranIndex = randomNumberGenerator(123456) % 3;
		aliens[i] = new Alien(Alien::images[ranIndex], rand() % (WINDOW_W * 800 / 900), 0, 80 * WINDOW_W / 900, 80 * WINDOW_H / 900, ranIndex);
	}
}

void Game::handleEvents()
{
	Window::handleEvents();
	if (player != NULL)
	{
		player->handleEvents();
		a = player->getVelX();
	}
}

bool IntersectRect(SDL_Rect *r1, SDL_Rect *r2) //checking collision
{
	return !(r2->x > (r1->x + r1->w / 2) || (r2->x + r2->w / 2) < r1->x || r2->y > (r1->y + r1->h / 2) || (r2->y + r2->h / 2) < r1->y);
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
	Window::update();

	if (player != NULL)
	{
		player->update(a, 0);
		obstacle->update(-2, 2);
		for (int i = 0; i < 3; i++)
			aliens[i]->update();
	}
	fuel->update(player);
	//put isRunning at the end
	isRunning = isDead();
}

void Game::renderNew()
{
	if (!isRunning)
		return;
	sb++;
	//sdl render clear always first
	if (player != NULL)
	{
		player->Render();
		for (int i = 0; i < 3; i++)
		{
			aliens[i]->Render();
		}
		obstacle->Render();
		fuel->Render();
	}
	score->render(sb, this->highScore);

	//sdl render present at end
}
