//
// Created by Nevena Kirova on 5.05.20.
//

#include "Moves.h"
bool Moves::queenGoesUp(int x1, int y1, int y2, Board *board) {
    for (int i = y1 + 1; i < y2; i++) {
        if (board->getPosition(i, x1)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::queenGoesDown(int x1, int y1, int y2, Board *board) {
    for (int i = y1 - 1; i > y2; i--) {
        if (board->getPosition(i, x1)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::queenGoesRight(int x1, int x2, int y1, Board *board) {
    for (int i = x1 + 1; i < x2; i++) {
        if (board->getPosition(y1, i)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::queenGoesLeft(int x1, int x2, int y1, Board *board) {
    for (int i = x1 - 1; i > x2; i--) { // Goes left
        if (board->getPosition(y1, i)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::queenUpRight(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 + 1, j = x1 + 1;
    while (i < y2 && j < x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i++;
        j++;
    }
    return false;
}

bool Moves::queenUpLeft(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 + 1, j = x1 - 1;
    while (i < y2 && j > x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i++;
        j--;
    }
    return false;
}

bool Moves::queenDownLeft(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 - 1, j = x1 - 1;
    while (i > y2 && j > x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i--;
        j--;
    }
    return false;
}

bool Moves::queenDownRight(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 - 1, j = x1 + 1;
    while (i > y2 && j < x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i--;
        j++;
    }
    return false;
}

bool Moves::bishopUpRight(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 + 1, j = x1 + 1;
    while (i < y2 && j < x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i++;
        j++;
    }
    return false;
}

bool Moves::bishopUpLeft(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 + 1, j = x1 - 1;
    while (i < y2 && j > x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i++;
        j--;
    }
    return false;
}

bool Moves::bishopDownRight(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 - 1, j = x1 + 1;
    while (i > y2 && j < x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i--;
        j++;
    }
    return false;
}

bool Moves::bishopDownLeft(int x1, int x2, int y1, int y2, Board *board) {
    int i = y1 - 1, j = x1 - 1;
    while (i > y2 && j > x2) {
        if (board->getPosition(i, j)->getDescription() != "0") return false;
        i--;
        j--;
    }
    return false;
}

bool Moves::rookGoesUp(int x1,int y1, int y2, Board *board) {
    for (int i = y1 + 1; i < y2; i++) {
        if (board->getPosition(i, x1)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::rookGoesDown(int x1, int y1, int y2, Board *board) {
    for (int i = y1 - 1; i > y2; i--) {
        if (board->getPosition(i, x1)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::rookGoesLeft(int x1, int x2, int y1, Board *board) {
    for (int i = x1 - 1; i > x2; i--) { //
        if (board->getPosition(y1, i)->getDescription() != "0") return false;
    }
    return false;
}

bool Moves::rookGoesRight(int x1, int x2, int y1, Board *board) {
    for (int i = x1 + 1; i < x2; i++) {
        if (board->getPosition(y1, i)->getDescription() != "0") return false;
    }
    return false;
}
