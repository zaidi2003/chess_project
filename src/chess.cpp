#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>

using namespace std;

int main(int argc, char*argv[]){
    SDL_Surface* screen;
    SDL_Surface* icon = IMG_Load("./res/chess_icon.png");
    
    SDL_Window* window = nullptr;

    

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "Chess Game",
        500,
        250,
        512,
        512,
        SDL_WINDOW_SHOWN
    );

    SDL_SetWindowResizable(window,SDL_TRUE);
    SDL_SetWindowIcon(window, icon);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Rect rectangle;
    
    

    bool gameIsRunning = true;
    while(gameIsRunning){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                gameIsRunning=false;
                break;
            case SDL_WINDOWEVENT_RESIZED:
                cout << "size changed";
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_a:
                    cout << "A" << SDL_GetWindowSurface(window)->w;
                    break;
                case SDLK_w:
                    cout << "W";
                    break;
                case SDLK_s:
                    cout << "S";
                    break;
                case SDLK_d:
                    cout << "D";
                    break;
                case SDLK_c:
                    break;
                }
             
            default:
                break;
            }
            
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        
                
        

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){

                if((i+j)%2 ==0){

                }
                else
                {
                
                rectangle.x = 0+(64*(j));
                rectangle.y = 0+(64*i);
                rectangle.w = 64;
                rectangle.h = 64;  
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);    
                SDL_RenderDrawRect(renderer,&rectangle);
                SDL_RenderFillRect(renderer,&rectangle);
                SDL_RenderPresent(renderer);
                }
            }       
            
        }  
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}


