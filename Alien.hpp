#ifndef Alien_hpp
#define Alien_hpp
#include "GameObject.hpp"

class Alien : public GameObject
{
public:
    Alien(const char *texturesheet, int x, int y, int width, int height);
    // ~Alien();
    void update();


};

#endif
