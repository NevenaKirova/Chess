//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Board.h"

class Knight {

public:
    static bool isKnight(int x1, int y1, int x2, int y2, Board *board);
};

#endif //CHESS_KNIGHT_H
