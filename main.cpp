#include "Game.hpp"
#include <fstream>
#include <string>
Window *game = nullptr;
vector<int> scores;
void fileWrite(fstream &filepointer, int scoreKeeper)
{
    // (filepointer) << "Score = " << scoreKeeper << endl;
    // for (int i = 0; i < scores.size(); i++)
    // {
    //     cout << "Score = " << scores[i] << endl;
    // }
    scores.push_back(scoreKeeper);

    cout << "new score is pushed in the vector" << endl;
    cout << "Size of score finally = " << scores.size() << endl;

    sort(scores.begin(), scores.end());
    for (int i = 0; i < scores.size(); i++)
    {
        cout << i << " " << scores[i] << endl;
        (filepointer) << "Score = " << scores[i] << endl;
    }
}

void fileRead(fstream &MyReadFile)
{
    string myText;

    // Read from the text file
    // ifstream MyReadFile("output.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        scores.push_back((stoi(myText.substr(7))));
        cout << myText << endl;
    }
    cout << "Size of score initially = " << scores.size() << endl;
}
int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    fstream file_input;
    fstream file_output;
    // file_input.open(argv[1]);
    file_input.open("output.txt");
    cout << "File is opened" << endl;
    file_output.open(argv[1]);
    int scoreKeeper = 0;
    fileRead(file_input);

    Window* win = new Window();
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
        // cout << scoreKeeper / 10 << endl;
        game->handleEvents();
        game->update();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    cout << "Final score = " << scoreKeeper / 10 << endl;
    fileWrite(file_output, scoreKeeper / 10);
    game->clean();
    return 0;
}
