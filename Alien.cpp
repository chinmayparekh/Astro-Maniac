#include "Alien.hpp"
#include "main.hpp"
#include "Game.hpp"
#include <time.h>
#include <math.h>
using namespace std;
Alien::Alien(const char *texturesheet, float x, float y, int width, int height, int index) : GameObject(texturesheet, x, y, width, height)
{
    this->index = index;
}
// Alien::~Alien() {}

int ufo[][4] = {
    //x y width and height
    {0, 6, 210, 90},
    {261, 6, 214, 90},
    {521, 6, 213, 90},
    {785, 6, 214, 90},
    {1036, 6, 213, 90},
    {1291, 6, 212, 90},
    {1537, 6, 212, 90},
};
void Alien::update()
{
    switch (index)
    {
    case 0:
        update1();
        break;
    case 1:
        update2();
        break;
    case 2:
        update3();
        break;
    }

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = w;
    destRect.h = h;
    reachedEnd = AlienReachedEndpoint();
}

void Alien::update1()
{
    xpos += 5 * sin(ypos / 10);
    ypos += 3;
}

void Alien::update2()
{
    xpos -= (1 + 4 * sin(ypos / 10));
    ypos += 5;
}

void Alien::update3()
{
    xpos += 0;
    ypos += 2;
}

bool Alien::AlienReachedEndpoint()
{
    if(index == 1)
        return ypos >= WINDOW_H*3/2;
    else if(index == 2)
        return ypos >= WINDOW_H*5/4;
    else
        return ypos >= WINDOW_H;
}

const char *Alien::images[] = {"images/alien.png", "images/monster.png", "images/ufoSprites.png"};

void Alien::Render()
{
    if(index == 2)
    {
        c+=1;
        c = c%28;
        if(c < 4)
        {
            im = 0;
        }
        else if(c >= 4 && c <8)
        {
            im = 1;
        }
        else if(c >= 8 && c <12)
        {
            im = 2;
        }
        else if(c >= 12 && c <16)
        {
            im = 3;
        }
        else if(c >= 16 && c <20)
        {
            im = 4;
        }
        else if(c >= 20 && c <24)
        {
            im = 5;
        }
        else if(c >= 24 && c <28)
        {
            im = 6;
        }
        Animate(im);
        //GameObject::Render();
    }
    else
    {
        GameObject::Render();
    }

    if (reachedEnd)
    {
        // cout << "Rendering new alien" << endl;
        // srand(time(0));
        xpos = Game::randomNumberGenerator(9619) % (WINDOW_W * 800 / 900);
        ypos = 0;
        reachedEnd = false;
        // srand(time(0));
        index = Game::randomNumberGenerator(46578) % 3;
        objTexture = TextureManager::LoadTexture(images[index]);
    }
    
}

void Alien::Animate(int i)
{
    srcRect.x = ufo[i][0];
    srcRect.y = ufo[i][1];
    destRect.w = srcRect.w = ufo[i][2];
    destRect.h = srcRect.h = ufo[i][3];
    // if (dir <= 1)
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    // else
    //     SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_HORIZONTAL);
}