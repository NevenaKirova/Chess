//
// Created by Nevena Kirova on 6/10/18.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>
#include <fstream>
#include "Piece.h"
#include "Board.h"
using namespace std;

class Game {

private:
    //Piece board [8][8];
    Board *board;
public:

    Game();

    void printBoard();

    void printMenu();

    int letterToCoord(char);

    bool checkMove(int, int, int, int, Player);

    void movePiece(int x1, int y1, int x2, int y2, Player player);

    void save();

    void load();
};


#endif //CHESS_GAME_H


