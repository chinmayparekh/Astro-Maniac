#ifndef textwindow_hpp
#define textwindow_hpp
#include "Game.hpp"
class textwindow
{
private:
    SDL_Rect r;
    SDL_Texture *tx = NULL;
    SDL_Rect r1;
    SDL_Texture *tx1 = NULL;

public:
    textwindow();
    ~textwindow();
    void render(int clickn);
};

#endif //SCORE_H