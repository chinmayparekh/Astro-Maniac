#ifndef TextureManager_hpp
#define TextureManager_hpp
#include "Window.hpp"
class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *filename);
};
#endif //TEXTUREMANAGER_HPP