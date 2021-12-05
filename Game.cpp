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

GameObject* player;
GameObject* obstacle;
GameObject* background;
//SDL_Texture *playerTex, *obstacleTex, *backgroundTex;
//SDL_Rect psrcR, pdestR, osrcR, odestR, bsrcR, bdestR;

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
		// window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	player = new GameObject("images/astronaut.png",renderer,430,800,80,80);
	obstacle = new GameObject("images/meteor.png",renderer,850,400,80,80);
	background = new GameObject("images/space.png",renderer,0,0,900,900);

    // SDL_Surface* tmpSurface = IMG_Load("images/astronaut.png");
    // playerTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    // SDL_FreeSurface(tmpSurface);


	//playerTex = TextureManager::LoadTexture("images/astronaut.png",renderer);
	//obstacleTex = TextureManager::LoadTexture("images/meteor.png",renderer);
	//backgroundTex = TextureManager::LoadTexture("images/space.png",renderer);
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
	case SDLK_ESCAPE :
	    isRunning = false;
	case SDL_KEYDOWN :
	    isRunning = false;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	/*bdestR.x = 0;
	bdestR.y = 0;
	bdestR.h = 1000;
	bdestR.w = 1300;
    odestR.h = 80;
    odestR.w = 80;
	pdestR.x = 600;
	pdestR.y = 800;
	pdestR.h = 70;
	pdestR.w = 70;
    odestR.y =  400 + cnt;
	odestR.x = 1000 - cnt;
	std::cout << cnt << std::endl;*/
	player->update(0,0);
	obstacle->update(cnt,cnt);
	background->update(0,0);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer,backgroundTex,NULL,&bdestR);
    //SDL_RenderCopy(renderer,playerTex,NULL,&pdestR);
	//SDL_RenderCopy(renderer,obstacleTex,NULL,&odestR);	
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