#include "Alien.hpp"
#include <time.h>
#include "Game.hpp"
#include <math.h>
using namespace std;
Alien::Alien(const char *texturesheet, float x, float y, int width, int height, int index) : GameObject(texturesheet, x, y, width, height)
{
    this->index = index;
}
// Alien::~Alien() {}

int ufo[][4] = {
    //x y width and height
    {30, 0, 210, 110},
    {255, 0, 210, 110},
    {520, 0, 210, 110},
    {785, 0, 210, 110},
    {1035, 0, 210, 110},
    {1290, 0, 210, 110},
    {1535, 0, 210, 110},
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
    return ypos >= 900;
}

const char *Alien::images[] = {"images/alien.png", "images/monster.png", "images/ufo.png"};

void Alien::Render()
{
    /*if(index == 2)
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

        if (reachedEnd)
        {
            // cout << "Rendering new alien" << endl;
            // srand(time(0));
            xpos = Game::randomNumberGenerator(9619) % 800;
            ypos = 0;
            reachedEnd = false;
            // srand(time(0));
            index = Game::randomNumberGenerator(46578) % 3;
            objTexture = TextureManager::LoadTexture(images[index]);
        }

        Animate(im);
        //GameObject::Render();

    }*/
    //else
    //{
        if (reachedEnd)
        {
            // cout << "Rendering new alien" << endl;
            // srand(time(0));
            xpos = Game::randomNumberGenerator(9619) % 800;
            ypos = 0;
            reachedEnd = false;
            // srand(time(0));
            index = Game::randomNumberGenerator(46578) % 3;
            objTexture = TextureManager::LoadTexture(images[index]);
        }

        GameObject::Render();

    //}
    
}

/*void Alien::Animate(int i)
{
    srcRect.x = ufo[i][0];
    srcRect.y = ufo[i][1];
    destRect.w = srcRect.w = ufo[i][2];
    destRect.h = srcRect.h = ufo[i][3];
    // if (dir <= 1)
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    // else
    //     SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_HORIZONTAL);
}*/