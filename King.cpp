//
// Created by Nevena Kirova on 6.04.20.
//

#include "King.h"

bool King::isKing(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "King") {
        return (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1) ||
               (abs(x1 - x2) == 1 && abs(y1 - y2) == 1);
    }
    return false;
}
