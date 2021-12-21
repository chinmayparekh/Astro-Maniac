#include "Game.hpp"
#include <fstream>
#include <string>
Window *game = nullptr;
vector<int> scores;
void fileWrite(fstream &filepointer, int scoreKeeper)
{
    scores.push_back(scoreKeeper);
    sort(scores.begin(), scores.end());
    for (int i = 0; i < scores.size(); i++)
    {
        (filepointer) << "Score = " << scores[i] << endl;
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
    file_input.open("output.txt");
    file_output.open(argv[1]);
    int scoreKeeper = 0;
    fileRead(file_input);

    Window *win = new Window();
    win->init("First Window ", 900, 900, false);
    while (win->running())
    {
        frameStart = SDL_GetTicks();
        win->handleEvents();
        win->update();
        win->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game = new Game();
    game->init("Astro Maniac ", 900, 900, false);
    while (game->running())
    {
        scoreKeeper++;
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    fileWrite(file_output, scoreKeeper / 10);
    game->clean();
    return 0;
}
