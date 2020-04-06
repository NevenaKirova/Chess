//
// Created by Nevena Kirova on 6.04.20.
//

#include "Queen.h"

bool Queen::isQueen(int x1, int y1, int x2, int y2, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Queen") {
        if (x1 == x2) { // Vertical move
            if (y2 > y1) { // Goes up
                for (int i = y1 + 1; i < y2; i++) {
                    if (board->getPosition(i, x1)->getDescription() != "0") return false;
                }
                return true;
            } else { // Goes down
                for (int i = y1 - 1; i > y2; i--) {
                    if (board->getPosition(i, x1)->getDescription() != "0") return false;
                }
                return true;
            }
        } else if (y1 == y2) { // Horizontal move
            if (x2 > x1) { // Goes right
                for (int i = x1 + 1; i < x2; i++) {
                    if (board->getPosition(y1, i)->getDescription() != "0") return false;
                }
                return true;
            } else {
                for (int i = x1 - 1; i > x2; i--) { // Goes left
                    if (board->getPosition(y1, i)->getDescription() != "0") return false;
                }
                return true;
            }
        } else {
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
    }
    return false;
}