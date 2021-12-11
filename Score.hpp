#include "Game.hpp"


class Score 
{
    private:
        SDL_Rect r;
        SDL_Texture *tx;
        SDL_Rect r1;
        SDL_Texture *tx1;
        int c = 0;
        
    public:
        Score();
        void update(int cnt);
};