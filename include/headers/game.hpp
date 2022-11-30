#pragma once
#include <game.hpp>
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>

#include <iostream>
using namespace std;


class Game{
    public:
        Game(int x,int y,int w,int h,Uint32 flags);
        void run();
    private:
        void init();
        void handleEvents();
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool gameIsRunning;
};