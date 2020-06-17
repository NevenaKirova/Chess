//
// Created by Nevena Kirova on 6.04.20.
//

#include "Rook.h"
#include "Moves.h"

bool Rook::isRookMoveValid(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Rook") {

        if (x1 == x2) { // Vertical move

            if (y2 > y1) {
                Moves::rookGoesUp(x1, y1, y2, board);
                return true;

            } else {
               Moves::rookGoesDown(x1, y1, y2, board);
                return true;
            }

        } else if (y1 == y2) { // Horizontal move

            if (x2 > x1) {
                Moves::rookGoesRight(x1, x2, y1, board);
                return true;

            } else {
                Moves::rookGoesLeft(x1, x2, y1, board);
                return true;
            }

        } else {
            return false;
        }
    }
    return false;
}

