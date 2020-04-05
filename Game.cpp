//
// Created by Nevena Kirova on 6/10/18.
//

#include "Game.h"

using namespace std;

Game::Game() {

    Piece whiteKing=Piece("King",WHITE);
    Piece whiteQueen=Piece("Queen",WHITE);
    Piece whiteRook=Piece("Rook",WHITE);
    Piece whiteBishop=Piece("Bishop",WHITE);
    Piece whiteKnight=Piece("Knight",WHITE);
    Piece whitePawn=Piece("Pawn",WHITE);

    Piece blackKing=Piece("King",BLACK);
    Piece blackQueen=Piece("Queen",BLACK);
    Piece blackRook=Piece("Rook",BLACK);
    Piece blackBishop=Piece("Bishop",BLACK);
    Piece blackKnight=Piece("Knight",BLACK);
    Piece blackPawn=Piece("Pawn",BLACK);

    board[0][4]=whiteKing;
    board[0][3]=whiteQueen;
    board[0][0]=whiteRook;
    board[0][7]=whiteRook;
    board[0][2]=whiteBishop;
    board[0][5]=whiteBishop;
    board[0][1]=whiteKnight;
    board[0][6]=whiteKnight;

    board[7][4]=blackKing;
    board[7][3]=blackQueen;
    board[7][0]=blackRook;
    board[7][7]=blackRook;
    board[7][2]=blackBishop;
    board[7][5]=blackBishop;
    board[7][1]=blackKnight;
    board[7][6]=blackKnight;

    for (int i=0; i<8;i++){
        board[1][i]=whitePawn;
        board[6][i]=blackPawn;
    }

}

