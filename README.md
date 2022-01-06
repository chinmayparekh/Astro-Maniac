# C++ Project- Astro Maniac (Group Number 8)

## Github Link:
---
https://github.com/chinmayparekh/Astro-Maniac

### Team members:
---

                Chinmay Parekh- IMT2020069
                Pavan Thanay - IMT2020024
                Tejdeep Gutta - IMT2020102
                Yash Mogal - IMT2020537
                Pratham Dandale - IMT2020038
---
                

## Contributions
---

| Name                               | Contribution                                                     |
| ----                               | ------------                                                     |
| Chinmay Parekh     |    Created game window,managed player movement,randomized spawning of enemies, collision detection and made file-based leaderboard system .    |
| Pavan Thanay                     |  Randomized spawning of enemies and meteors, managed animations,generalizing of code,background movement and performed memory management.   | 
| Tejdeep Gutta                    |  Made the GameObject,spritesheets,displayed dynamic score and generaliztion of code, Managed animations. | 
| Yash Mogal                        |    Made the transition between different windows, displaying text and image on the windows and added background music to the game.    |
| Pratham Dandale                         | Implemented randomized spawning of fuel and its collision detection and made makefile  |

---


### Use the following command in your terminal to clone the repository
---

git clone https://github.com/chinmayparekh/Astro-Maniac.git

## About Game
---

Astro-Maniac is a single-player endless-running space game. In which, the player controls the Spaceship at the bottom of the screen, which can move horizontally. Various obstacles (Alien, UFO, Asteroids, and Meteoroids) will be approaching the Spaceship. If any of the objects touch the Spaceship the player loses the game. Also, the player has to collect fuel tanks which will be spawning along with the obstacles to keep the game going. On missing three consecutive fuels the game comes to an end. In order to dodge the obstacles, the player has to move the spaceship left or right by pressing D and A from the keyboard respectively. This game becomes challenging as our mind has developed muscle memory of D as Right move and  A as left move.

## Requirements
---

Instructions for installing SDL2: 
For Windows: Go to the SDL2 website and head to the download page. Under Development Libraries choose SDL2-devel- [VERSION NUMBER] -VC.zip. Unzip and you will see several folders with the names docs, include, and lib. include contains the header files which we will be needing soon. Create a simple C++ VS project and copy/move the include directory in your project folder. Same thing with lib. Now in lib there exists two folders: x64 and x86.
In x86 contains the 32-bit version of the library whereas in x64 contains the 64-bit version

For Linux (Ubuntu): Enter the following command in terminal:
---

    sudo apt-get install libsdl2-dev

For installing other libraries run the following command:
---

    sudo apt-get install libsdl2-image-dev
    sudo apt-get install libsdl2-ttf-dev


## References
---

https://lazyfoo.net/tutorials/SDL/index.php


https://www.youtube.com/channel/UCAM9ZPgEIdeHAsmG50wqL1g

## Running the code
---

To compile and run the code:

    make
    ./run scoresheet.txt

## Images
---
![menu](https://user-images.githubusercontent.com/76399431/148392860-2e0f5641-ab70-4990-9b6a-65b68a952c09.png)

![controls](https://user-images.githubusercontent.com/76399431/148392977-c3dcd484-0439-440b-a66e-3679fd8eec20.png)

![game](https://user-images.githubusercontent.com/76399431/148393141-2ed0fb1d-671b-4690-ae3d-3e3dd230a9b0.png)



