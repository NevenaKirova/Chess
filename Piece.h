//
// Created by Nevena Kirova on 6/10/18.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
using namespace std;

enum Player{
    WHITE,
    BLACK
};

class Piece {

private:

    string type;
    string description;
    Player team;

public:

    Piece();
    Piece(string type,Player team);
    string getType();
    Player getTeam();
    string getDescription();

};


#endif //CHESS_PIECE_H
