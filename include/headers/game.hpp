#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
// imported the SDL Files
#include <iostream>
using namespace std;

// made class Game
class Game{
    public:
        Game(int x,int y,int w,int h,Uint32 flags); //initalized all the starting parameters
        void run(); // public function
    private:
        void init();
        void handleEvents();
        void display();
        void render();
        void startup();
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool gameIsRunning;
};



