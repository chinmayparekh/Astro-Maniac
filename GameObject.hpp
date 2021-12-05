#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char *texturesheet, int x, int y, int width, int height);
    ~GameObject();

    void update(int p, int q);
    void Render();

private:
    int xpos;
    int ypos;
    int w;
    int h;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};