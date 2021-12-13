#include "Player.hpp"
#include "Game.hpp"
#include "main.hpp"

int ant[][4] = {
    //x y width and height
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
    if (Game::event.type == SDL_KEYDOWN)
    {
        move = 0;
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_a: //going right
            if (getX() > 745)
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
    Animate();
}

void Player::Animate()
{
    move++;
    if ((vel_X > 0 || move < 30) && dir == 2)
    {
        moving = true;
        if (move < 6)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right0.png"));
        else if (move < 12)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right1.png"));
        // else if(move < 45)
        //     objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right2.png"));
        else if (move < 18)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right2.png"));
        else if (move < 24)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right1.png"));
        else
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/right0.png"));
    }
    else if ((vel_X < 0 || move < 30) && dir == 1)
    {
        moving = true;
        if (move < 6)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left0.png"));
        else if (move < 12)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left1.png"));
        // else if(move < 45)
        //     objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left2.png"));
        else if (move < 18)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left2.png"));
        else if (move < 24)
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left1.png"));
        else
            objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/left0.png"));
    }
    else if (moving)
    {
        moving = false;
        dir = 0;
        objTexture = SDL_CreateTextureFromSurface(Game::renderer, IMG_Load("images/astronaut.png"));
    }
    Render();
}

void Player::handleEvents2()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        move = 0;
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_a: //going right
            if (getX() > 745)
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

void Player::Render2()
{
    move++;
    if ((vel_X > 0 || move < 35) && dir == 2)
    {
        moving = true;
        int cf;
        // if(move < 5)
        //     cf = 4 + (SDL_GetTicks() * 12 / 1000) % 4;
        // else 
        //     cf = 8 - (SDL_GetTicks() * 12 / 1000) % 4;
        
        if (move < 5)
            cf = 5;
        else if (move < 10)
            cf = 6;
        else if (move < 15)
            cf = 7;
        else if (move < 20)
            cf = 8;
        else if (move < 25)
            cf = 7;
        else if (move < 30)
            cf = 6;
        else
            cf = 5;
        Animate2(cf, dir);
    }
    else if ((vel_X < 0 || move < 35) && dir == 1)
    {
        moving = true;
        int cf;
        // if(move < 5)
        //     cf = 4 - (SDL_GetTicks() * 12 / 1000) % 4;
        // else 
        //     cf = (SDL_GetTicks() * 12 / 1000) % 4;
        // Animate2(cf, dir);
        // if (move < 5)
        //     Animate2(1, dir);
        // else if (move < 10)
        //     Animate2(2, dir);
        // else if (move < 15)
        //     Animate2(3, dir);
        // else if (move < 20)
        //     Animate2(4, dir);
        // else if (move < 25)
        //     Animate2(5, dir);
        // else if (move < 30)
        //     Animate2(4, dir);
        // else if (move < 35)
        //     Animate2(3, dir);
        // else if (move < 40)
        //     Animate2(2, dir);
        // else
        //     Animate2(1, dir);
        if (move < 5)
            cf = 3;
        else if (move < 10)
            cf = 2;
        else if (move < 15)
            cf = 1;
        else if (move < 20)
            cf = 0;
        else if (move < 25)
            cf = 1;
        else if (move < 30)
            cf = 2;
        else
            cf = 3;
        Animate2(cf, dir);
    }
    else if (moving)
    {
        moving = false;
        dir = 0;
        Animate2(4, dir);
    }
    else
        Animate2(4, 0);
}

void Player::Animate2(int i, int dir)
{
    srcRect.x = ant[i][0];
    srcRect.y = ant[i][1];
    destRect.w = srcRect.w = ant[i][2];
    destRect.h = srcRect.h = ant[i][3];
    // if (dir <= 1)
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    // else
    //     SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_HORIZONTAL);
}