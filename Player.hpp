#ifndef Player_hpp
#define Player_hpp
#include "GameObject.hpp"

class Player : public GameObject
{
    public:
        Player(const char *texturesheet, int x, int y, int width, int height);
        ~Player();

        // void update();
};

#endif //PLAYER_H