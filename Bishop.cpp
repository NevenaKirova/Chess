//
// Created by Nevena Kirova on 6.04.20.
//

#include "Bishop.h"
#include "Moves.h"

bool Bishop::isBishop(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Bishop") {

        if (abs(y2 - y1) != abs(x2 - x1)) return false;

        if (y2 > y1 && x2 > x1) {
           Moves::bishopUpRight(x1, x2, y1, y2, board);

        } else if (y2 > y1 && x2 < x1) {
           Moves::bishopUpLeft(x1, x2, y1, y2, board);

        } else if (y2 < y1 && x2 < x1) {
           Moves::bishopDownLeft(x1, x2, y1, y2, board);

        } else if (y2 < y1 && x2 > x1) {
           Moves::bishopDownRight(x1, x2, y1, y2, board);
        }

        return true;
    }
    return false;
}

