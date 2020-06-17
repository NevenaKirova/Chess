//
// Created by Nevena Kirova on 5.04.20.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Board.h"

class Pawn {
public:
    static bool isPawnMoveValid(int x1, int y1, int x2, int y2, Player player, Board *board);
};


#endif //CHESS_PAWN_H
