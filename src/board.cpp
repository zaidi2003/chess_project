 #define SDL_MAIN_HANDLED
#include <board.hpp>


Board::Board(){
    // pawn init
    for(int i=0;i<8;i++){
        board_arr[1][i].isEmpty = false;
        board_arr[6][i].isEmpty = false;
    }
}


// this will construct the board and populate it with parts
void Board::printBoard(SDL_Window* window,SDL_Renderer* renderer){
    SDL_Rect rectangle,rect2;
    rectangle.w = 64;
    rectangle.h = 64;
    rect2.w = 64;
    rect2.h = 64;
    for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){
                   
            if((i+j)%2 ==0){
                rectangle.x = 0+(64*(j));
                rectangle.y = 0+(64*i);
                  
                SDL_SetRenderDrawColor(renderer,238,238,210,SDL_ALPHA_OPAQUE);    
                SDL_RenderDrawRect(renderer,&rectangle);
                SDL_RenderFillRect(renderer,&rectangle);
            }
            else
                {
                
                rectangle.x = 0+(64*(j));
                rectangle.y = 0+(64*i);
                SDL_SetRenderDrawColor(renderer,118,150,86,SDL_ALPHA_OPAQUE);    
                SDL_RenderDrawRect(renderer,&rectangle);
                SDL_RenderFillRect(renderer,&rectangle);
                }

            if(board_arr[i][j].isEmpty){
                
            }
            else{
                rect2.x = 0+(64*(j));
                rect2.y = 0+(64*i);
                SDL_Surface* pawn = IMG_Load("./res/king.png");
                SDL_Texture* pawn_texture = SDL_CreateTextureFromSurface(renderer,pawn);

                SDL_RenderCopy(renderer,pawn_texture,NULL,&rect2);
                SDL_DestroyTexture(pawn_texture);
            }

        }
    }

    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}


// this will fill the board with the remaining pieces
