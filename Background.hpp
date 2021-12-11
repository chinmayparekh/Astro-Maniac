#ifndef background_hpp
#define background_hpp
#include "GameObject.hpp"

class Background : public GameObject
{
    public:
        Background(const char *texturesheet, float x, float y, int width, int height);
        void update();

};

#endif
