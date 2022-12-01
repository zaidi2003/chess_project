#include <game.hpp>
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>

Game::Game(int x,int y,int w,int h, Uint32 flags){
    SDL_Init(SDL_INIT_VIDEO); // initialized SDL2

    window = SDL_CreateWindow("CHESS",x,y,w,h,flags); // creates a window using the parameters we gave
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);        
}

void Game::run(){
    gameIsRunning = true;
    gameStarted = false;
    startup();
    while(gameIsRunning){
        
        handleEvents();
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleEvents(){
    SDL_Event event;
        if(SDL_WaitEvent(&event)!=0){
           

            switch (event.type)
            {
            case SDL_QUIT:
                gameIsRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    if(!gameStarted){
                        board.printBoard(window,renderer);
                        gameStarted = true;
                    }
                    break;

                default:
                    break;
                }
            default:
                break;
            }
        }
}

void Game::startup(){
    SDL_Surface* icon = IMG_Load("./res/chess_icon.png");
    SDL_SetWindowIcon(window, icon);
    SDL_Rect rectangle;
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    cout << endl;
    rectangle.x = 0;rectangle.y = 0;rectangle.w = 512;rectangle.h = 512;
    
    SDL_Surface* start_screen = IMG_Load("./res/start1.png");
    SDL_Texture* start_screen_texture = SDL_CreateTextureFromSurface(renderer,start_screen);
    
    
    SDL_RenderCopy(renderer,start_screen_texture,NULL,&rectangle);
    SDL_DestroyTexture(start_screen_texture);
    display();

    
}
    


void Game::render(){
    cout << " Empty Function ";
}

void Game::display(){
    SDL_RenderPresent(renderer); // display my current renderer
}


