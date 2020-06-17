//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Board.h"

class Bishop {

public:
    static bool isBishopMoveValid(int x1, int y1, int x2, int y2, Board *board);
};

#endif //CHESS_BISHOP_H
