//
// Created by Nevena Kirova on 6/10/18.
//

#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Board.h"

Game::Game() {
    this->board = new Board();

}

void Game::printBoard() {
    for (int i = 7; i >= 0; i--) {
        cout << endl << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            cout << " " << this->board->getPosition(i, j)->getDescription() << " ";
        }
    }
    cout << "\n   A  B  C  D  E  F  G  H \n\n";


}

void Game::printMenu() {
    cout<<"Commands: (S)ave, (L)oad, (Q)uit \n ";
}

int Game::letterToCoord(char letter) {
    return (letter-97);
}


bool Game::checkMove(int x1, int y1,int x2, int y2,Player player) {
    if (Pawn::isPawn(x1, y1, x2, y2, player, board))return true;

    if (Rook::isRook(x1, y1, x2, y2, board)) return true;

    if (Knight::isKnight(x1, y1, x2, y2, board)) return true;

    if (Bishop::isBishop(x1, y1, x2, y2, board)) return true;

    if (King::isKing(x1, y1, x2, y2, board)) return true;

    return Queen::isQueen(x1, y1, x2, y2, board);

}

void Game::movePiece(int x1, int y1, int x2, int y2,Player player) {
    if (board->getPosition(y2, x2)->getType() == "King") {
        cout << "End of game";
        exit(1);
    }
    board->setPosition(board->getPosition(y1, x1), y2, x2);
    board->setPosition(new Piece(), y1, x1);
}


void Game::save(){
    ofstream outputFile;
    outputFile.open("game.txt",ios::out);
    if(outputFile.is_open()){
        for (int i=7;i>=0;i--){

            for(int j=0;j<8;j++){
                outputFile << this->board->getPosition(i, j)->getDescription() << " ";

            }
            outputFile<<endl;
        }
    }
    outputFile.close();
}

void Game::load(){
    Piece pieces[13] = {
            Piece(),
            Piece("Pawn", WHITE),
            Piece("King", WHITE),
            Piece("Queen", WHITE),
            Piece("Bishop", WHITE),
            Piece("Rook", WHITE),
            Piece("Knight", WHITE),
            Piece("Pawn", BLACK),
            Piece("King", BLACK),
            Piece("Queen", BLACK),
            Piece("Bishop", BLACK),
            Piece("Rook", BLACK),
            Piece("Knight", BLACK)
    };


    ifstream inputFile;
    inputFile.open("game.txt",ios::in);
    if (inputFile.is_open()) {

        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                string put;
                inputFile >> put;
                for (int z = 0; z < 13; z++) {

                    if (pieces[z].getDescription() == put) {
                        if(put == "0")
                            board->setPosition(new Piece(), i, j);
                        else
                            board->setPosition(new Piece(pieces[z].getType(), pieces[z].getTeam()), i, j);
                    }
                }
            }
        }
    }
    inputFile.close();
}
