#include "Game.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"

Player *player;
Obstacle *obstacle;
GameObject *background;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
using namespace std;

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
	}

	player = new Player("images/astronaut.png", 430, 710, 170, 170);
	obstacle = new Obstacle("images/meteor.png", 850, 400, 80, 80);
	background = new GameObject("images/space.jpg", 0, 0, 900, 900);
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDLK_ESCAPE:
		isRunning = false;
	default:
		break;
	}
	if (player != NULL)
	{
		player->handleEvents();
		a = player->getVelX();
	}
}

inline double distanceSq(int x1, int y1, int x2, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool checkCollision(GameObject *go)
{
	if ((distanceSq(go->getX(), go->getY(), player->getX(), player->getY()) < 10000)) //checking collision
	{
		player = NULL;
		return true;
	}
	return false;
}
void Game::update()
{
	if (player != NULL)
	{
		player->update(a, 0);
		if(checkCollision(obstacle))
		{
			isRunning = false;
		}
	}

	obstacle->update(-2, 2);
	background->update(0, 0);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	background->Render();
	if (player != NULL)
	{
		player->Render();
	}
	obstacle->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}