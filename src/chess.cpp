#define SDL_MAIN_HANDLED
#include <game.hpp>

// imported my game headers files

using namespace std;


int main(int argc, char*argv[]){
    int _screenWidth  = 512; // screen width
    int _screenHeight = 512; // screen height


    Game game(SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight,SDL_WINDOW_SHOWN); // initalized a game object
    game.run(); // running the game

    return 0;
}
