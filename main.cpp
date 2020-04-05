#include <iostream>
#include "Game.h"
using namespace std;


int main() {

    Game board=Game();


    Player player=WHITE;
    char coordinate;
    int x1,x2,y1,y2;

    while(true){
        board.printMenu();
        board.printBoard();

        if (player==WHITE) cout<<"White move"<<endl;
        else if (player==BLACK) cout<<"Black move"<<endl;

        cin >> coordinate;
        if(coordinate == 'Q') {
            cout << "End of game";
            break;
        }
        if(coordinate == 'S') {
            board.save();
            continue;
        }
        if(coordinate == 'L') {
            board.load();
            continue;
        }
        cin>> y1;
        x1 = board.letterToCoord(coordinate);
        y1 = y1 - 1;

        cin >> coordinate >> y2;
        x2 = board.letterToCoord(coordinate);
        y2 = y2-1;

        if (!board.checkMove(x1, y1, x2, y2, player)) {
            cout<< "Incorrect move"<<endl;
            continue;
        } else {
            cout<<"";
        }
        board.movePiece(x1,y1,x2,y2,player);
        if(player == WHITE)player = BLACK;
        else player = WHITE;
    }



    return 0;
}