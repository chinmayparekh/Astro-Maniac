#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
using namespace std;
class Game: public Window
{
    public:
        Game();
        ~Game();

        void init(const char *title, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void renderNew();
};

#endif //GAME_H
