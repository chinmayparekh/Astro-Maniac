#ifndef Score_hpp
#define Score_hpp
#include "Game.hpp"
class Score
{
private:
    SDL_Rect r;
    SDL_Texture *tx = NULL;
    SDL_Rect r1;
    SDL_Texture *tx1 = NULL;

public:
    Score();
    ~Score()
    {
        if(tx)
            SDL_DestroyTexture(tx);
        if(tx1)
            SDL_DestroyTexture(tx1);
    }
    void render(int cnt, int highScore);
};

#endif //SCORE_H