#include "Alien.hpp"

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
}