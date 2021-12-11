#include "Background.hpp"
#include "GameObject.hpp"

using namespace std;

Background::Background(const char *texturesheet, float x, float y, int width, int height) : GameObject(texturesheet, x, y, width, height)
{
}

void Background::update()
{
    GameObject::update(0, 1);
    if(ypos >= 900)
        ypos = -900;
}