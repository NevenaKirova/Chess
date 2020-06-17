//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Board.h"

class King {

public:
    static bool isKingMoveValid(int x1, int y1, int x2, int y2, Board *board);
};

#endif //CHESS_KING_H
