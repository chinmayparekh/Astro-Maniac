#ifndef Button_hpp
#define Button_hpp
#include "GameObject.hpp"

class Button : public GameObject
{
    public:
        Button(const char *texturesheet, float x, float y, int width, int height);
};

#endif 
