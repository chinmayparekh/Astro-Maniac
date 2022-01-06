// #include "Alien.hpp"
#include "../include/Alien.hpp"
#include "../include/main.hpp"
#include "../include/Game.hpp"
#include "../include/GameObject.hpp"
#include <time.h>
#include <math.h>
using namespace std;
Alien::Alien(const char *texturesheet, float x, float y, int width, int height, int index) : GameObject(texturesheet, x, y, width, height)
{
    this->index = index;
}

Alien::Alien(const char *texturesheet, int index) : GameObject(texturesheet, 0, 0, 0, 0)
{
    this->index = index;
    setPosition();
}
int Alien::spawnRegion = 1;

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
            update0();
            break;
        case 1:
            update1();
            break;
        case 2:
            update2();
            break;
        case 3:
            updateBullet();
            break;
    }

    destRect.x = xpos;
    destRect.y = ypos;
    reachedEnd = AlienReachedEndpoint();
}

void Alien::update0()
{
    xpos += 5 * sin(ypos / 10);
    ypos += 3;
}

void Alien::update1()
{
    xpos -= (1 + 4 * sin(ypos / 10));
    ypos += 5;
}

void Alien::update2()
{
    xpos += 0;
    ypos += 2;
    if(bullet == NULL)
        bullet = new Alien("../images/newBullet.png", xpos, ypos, 100, 100, 3);
    bullet->update();
}

void Alien::updateBullet()
{
    xpos += 0;
    ypos += 5;

}

bool Alien::AlienReachedEndpoint()
{
    if (index == 1)
        return ypos >= WINDOW_H * 3 / 2;
    else if (index == 2)
        return ypos >= WINDOW_H * 5 / 4;
    else
        return ypos >= WINDOW_H;
}

const char *Alien::images[] = {"../images/alien.png", "../images/monster.png", "../images/ufoSprites.png"};

void Alien::Render()
{
    if (index == 2)
    {
        c += 1;
        c = c % 28;
        if (c < 4)
        {
            im = 0;
        }
        else if (c >= 4 && c < 8)
        {
            im = 1;
        }
        else if (c >= 8 && c < 12)
        {
            im = 2;
        }
        else if (c >= 12 && c < 16)
        {
            im = 3;
        }
        else if (c >= 16 && c < 20)
        {
            im = 4;
        }
        else if (c >= 20 && c < 24)
        {
            im = 5;
        }
        else if (c >= 24 && c < 28)
        {
            im = 6;
        }
        Animate(im);
        SDL_RenderCopy(Game::renderer, bullet->getTexture(), NULL, bullet->getdestRect());

        // bullet->Render();
    }
    else
    {
        GameObject::Render();
    }

    if (reachedEnd && index != 3)
    {
        // delete(objTexture);
        SDL_DestroyTexture(objTexture);
        index = Game::randomNumberGenerator(46578) % 3;
        objTexture = TextureManager::LoadTexture(images[index]);
        setPosition();
        reachedEnd = false;
        if(bullet)
        {
            delete(bullet);
            bullet = NULL;
        }
    }
}

void Alien::Animate(int i)
{
    srcRect.x = ufo[i][0];
    srcRect.y = ufo[i][1];
    srcRect.w = ufo[i][2];
    srcRect.h = ufo[i][3];
    destRect.w = wa2;
    destRect.h = ha2;
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void Alien::setPosition()
{
    switch (index)
    {
    case 0:
        w = wa0;
        h = ha0;
        break;
    case 1:
        w = wa1;
        h = ha1;
        break;
    case 2:
        w = wa2;
        h = ha2;
        break;
    }
    xpos = Game::randomNumberGenerator((WINDOW_W - 5 * w) * 1000) * 1.0 / 1000;
    xpos = (spawnRegion * WINDOW_W * 1.0) / 3 + xpos / 3;
    ypos = 0;
    spawnRegion = (spawnRegion + 2) % 3;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = w;
    destRect.h = h;
    reachedEnd = AlienReachedEndpoint();
}