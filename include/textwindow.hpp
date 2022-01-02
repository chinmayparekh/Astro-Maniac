#ifndef textwindow_hpp
#define textwindow_hpp
#include "Game.hpp"
class textwindow
{
    private:
        SDL_Rect r;
        SDL_Texture *tx;
        SDL_Rect r1;
        SDL_Texture *tx1;
        
    public:
        textwindow();
        void render(int clickn);
};

#endif //SCORE_H