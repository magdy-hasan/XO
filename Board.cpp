#include "Board.h"
#include<stdio.h>
using namespace std;

void Board::initialize(){
    for(int i=0;i<9;i++)
        _board[i] = '0'+i+1;
}

bool Board::readMove(Board &cur_board,int curPlayer){
    puts("\n\n\n\n");
    puts("\t     Player 1<X> - Player 2<O>\n\n");

    // print current board
    cur_board.print();
    printf("\t\tPlayer %d ('%c') Turn\n",curPlayer+1,curPlayer == 0 ? 'X':'O');
    printf("Please Enter a valid number on the board:");

    // where to play
    int pos;
    scanf("%d",&pos);
    if(cur_board.place(pos-1,curPlayer) == false)
        return 0; // if not a valid position
    return 1;
}

bool Board::place(int idx,int player){
    if(_board[idx] == '0'+idx+1){
        if(player == 0)
            _board[idx] = 'X';
        else
            _board[idx] = 'O';
        return 1;
    }else{ // if we in already visited cell
        puts("invalid move, try again\n");
        return 0;
    }
}

bool Board::checkWin(char ch){
    // check first diagonal
    if( (_board[0] == ch && _board[4] == ch && _board[8] == ch))
        return 1;
    // check first diagonal
    if(_board[2] == ch && _board[4] == ch && _board[6] == ch)
        return 1;
    // check rows and columns
    for(int i=0;i<3;i++)
        if(_board[i] == ch && _board[i+3] == ch && _board[i+6] == ch) // check column
           return 1;
        else if( (_board[i*3] == ch && _board[i*3+1] == ch && _board[i*3+2] == ch) )// check row
            return 1;

    return 0;
}

void Board::print(){
    puts("\t\t     |     |     ");

    printf("\t\t  %c  |  %c  |  %c  \n",_board[0],_board[1],_board[2]);
    puts("\t\t_____|_____|_____");
    puts("\t\t     |     |     ");

    printf("\t\t  %c  |  %c  |  %c  \n",_board[3],_board[4],_board[5]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c  \n",_board[6],_board[7],_board[8]);
    puts("\t\t     |     |     \n");
}
