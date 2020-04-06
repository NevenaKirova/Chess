//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Piece.h"

class Board {

private:

    Piece *board[8][8];

public:

    Board();

    Piece *getPosition(int horizontal, int vertical);

    void setPosition(Piece *piece, int horizontal, int vertical);
};


#endif //CHESS_BOARD_H
