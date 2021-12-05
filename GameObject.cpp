#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject:: GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int width, int height)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
    xpos = x;
    ypos = y;
    w = width;
    h = height;
}

void GameObject::update(int p, int q)
{

    //srcRect.h = 40;
    //srcRect.w = 40;
    //srcRect.x = 0;
    //srcRect.y = 0;

    destRect.x = xpos - p;
    destRect.y = ypos + q;
    destRect.w = w;
    destRect.h = h;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}