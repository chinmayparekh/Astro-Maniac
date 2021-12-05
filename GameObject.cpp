#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *texturesheet, int x, int y, int width, int height)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    w = width;
    h = height;
}

void GameObject::update(int p, int q)
{
    destRect.x = xpos - p;
    destRect.y = ypos + q;
    destRect.w = w;
    destRect.h = h;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}