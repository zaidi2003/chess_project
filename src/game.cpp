#include <game.hpp>
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>

Game::Game(int x,int y,int w,int h, Uint32 flags){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("CHESS",x,y,w,h,flags);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    run();
}

void Game::run(){
    gameIsRunning = true;
    int c= 0;
    while(gameIsRunning){
        handleEvents();
    }
}


void Game::handleEvents(){
    SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                gameIsRunning=false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                cout << "bUTTON PRESSED";
                break;
            default:
                break;
            }
            
        }
}