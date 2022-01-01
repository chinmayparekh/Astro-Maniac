#ifndef Cntrl_Window_hpp
#define Cntrl_Window_hpp

#include "../include/Window.hpp"
using namespace std;
class Cntrl_Window: public Window
{
    public:
        Cntrl_Window();
        ~Cntrl_Window();

        void init(const char *title, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void renderNew();
        void Clean();
};


#endif