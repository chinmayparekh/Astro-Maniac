#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
using namespace std;
class Game: public Window
{
    public:
        Game();
        ~Game();

        void init(const char *title, int width, int height, bool fullscreen, int highScore);
        void setHighScore(int hs){highScore = hs;}

        void handleEvents();
        void update();
        void renderNew();
        int highScore;
};

#endif //GAME_H
