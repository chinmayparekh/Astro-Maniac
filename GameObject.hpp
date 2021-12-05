#include"Game.hpp"

class GameObject
{
    public:
        GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int width, int height);
        ~GameObject();

        void update(int p, int q);
        void Render();

    private:
        int xpos;
        int ypos;
        int w;
        int h;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
};