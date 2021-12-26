#ifndef Alien_hpp
#define Alien_hpp
#include "GameObject.hpp"

enum iWidth
{
    wa0 = 70 * WINDOW_W / 900,
    wa1 = 70 * WINDOW_W / 900,
    wa2 = 80 * WINDOW_W / 900
};

enum iHeight
{
    ha0 = 70 * WINDOW_H / 900,
    ha1 = 70 * WINDOW_H / 900,
    ha2 = 80 * WINDOW_H / 900
};

class Alien : public GameObject
{
public:
    Alien(const char *texturesheet, float x, float y, int width, int height, int index);
    Alien(const char *texturesheet, int index);
    void update();
    void update0();
    void update1();
    void update2();
    void setPosition();
    bool AlienReachedEndpoint();
    void Render();
    void Animate(int i);
    static const char *images[];
    static int spawnRegion;

private:
    int flag = 0;
    bool reachedEnd = false;
    const char *picture;
    int index;
    int c = 0;
    int im;
};

#endif
