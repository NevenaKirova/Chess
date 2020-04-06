//
// Created by Nevena Kirova on 6.04.20.
//

#include "Bishop.h"

bool Bishop::isBishop(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Bishop") {
        if (abs(y2 - y1) != abs(x2 - x1)) return false;
        if (y2 > y1 && x2 > x1) { // Up right
            int i = y1 + 1, j = x1 + 1;
            while (i < y2 && j < x2) {
                if (board->getPosition(i, j)->getDescription() != "0") return false;
                i++;
                j++;
            }
        } else if (y2 > y1 && x2 < x1) { // Up left
            int i = y1 + 1, j = x1 - 1;
            while (i < y2 && j > x2) {
                if (board->getPosition(i, j)->getDescription() != "0") return false;
                i++;
                j--;
            }
        } else if (y2 < y1 && x2 < x1) { // Down left
            int i = y1 - 1, j = x1 - 1;
            while (i > y2 && j > x2) {
                if (board->getPosition(i, j)->getDescription() != "0") return false;
                i--;
                j--;
            }
        } else if (y2 < y1 && x2 > x1) { // Down right
            int i = y1 - 1, j = x1 + 1;
            while (i > y2 && j < x2) {
                if (board->getPosition(i, j)->getDescription() != "0") return false;
                i--;
                j++;
            }
        }
        return true;
    }
    return false;
}

