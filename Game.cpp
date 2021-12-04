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
SDL_Texture *playerTex;
SDL_Rect srcR,destR;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
    // SDL_Surface* tmpSurface = IMG_Load("images/astronaut.png");
    // playerTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    // SDL_FreeSurface(tmpSurface);
	playerTex = TextureManager::LoadTexture("images/astronaut.png",renderer);
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
    destR.h =80;
    destR.w =80;
	// srcR.x = 300;
	// srcR.y = 400;
    destR.y =cnt;
	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}