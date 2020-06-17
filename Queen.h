//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Board.h"

class Queen {

public:
    static bool isQueenMoveValid(int x1, int y1, int x2, int y2, Board *board);

};

#endif //CHESS_QUEEN_H
