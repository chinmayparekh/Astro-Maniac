#include "../include/Player.hpp"
#include "../include/Window.hpp"
#include "../include/main.hpp"

int ant[][4] = {
    {30, 0, 140, 140},
    {205, 0, 140, 140},
    {380, 0, 140, 140},
    {540, 0, 140, 140},
    {705, 0, 140, 140},
    {870, 0, 140, 140},
    {1030, 0, 140, 140},
    {1190, 0, 140, 140},
    {1365, 0, 140, 140}};

Player::Player(const char *texturesheet, float x, float y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}

void Player::handleEvents()
{
    if (Window::event.type == SDL_KEYDOWN)
    {
        move = 0;
        switch (Window::event.key.keysym.sym)
        {
        case SDLK_a:
            if (getX() > WINDOW_W - destRect.w - 1)
            {
                vel_X = 0;
            }
            else
            {
                vel_X = 5;
                dir = 2;
            }
            break;
        case SDLK_d:
            if (getX() < 0)
            {
                vel_X = 0;
            }
            else
            {
                vel_X = -5;
                dir = 1;
            }
            break;
        }
    }
    else
    {
        vel_X = 0;
    }
    setX(getX() + vel_X);
}

void Player::Render()
{
    if ((vel_X > 0 || move < 30) && dir == 2)
    {
        move++;
        moving = true;
        int cf;
        if (move < 3)
            cf = 8;
        else if (move < 6)
            cf = 7;
        else if (move < 9)
            cf = 6;
        else if (move < 12)
            cf = 5;
        else
            cf = 4;
        Animate(cf, dir);
    }
    else if ((vel_X < 0 || move > -30) && dir == 1)
    {
        move--;
        moving = true;
        int cf;
        if (move > -3)
            cf = 0;
        else if (move > -6)
            cf = 1;
        else if (move > -9)
            cf = 2;
        else if (move > -12)
            cf = 3;
        else
            cf = 4;
        Animate(cf, dir);
    }
    else if (moving)
    {
        moving = false;
        dir = 0;
        Animate(4, dir);
    }
    else
        Animate(4, 0);
}

void Player::Animate(int i, int dir)
{
    srcRect.x = ant[i][0];
    srcRect.y = ant[i][1];
    destRect.w = srcRect.w = ant[i][2];
    destRect.h = srcRect.h = ant[i][3];
    SDL_RenderCopy(Window::renderer, objTexture, &srcRect, &destRect);
}