#pragma once
#include <pieces.hpp>
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
// imported the SDL Libraries & other STDIO (maybe needed)
using namespace std;

class Spot{
    public:
        Spot(){}; // spot code
        bool isEmpty=true;
        Piece piece;
};

class Board{
    public:
        Board();
        Spot board_arr[8][8];
        void printBoard(SDL_Window* window,SDL_Renderer* renderer);
        
    private:
        
};