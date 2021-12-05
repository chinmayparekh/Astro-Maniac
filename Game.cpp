// #include "Game.hpp"
// SDL_Texture *playerTex;

// using namespace std;
// Game::Game()
// {
// }
// Game::~Game()
// {
// }
// void Game::init(const char *name, int x, int y, int width, int height, bool fullscreen)
// {
//     int flags = 0;
//     if (fullscreen)
//     {
//         flags = SDL_WINDOW_FULLSCREEN;
//     }
//     if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
//     {
//         cout << "Subsystems Initialized!" << endl;
//         window = SDL_CreateWindow(name, x, y, width, height, flags);
//         if (window)
//         {
//             cout << "Window created" << endl;
//         }
//         renderer = SDL_CreateRenderer(window, -1, 0);
//         if (renderer)
//         {
//             SDL_SetRenderDrawColor(renderer,255,255,255,255);
//             cout << "Renderer created" << endl;
//         }
//         isRunning = true;
//     }
//     else
//     {
//         isRunning = false;
//     }
// }

// void Game::handleEvents()
// {
//     SDL_Event event;
//     SDL_PollEvent(&event);
//     switch (event.type)
//     {
//     case SDL_QUIT:
//         isRunning = false;
//         break;
//     default:
//         break;
//     }
// }
// void Game::update()
// {
//     count++;
//     cout << count <<endl;
// }
// void Game::render()
// {
//     SDL_RenderClear(renderer);
//     SDL_RenderPresent(renderer);
// }

// void Game::clean()
// {
//     SDL_DestroyWindow(window);
//     SDL_DestroyRenderer(renderer);
//     SDL_Quit();
//     cout << "Game cleaned" << endl;
// }

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject *player;
GameObject *obstacle;
GameObject *background;
SDL_Renderer *Game::renderer = nullptr;

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

	player = new GameObject("images/astronaut.png", 430, 800, 80, 80);
	obstacle = new GameObject("images/meteor.png", 850, 400, 80, 80);
	background = new GameObject("images/space.png", 0, 0, 900, 900);
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDLK_ESCAPE:
		isRunning = false;
	case SDL_KEYDOWN:
		isRunning = false;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	player->update(0, 0);
	obstacle->update(cnt, cnt);
	background->update(0, 0);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	background->Render();
	player->Render();
	obstacle->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}