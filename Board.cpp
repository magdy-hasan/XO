#include "Board.h"
#include<stdio.h>
using namespace std;

void Board::initialize(){
    for(int i=0;i<9;i++)
        bo[i] = '0'+i+1;
}

bool Board::place(int idx,int player){
    if(bo[idx] == '0'+idx+1){
        if(player == 0)
            bo[idx] = 'X';
        else
            bo[idx] = 'O';
        return 1;
    }else{ // if we in already visited cell
        puts("invalid move, try again\n");
        return 0;
    }
}

bool Board::checkWin(char ch){
    // check 2 diagonals
    if( (bo[0] == ch && bo[4] == ch && bo[8] == ch) || (bo[2] == ch && bo[4] == ch && bo[6] == ch) )
        return 1;
    for(int i=0;i<3;i++)
        if( (bo[i] == ch && bo[i+3] == ch && bo[i+6] == ch) // check column
           || (bo[i*3] == ch && bo[i*3+1] == ch && bo[i*3+2] == ch) ) // check row
           return 1;
    return 0;
}

void Board::print(){
    puts("\t\t     |     |     ");

    printf("\t\t  %c  |  %c  |  %c  \n",bo[0],bo[1],bo[2]);
    puts("\t\t_____|_____|_____");
    puts("\t\t     |     |     ");

    printf("\t\t  %c  |  %c  |  %c  \n",bo[3],bo[4],bo[5]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c  \n",bo[6],bo[7],bo[8]);
    puts("\t\t     |     |     \n");
}
