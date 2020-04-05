//
// Created by Nevena Kirova on 6/10/18.
//

#include "Piece.h"

Piece::Piece() {
    description= "0";
    team = WHITE;
}

Piece::Piece(string type, Player team) {
    if (type == "King" && team == WHITE) {
        description = "♔";
    }
    if (type == "King" && team == BLACK) {
        description = "♚";
    }
    if (type == "Queen" && team == WHITE) {
        description = "♕";
    }
    if (type == "Queen" && team == BLACK) {
        description = "♛";
    }

    if (type == "Rook" && team == WHITE) {
        description = "♖";
    }
    if (type == "Rook" && team == BLACK) {
        description = "♜";
    }
    if (type == "Bishop" && team == WHITE) {
        description = "♗";
    }
    if (type == "Bishop" && team == BLACK) {
        description = "♝";
    }
    if (type == "Knight" && team == WHITE) {
        description = "♘";
    }
    if (type == "Knight" && team == BLACK) {
        description = "♞";
    }
    if (type == "Pawn" && team == WHITE) {
        description = "♙";
    }
    if (type == "Pawn" && team == BLACK) {
        description = "♟";
    }
    this->type=type;
    this->team = team;
}


string Piece::getType() {
    return type;
}

Player Piece::getTeam() {
    return team;
}

string Piece::getDescription() {
    return description;
}

