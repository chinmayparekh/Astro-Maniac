#ifndef Window_hpp
#define Window_hpp

#include "GameObject.hpp"
#include "main.hpp"
using namespace std;
class Window
{
public:
    Window();
    ~Window();

    virtual void init(const char *title, int width, int height, bool fullscreen);
    virtual void handleEvents();
    virtual void update();
    bool running() { return isRunning; }
    virtual void render();
    virtual void renderNew(){}
    void clean();
    static int randomNumberGenerator(int limit)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, limit);
        return dis(gen);
    }

    static SDL_Renderer *renderer;
    static SDL_Event event;

protected:
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
};

#endif //WINDOW_H
