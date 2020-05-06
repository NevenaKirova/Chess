//
// Created by Nevena Kirova on 6.04.20.
//

#include "Queen.h"
#include "Moves.h"

bool Queen::isQueen(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Queen") {

        if (x1 == x2) { // Vertical move
            if (y2 > y1) {
                Moves::queenGoesUp(x1, y1, y2, board);
                return true;

            } else {
                Moves::queenGoesDown(x1, y1, y2, board);
                return true;
            }

        } else if (y1 == y2) { // Horizontal move
            if (x2 > x1) {
                Moves::queenGoesRight(x1, x2, y1, board);
                return true;

            } else {
                Moves::queenGoesLeft(x1, x2, y1, board);
                return true;
            }

        } else {
            if (abs(y2 - y1) != abs(x2 - x1)) return false;

            if (y2 > y1 && x2 > x1) {
                Moves::queenUpRight(x1, x2, y1, y2, board);

            } else if (y2 > y1 && x2 < x1) {
                Moves::queenUpLeft(x1, x2, y1, y2, board);

            } else if (y2 < y1 && x2 < x1) {

                Moves::queenDownLeft(x1, x2, y1, y2, board);

            } else if (y2 < y1 && x2 > x1) {
               Moves::queenDownRight(x1, x2, y1, y2, board);
            }

            return true;
        }
    }
    return false;
}