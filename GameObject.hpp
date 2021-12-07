#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"
#include "main.hpp"
#include "TextureManager.hpp"
class GameObject
{
public:
    GameObject(const char *texturesheet, int x, int y, int width, int height);
    ~GameObject();

    void update(int p, int q);
    void Render();
    int getX() { return xpos; }
    int getY() { return ypos; }
    void setX(int x){xpos = x;}
    void setY(int y){ypos = y;}
    int getHeight() { return h; }
    int getWidth() { return w; }
    void handleEvents();

protected:
    int xpos;
    int ypos;
    int w;
    int h;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};
#endif //GAMEOBJECT_HPP