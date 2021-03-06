#include "../include/GameObject.hpp"

GameObject::GameObject(const char *texturesheet, float x, float y, int width, int height)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    w = width;
    h = height;
}

void GameObject::update(float p, float q)
{
    xpos += p;
    ypos += q;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = w;
    destRect.h = h;
}

void GameObject::Render()
{
    SDL_RenderCopy(Window::renderer, objTexture, NULL, &destRect);
}