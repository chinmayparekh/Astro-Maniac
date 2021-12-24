#include "Fuel.hpp"
#include "Game.hpp"

Fuel::Fuel(const char *texturesheet, int x, int y, int width, int height) : GameObject(texturesheet, x, y, width, height) {}

inline double distanceSq(float x1, float y1, float x2, float y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool Fuel::tookFuel(GameObject *go, float dis)
{
    if ((distanceSq(go->getX(), go->getY(), getX(), getY()) < dis)) //checking collision
    {
        return true;
    }
    return false;
}

void Fuel::update(Player *player)
{
    if (tookFuel(player, 5000))
    {
        xpos = Game::randomNumberGenerator(2543) % (WINDOW_W * 800 / 900);
        ypos = 0;
        count = 0;
    }
    else if (ypos > WINDOW_H * 830 / 900)
    {
        xpos = Game::randomNumberGenerator(2543) % (WINDOW_W * 800 / 900);
        ypos = 0;
        count++;
        if (count == 3)
        {
            die = true;
        }
    }
    else
    {
        ypos += 1.5;
    }
    GameObject::update(0, 1.5);
}
void Fuel::Render()
{
    GameObject::Render();
}
