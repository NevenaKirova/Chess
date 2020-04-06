//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Game.h"
#include "Board.h"

class Rook {
public:
    static bool isRook(int x1, int y1, int x2, int y2, Board *board);

};

#endif //CHESS_ROOK_H
