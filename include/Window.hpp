#ifndef Window_hpp
#define Window_hpp

#include "GameObject.hpp"
#include "main.hpp"
using namespace std;
class Window
{
public:
    Window();
    virtual ~Window();

    virtual void init(const char *title, int width, int height, bool fullscreen);
    virtual void handleEvents();
    virtual void update(int wn);
    bool running() { return isRunning; }
    bool running1() { return is_Running; }
    virtual void render();
    virtual void renderNew() {}
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
    bool is_Running = false;
    int cnt = 0;
    int winno;
    int t = 0;
    SDL_Window *window;
};

#endif //WINDOW_H
