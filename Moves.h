//
// Created by Nevena Kirova on 5.05.20.
//

#ifndef CHESS_MOVES_H
#define CHESS_MOVES_H

#include "Board.h"


class Moves {
public:

     static bool queenGoesUp(int x1, int y1, int y2, Board *board);
     static bool queenGoesDown(int x1, int y1, int y2, Board *board);
     static bool queenGoesRight(int x1, int y1, int y2, Board *board);
     static bool queenGoesLeft(int x1, int x2, int y1, Board *board);
     static bool queenUpRight(int x1, int x2, int y1, int y2, Board *board);
     static bool queenUpLeft(int x1, int x2, int y1, int y2, Board *board);
     static bool queenDownLeft(int x1, int x2, int y1, int y2, Board *board);
     static bool queenDownRight(int x1, int x2, int y1, int y2, Board *board);
     static bool bishopUpRight(int x1, int x2, int y1, int y2, Board *board);
     static bool bishopUpLeft(int x1, int x2, int y1, int y2, Board *board);
     static bool bishopDownRight(int x1, int x2, int y1, int y2, Board *board);
     static bool bishopDownLeft(int x1, int x2, int y1, int y2, Board *board);
     static bool rookGoesUp(int x1, int y1, int y2, Board* board);
     static bool rookGoesDown(int x1, int y1, int y2, Board* board);
     static bool rookGoesLeft(int x1, int x2, int y1, Board* board);
     static bool rookGoesRight(int x1, int x2, int y1a, Board* board);


};




#endif //CHESS_MOVES_H
