#ifndef Score_hpp
#define Score_hpp
#include "Game.hpp"
class Score 
{
    private:
        SDL_Rect r;
        SDL_Texture *tx;
        SDL_Rect r1;
        SDL_Texture *tx1;
        
    public:
        Score();
        void render(int cnt, int highScore);
};

#endif //SCORE_H