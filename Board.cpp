//
// Created by Nevena Kirova on 5.04.20.
//

#include "Board.h"

Board::Board() {

    Piece *whiteKing = new Piece("King", WHITE);
    Piece *whiteQueen = new Piece("Queen", WHITE);
    Piece *whiteRook = new Piece("Rook", WHITE);
    Piece *whiteBishop = new Piece("Bishop", WHITE);
    Piece *whiteKnight = new Piece("Knight", WHITE);
    Piece *whitePawn = new Piece("Pawn", WHITE);

    Piece *blackKing = new Piece("King", BLACK);
    Piece *blackQueen = new Piece("Queen", BLACK);
    Piece *blackRook = new Piece("Rook", BLACK);
    Piece *blackBishop = new Piece("Bishop", BLACK);
    Piece *blackKnight = new Piece("Knight", BLACK);
    Piece *blackPawn = new Piece("Pawn", BLACK);

    board[0][4] = whiteKing;
    board[0][3] = whiteQueen;
    board[0][0] = whiteRook;
    board[0][7] = whiteRook;
    board[0][2] = whiteBishop;
    board[0][5] = whiteBishop;
    board[0][1] = whiteKnight;
    board[0][6] = whiteKnight;

    board[7][4] = blackKing;
    board[7][3] = blackQueen;
    board[7][0] = blackRook;
    board[7][7] = blackRook;
    board[7][2] = blackBishop;
    board[7][5] = blackBishop;
    board[7][1] = blackKnight;
    board[7][6] = blackKnight;

    for (int i = 0; i < 8; i++) {
        board[1][i] = whitePawn;
        board[6][i] = blackPawn;
    }
    for (int i = 5; i >= 2; i--) {
        for (int u = 0; u <= 7; u++)
            board[i][u] = new Piece();
    }
}

Piece *Board::getPosition(int horizontal, int vertical) {
    return this->board[horizontal][vertical];
}

void Board::setPosition(Piece *piece, int horizontal, int vertical) {
    this->board[horizontal][vertical] = piece;
}