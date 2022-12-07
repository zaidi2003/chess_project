 #define SDL_MAIN_HANDLED
#include <board.hpp>


Board::Board(){   
    // initalizing the pawns
    for(int i=0;i<8;i++){
        board_arr[1][i] = 65;
        board_arr[6][i] = 129;
    }

    // initializing all the black pieces
    board_arr[0][0] = 72; board_arr[0][7] = 72;
    board_arr[0][1] = 66; board_arr[0][6] = 66;
    board_arr[0][2] = 68; board_arr[0][5] = 68; // bishops
    board_arr[0][3] = 80; //Queen
    board_arr[0][4] = 96; //King
    // initalizing all the white pieces
    board_arr[7][0] = 136; board_arr[7][7] = 136; //rook
    board_arr[7][1] = 130; board_arr[7][6] = 130; //knights
    board_arr[7][2] = 132; board_arr[7][5] = 132; //bishops
    board_arr[7][3] = 144; //Queen
    board_arr[7][4] = 160; //King
    
}


// this will construct the board 
void Board::printBoard(SDL_Window* window,SDL_Renderer* renderer){
    SDL_Rect rectangle;
    rectangle.w = 64;
    rectangle.h = 64;

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
        }
    }
    printPieces(window,renderer);
    
    
}

// this will fill the board with the remaining pieces
void Board::printPieces(SDL_Window* window,SDL_Renderer* renderer){
    SDL_Surface* piece;
    SDL_Texture* piece_texture; 
     
    SDL_Rect rect2;
    rect2.w = 64;
    rect2.h = 64;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rect2.x = 0+(64*(j));
            rect2.y = 0+(64*i);
            if(board_arr[i][j]){
                switch (board_arr[i][j])
                {
                case 65:
                    piece = IMG_Load("./res/65.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 66:
                    piece = IMG_Load("./res/66.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 68:
                    piece = IMG_Load("./res/68.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 72:
                    piece = IMG_Load("./res/72.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 80:
                    piece = IMG_Load("./res/80.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 96:
                    piece = IMG_Load("./res/96.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;    
                case 129:
                    piece = IMG_Load("./res/129.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 130:
                    piece = IMG_Load("./res/130.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 132:
                    piece = IMG_Load("./res/132.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 136:
                    piece = IMG_Load("./res/136.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 144:
                    piece = IMG_Load("./res/144.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                case 160:
                    piece = IMG_Load("./res/160.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                default:
                    piece = IMG_Load("./res/king.png");
                    piece_texture = SDL_CreateTextureFromSurface(renderer,piece);
                    break;
                }
                
                SDL_RenderCopy(renderer,piece_texture,NULL,&rect2);
                SDL_DestroyTexture(piece_texture);
                SDL_FreeSurface(piece);
            }
        }
        
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    
}


void Board::click_movePiece(int x_initial,int y_initial,int x_final, int y_final, SDL_Window* window,SDL_Renderer* renderer){
    int x1,y1,x2,y2;
    x1 = x_initial/64;
    y1 = y_initial/64;

    x2 = x_final/64;
    y2 = y_final/64;
    switch (board_arr[y1][x1])
    {
    case 65:
        if(validatePawn_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 66:
        if(validateKnight_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 68:
        if(validateBishop_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 72:
        if(validateRook_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 80:
        if(validateQueen_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 96:
        if(validateKing_Black(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 129:
        if(validatePawn_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 130:
        if(validateKnight_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 132:
        if(validateBishop_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 136:
        if(validateRook_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 144:
        if(validateQueen_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    case 160:
        if(validateKing_White(x1,y1,x2,y2)){
            board_arr[y2][x2]=board_arr[y1][x1];
            board_arr[y1][x1] = 0;
        }
        else{
            break;
        }
    default:
        break;
    }
    printBoard(window,renderer);
}

void Board::printBoard_term(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board_arr[i][j] <<"  ";
        }
        cout << endl;
    }
}



bool Board::validatePawn_Black(int x1,int y1,int x2,int y2){
    if(x2>7 || y2>7 || x2<0 || y2<0){return false;}
    if(board_arr[y2][x2]>0 && board_arr[y2][x2]<=96){ return false;}// a piece cant move on to a piece from its own team
    if(y1-y2>0){return false;} // pawns cant move back
    if(abs(x1-x2)>1 || abs(y2-y1)>2){return false;} //pawns cant move 2places right/left or 3places up down
    if(y1 !=1 && y2-y1==2){return false;} //pawns can only move 2 places on first move
    if(abs(y2-y1)==2 && (abs(x2-x1))){return false;} // cant move like a knight

    if((abs(x2-x1) == 1 && abs(y2-y1)==1) && board_arr[y2][x2] < 128){return false;} // i think this code is redundant
    if(abs(x2-x1)==1 && !(y2-y1)){return false;} //piece cant move just sideways
    if(abs(y2-y1)==1 && !(x2-x1)  && board_arr[y2][x2]>=129){return false;} // cant move if obstacle in way
    
    return true;
}

bool Board::validatePawn_White(int x1,int y1,int x2,int y2){
    if(x2>7 || y2>7 || x2<0 || y2<0){return false;}

    if(board_arr[y2][x2]>=129 && board_arr[y2][x2]<=256){ return false;}// a piece cant move on to a piece from its own team
    if(y2-y1>0){return false;} // pawns cant move back
    if(abs(x1-x2)>1 || abs(y2-y1)>2){return false;} //pawns cant move 2places right/left or 3places up down
    if(y1 !=6 && y1-y2==2){return false;} //pawns can only move 2 places on first move
    if(abs(y2-y1)==2 && (abs(x2-x1))){return false;} // cant move like a knight

    if((abs(x2-x1) == 1 && abs(y2-y1)==1) && (board_arr[y2][x2] > 129 || board_arr[y2][x2] == 0)){return false;}
    if(abs(x2-x1)==1 && !(y2-y1)){return false;} //piece cant move just sideways 
    if(abs(y2-y1)==1 && !(x2-x1)  && (board_arr[y2][x2]<=128 && board_arr[y2][x2]>0 )){return false;} // cant move if obstacle in way

    return true;
}

bool Board::validateKnight_Black(int x1,int y1,int x2,int y2){
    if(x2>7 || y2>7 || x2<0 || y2<0){return false;}
    if(board_arr[y2][x2]>0 && board_arr[y2][x2]<=96){ return false;}// a piece cant move on to a piece from its own team    
    if(!(abs(y2-y1)==2 && abs(x2-x1)==1) && !(abs(y2-y1)==1 && abs(x2-x1)==2)){return false;}
    return true;
}

bool Board::validateKnight_White(int x1,int y1,int x2,int y2){
    if(x2>7 || y2>7 || x2<0 || y2<0){return false;}
    if(board_arr[y2][x2]>=129 && board_arr[y2][x2]<=256){ return false;}// a piece cant move on to a piece from its own team
    if(!(abs(y2-y1)==2 && abs(x2-x1)==1) && !(abs(y2-y1)==1 && abs(x2-x1)==2)){return false;}
    return true;
}

bool Board::validateBishop_Black(int x1,int y1,int x2,int y2){
    if(board_arr[y2][x2]>0 && board_arr[y2][x2]<=96){ return false;}// a piece cant move on to a piece from its own team
    if(((abs(x2-x1)) && !(abs(y2-y1))) || (abs(x2-x1)) && !(abs(y2-y1)) ){return false;} // cant move JUST horizontally or vertically
    if(abs(x2-x1)/abs(y1-y2) >1 || abs(x2-x1)/abs(y1-y2) <1){return false;} // it has to move at a ratio

    
    return true;
}

bool Board::validateBishop_White(int x1,int y1,int x2,int y2){
    if(board_arr[y2][x2]>=129 && board_arr[y2][x2]<=256){ return false;}// a piece cant move on to a piece from its own team
    if(((abs(x2-x1)) && !(abs(y2-y1))) || (abs(x2-x1)) && !(abs(y2-y1)) ){return false;} // cant move JUST horizontally or vertically
    if(abs(x2-x1)/abs(y1-y2) >1 || abs(x2-x1)/abs(y1-y2) <1){return false;} // it has to move at a ratio

    cout << abs(x2-x1) << endl;
    for(int i=1;i<abs(x2-x1);i++){
        if(board_arr[y1-i][x1-i]<128 && board_arr[y1-i][x1-i]>0){cout << "l";}
    }
    
    
    return true;
}

bool Board::validateRook_Black(int x1,int y1,int x2,int y2){return true;}

bool Board::validateRook_White(int x1,int y1,int x2,int y2){return true;}

bool Board::validateQueen_Black(int x1,int y1,int x2,int y2){return true;}

bool Board::validateQueen_White(int x1,int y1,int x2,int y2){return true;}

bool Board::validateKing_Black(int x1,int y1,int x2,int y2){return true;}

bool Board::validateKing_White(int x1,int y1,int x2,int y2){return true;}

bool checkMate(){}

