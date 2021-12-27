#ifndef Fuel_hpp
#define Fuel_hpp
#include "GameObject.hpp"
#include "Player.hpp"
class Fuel : public GameObject
{
public:
    Fuel(const char *texturesheet, int x, int y, int width, int height);
    ~Fuel();
    virtual void update(Player *player);
    virtual void Render();
    void setisCollected(bool isCollected)
    {
        this->isCollected = isCollected;
    }
    bool tookFuel(GameObject *go, float dis);
    bool getPlayerStatus()
    {
        return die;
    }

private:
    bool isCollected = false;
    int count = 0;
    bool die = false;
};

#endif