void Game::printBoard() {
    for (int i=7;i>=0;i--){
        cout<<endl<<i+1<<" ";
        for(int j=0;j<8;j++){
            cout<<" "<<board[i][j].getDescription()<<" ";
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

    if(board[y1][x1].getType()=="Pawn") {
        if (x1 == x2 && board[y2][x2].getDescription()== "0") { // Move forward
            if (player == board[y1][x1].getTeam() && player == WHITE) { // White
                if ((y2 - y1) == 1) return true;
                return (y2 - y1) == 2 && y1 == 1 && board[2][x1].getDescription() == "0";
            } else { // Black
                if ((y1 - y2) == 1) return true;
                return (y1 - y2) == 2 && y1 == 6 && board[5][x1].getDescription() == "0";
            }
        } else if (abs(x1 - x2) == 1 && abs(y1 - y2) == 1 && board[y2][x2].getDescription() != "0") { // Attack
            if (player == WHITE) {
                return y2 > y1 && board[y2][x2].getTeam() == BLACK;
            } else {
                return y2 < y1 && board[y2][x2].getTeam() == WHITE;
            }
        } else {
            return false;
        }
    }

    if(board[y1][x1].getType()=="Rook") {
        if (x1 == x2) { // Vertical move
            if (y2 > y1) { // Goes up
                for (int i = y1 + 1; i < y2; i++) {
                    if (board[i][x1].getDescription() != "0") return false;
                }
                return true;
            } else { // Goes down
                for (int i = y1 - 1; i > y2; i--) {
                    if (board[i][x1].getDescription() != "0") return false;
                }
                return true;
            }
        } else if (y1 == y2) { // Horizontal move
            if (x2 > x1) { // Goes right
                for (int i = x1 + 1; i < x2; i++) {
                    if (board[y1][i].getDescription() != "0") return false;
                }
                return true;
            } else {
                for (int i = x1 - 1; i > x2; i--) { // Goes left
                    if (board[y1][i].getDescription() != "0") return false;
                }
                return true;
            }
        }
        else {
            return false;
        }
    }

    if(board[y1][x1].getType()== "Knight") {
        return (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2);
    }

    if(board[y1][x1].getType()== "Bishop") {
        if (abs(y2 - y1) != abs(x2 - x1)) return false;
        if (y2 > y1 && x2 > x1) { // Up right
            int i = y1 + 1, j = x1 + 1;
            while (i < y2 && j < x2) {
                if (board[i][j].getDescription() != "0") return false;
                i++;
                j++;
            }
        } else if (y2 > y1 && x2 < x1) { // Up left
            int i = y1 + 1, j = x1 - 1;
            while (i < y2 && j > x2) {
                if (board[i][j].getDescription() != "0") return false;
                i++;
                j--;
            }
        } else if (y2 < y1 && x2 < x1) { // Down left
            int i = y1 - 1, j = x1 - 1;
            while (i > y2 && j > x2) {
                if (board[i][j].getDescription() !="0") return false;
                i--;
                j--;
            }
        } else if (y2 < y1 && x2 > x1) { // Down right
            int i = y1 - 1, j = x1 + 1;
            while (i > y2 && j < x2) {
                if (board[i][j].getDescription() != "0") return false;
                i--;
                j++;
            }
        }
        return true;
    }

    if(board[y1][x1].getType()== "King") {
        return (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1) ||
               (abs(x1 - x2) == 1 && abs(y1 - y2) == 1);
    }

    if(board[y1][x1].getType()== "Queen") {
        if (x1 == x2) { // Vertical move
            if (y2 > y1) { // Goes up
                for (int i = y1 + 1; i < y2; i++) {
                    if (board[i][x1].getDescription() != "0") return false;
                }
                return true;
            } else { // Goes down
                for (int i = y1 - 1; i > y2; i--) {
                    if (board[i][x1].getDescription() != "0") return false;
                }
                return true;
            }
        } else if (y1 == y2) { // Horizontal move
            if (x2 > x1) { // Goes right
                for (int i = x1 + 1; i < x2; i++) {
                    if (board[y1][i].getDescription() !="0") return false;
                }
                return true;
            } else {
                for (int i = x1 - 1; i > x2; i--) { // Goes left
                    if (board[y1][i].getDescription() != "0") return false;
                }
                return true;
            }
        } else {
            if (abs(y2 - y1) != abs(x2 - x1)) return false;
            if (y2 > y1 && x2 > x1) { // Up right
                int i = y1 + 1, j = x1 + 1;
                while (i < y2 && j < x2) {
                    if (board[i][j].getDescription() != "0") return false;
                    i++; j++;
                }
            } else if (y2 > y1 && x2 < x1) { // Up left
                int i = y1 + 1, j = x1 - 1;
                while (i < y2 && j > x2) {
                    if (board[i][j].getDescription() != "0") return false;
                    i++; j--;
                }
            } else if (y2 < y1 && x2 < x1) { // Down left
                int i = y1 - 1, j = x1 - 1;
                while (i > y2 && j > x2) {
                    if (board[i][j].getDescription() != "0") return false;
                    i--; j--;
                }
            } else if (y2 < y1 && x2 > x1) { // Down right
                int i = y1 - 1, j = x1 + 1;
                while (i > y2 && j < x2) {
                    if (board[i][j].getDescription() != "0") return false;
                    i--; j++;
                }
            }
            return true;
        }

    }
    return false;
}

void Game::movePiece(int x1, int y1, int x2, int y2,Player player) {
    if(board[y2][x2].getType()=="King"){
        cout<<"End of game";
        exit(1);
    }
    board[y2][x2] = board[y1][x1];
    board[y1][x1] = Piece();

}


void Game::save(){
    ofstream outputFile;
    outputFile.open("game.txt",ios::out);
    if(outputFile.is_open()){
        for (int i=7;i>=0;i--){

            for(int j=0;j<8;j++){
                outputFile<<this->board[i][j].getDescription()<<" ";

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
                            board[i][j] = Piece();
                        else
                            board[i][j] = Piece(pieces[z].getType(), pieces[z].getTeam());
                    }
                }
            }
        }
    }
    inputFile.close();
}
