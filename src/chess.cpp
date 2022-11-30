#define SDL_MAIN_HANDLED
#include <game.hpp>


using namespace std;


int main(int argc, char*argv[]){
    int _screenWidth  = 512;
    int _screenHeight = 512;

    Game game(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight,SDL_WINDOW_SHOWN);

}


