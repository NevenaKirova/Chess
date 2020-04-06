//
// Created by Nevena Kirova on 6.04.20.
//

#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

bool Pawn::isPawn(int x1, int y1, int x2, int y2, Player player, Board *board) {
    if (board->getPosition(y1, x1)->getType() == "Pawn") {
        if (x1 == x2 && board->getPosition(y2, x2)->getDescription() == "0") { // Move forward
            if (player == board->getPosition(y1, x1)->getTeam() && player == WHITE) { // White
                if ((y2 - y1) == 1) return true;
                return (y2 - y1) == 2 && y1 == 1 && board->getPosition(2, x1)->getDescription() == "0";
            } else { // Black
                if ((y1 - y2) == 1) return true;
                return (y1 - y2) == 2 && y1 == 6 && board->getPosition(5, x1)->getDescription() == "0";
            }
        } else if (abs(x1 - x2) == 1 && abs(y1 - y2) == 1 &&
                   board->getPosition(y2, x2)->getDescription() != "0") { // Attack
            if (player == WHITE) {
                return y2 > y1 && board->getPosition(y2, x2)->getTeam() == BLACK;
            } else {
                return y2 < y1 && board->getPosition(y2, x2)->getTeam() == WHITE;
            }
        } else {
            return false;
        }
    }
    return false;
}
