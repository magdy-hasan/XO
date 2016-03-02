#include <stdio.h>
#include<Board.h>
using namespace std;

void play(){
    // create the game board
    Board gameBoard;
    gameBoard.initialize();

    int curPlayer = 0; // first player
    int _x = 0, _o = 0; // number of x's and o's
    bool p1win = 0, p2win = 0; // keep track whether player 1, player 2 win

    while(1){
        if(gameBoard.readMove(gameBoard,curPlayer) == false) // read player move
            continue; // if not a valid move ask him to enter again

        // increase number of which one we put
        _x += (curPlayer == 0); // if player 0 plays increase number of X's
        _o += (curPlayer == 1); // if player 1 plays increase number of O's

        // make curPlayer the next player
        curPlayer = (curPlayer+1)%2;

        // check win
        p1win = gameBoard.checkWin('X');
        p2win = gameBoard.checkWin('O');


        if(p1win){ // if Player 1 wins
            gameBoard.print();
            puts("\t\tPlayer 1 win \n\n");
            return;
        }else if(p2win){ // if player 2 wins
            gameBoard.print();
            puts("\t\tPlayer 2 win \n\n");
            return;
        }else if(_x+_o == 9){ // if draw ( all board is full )
            gameBoard.print();
            puts("\t\tDraw\n\n");
            return;
        }
    }
}

int main(){
    while(1){
        puts("\n\n\t\t     Tic Tac Toe\n");
        puts("Enter Number 1 for 2 Player Game:");

        int choice;
        scanf("%d",&choice);
        if(choice == 1){
            play();
            puts("Enter 1 to play again Or 2 to exit:");
            scanf("%d",&choice);
            if(choice == 1)
                continue;
            else
                break;
        }// To-DO other choices
    }
    puts("Good Bye");
}
