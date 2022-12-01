#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include <board.hpp>
// imported the SDL Libraries
#include <iostream>
using namespace std;

// made class Game
class Game{
    public:
        Game(int x,int y,int w,int h,Uint32 flags); //initalized all the starting parameters
        void run(); // public function
        Board board;
        SDL_Window* window;
        SDL_Renderer* renderer;
    private:
        void init();
        void handleEvents();
        void display();
        void render();
        void startup();
        void end();
        bool gameStarted;
        bool gameIsRunning; // gameloop bool
        
};


