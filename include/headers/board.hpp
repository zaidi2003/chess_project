#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
// imported the SDL Libraries & other STDIO (maybe needed)
using namespace std;

class Board{
    public:
        Board();
        int board_arr[8][8] = {0};
        void printBoard(SDL_Window* window,SDL_Renderer* renderer);
        void printPieces(SDL_Window* window,SDL_Renderer* renderer);
        void click_movePiece(int x_initial,int y_initial,int x_final,int y_final,SDL_Window* window,SDL_Renderer* renderer);
        void printBoard_term();
    private:
        bool validatePawn_White(int x1,int y1,int x2,int y2);
        bool validatePawn_Black(int x1,int y1,int x2,int y2);
        bool validateKnight_White(int x1,int y1,int x2,int y2);
        bool validateKnight_Black(int x1,int y1,int x2,int y2);
        bool validateBishop_White(int x1,int y1,int x2,int y2);
        bool validateBishop_Black(int x1,int y1,int x2,int y2);
        bool validateRook_White(int x1,int y1,int x2,int y2);
        bool validateRook_Black(int x1,int y1,int x2,int y2);
        bool validateQueen_White(int x1,int y1,int x2,int y2);
        bool validateQueen_Black(int x1,int y1,int x2,int y2);
        bool validateKing_White(int x1,int y1,int x2,int y2);
        bool validateKing_Black(int x1,int y1,int x2,int y2);

};