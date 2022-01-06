#ifndef GameObject_hpp
#define GameObject_hpp

#include "Window.hpp"
#include "main.hpp"
#include "TextureManager.hpp"
class GameObject
{
public:
    GameObject(const char *texturesheet, float x, float y, int width, int height);
    virtual ~GameObject()
    {
        SDL_DestroyTexture(objTexture);
    }

    void update(float p, float q);
    void Render();
    float getX() { return xpos; }
    float getY() { return ypos; }
    void setX(float x) { xpos = x; }
    void setY(float y) { ypos = y; }
    int getHeight() { return h; }
    int getWidth() { return w; }
    SDL_Texture* getTexture(){return objTexture;}
    void handleEvents();
    SDL_Rect *getSrcRect() { return &srcRect; }
    SDL_Rect *getdestRect() { return &destRect; }

protected:
    float xpos;
    float ypos;
    int w;
    int h;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};
#endif //GAMEOBJECT_HPP