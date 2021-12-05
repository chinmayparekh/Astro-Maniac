// #include <bits/stdc++.h>
// #include "SDL2/SDL.h"
// #include <SDL2/SDL_image.h>

// using namespace std;

// class Obstacle
// {
// protected:
//     float x, y;
//     int height, width;
//     string image;
//     float x_vel;
//     SDL_Rect destR;
//     SDL_Texture *playerTex;
//     SDL_Renderer *renderer;

// public:
//     Obstacle(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer);
//     float get_x() { return x; }
//     float get_y() { return y; }
//     int get_height() { return height; }
//     int get_width() { return width; }
//     float get_xvel() { return x_vel; }
//     void render();
//     virtual void update();

// };

#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "GameObject.hpp"

class Obstacle : public GameObject
{
public:
    Obstacle(const char *texturesheet, int x, int y, int width, int height);
    ~Obstacle();
};

#endif //Obstacle_H
