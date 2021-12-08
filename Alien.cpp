#include "Alien.hpp"
#include <time.h>
#include <math.h>
using namespace std;
Alien::Alien(const char *texturesheet, int x, int y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}
// Alien::~Alien() {}
void Alien::update()
{
    xpos += 0;
    ypos += 2;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = w;
    destRect.h = h;
    reachedEnd = AlienReachedEndpoint();
}

bool Alien::AlienReachedEndpoint()
{
    return ypos >= 900;
}

void Alien::Render()
{
    if (reachedEnd)
    {
        // cout << "Rendering new alien" << endl;
        // srand(time(0));
        xpos = rand() % 800;
        ypos = 0;
        reachedEnd = false;
    }

    GameObject::Render();
}