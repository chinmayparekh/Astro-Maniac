#include "../include/Game.hpp"
#include "../include/Cntrl_Window.hpp"
#include <fstream>
#include <string>
Game *game = nullptr;
vector<int> scores;
int wn = 0;
void fileWrite(fstream &filepointer, int scoreKeeper)
{
    scores.push_back(scoreKeeper);
    sort(scores.begin(), scores.end());
    for (int i = 0; i < scores.size(); i++)
    {
        (filepointer) << "Score = " << scores[scores.size() - 1 - i] << endl;
    }
}

void fileRead(fstream &MyReadFile)
{
    string myText;
    while (getline(MyReadFile, myText))
    {
        scores.push_back((stoi(myText.substr(7))));
    }
}
int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    fstream file_input;
    fstream file_output;
    file_input.open("scoresheet.txt");
    fileRead(file_input);
    file_input.close();
    
    int scoreKeeper = 0;

    Window *win = new Window();
    win->init("MENU", WINDOW_W, WINDOW_H, false);
    while (win->running())
    {
        frameStart = SDL_GetTicks();
        win->handleEvents();
        win->update(wn);
        win->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    wn = 1;
    int hScore;
    if (scores.size())
        hScore = scores[0];
    else
        hScore = 0;

    game = new Game();
    // win->clean();
    // delete(win);
    game->init("Astro Maniac ", WINDOW_W, WINDOW_H, false, hScore);
    while (game->running())
    {
        scoreKeeper++;
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update(wn);
        if (!game->running())
        {
            break;
        }
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    // game->clean();
    win->clean();
    delete(win);
    delete(game);

    // cout << "Window cleared" << endl;
    // cout << "Window deleted" << endl;
    // cout << "Game cleared" << endl;
    file_output.open(argv[1]);
    fileWrite(file_output, scoreKeeper / 10);
    file_output.close();
    return 0;
}
