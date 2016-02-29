#include <stdio.h>
#include<Board.h>
using namespace std;

void play(){
    int curPlayer = 0;
    int pos;
    Board g;
    g.initialize();
    int _x = 0, _o = 0;
    bool p1win = 0, p2win = 0;
    while(1){
        puts("\n\n\n\n");
        puts("\t     Player 1<X> - Player 2<O>\n\n");
        // print current board
        g.print();
        printf("\t\tPlayer %d ('%c') Turn\n",curPlayer+1,curPlayer == 0 ? 'X':'O');
        printf("Please Enter a valid number on the board:");
        // where to play
        scanf("%d",&pos);
        if(g.place(pos-1,curPlayer) == false)
            continue;
        // increase number of which one we put
        _x += (curPlayer == 0);
        _o += (curPlayer == 1);
        curPlayer = (curPlayer+1)%2;
        // check win
        p1win = g.checkWin('X');
        p2win = g.checkWin('O');
        if(p1win){
            g.print();
            puts("\t\tPlayer 1 win \n\n");
            return;
        }else if(p2win){
            g.print();
            puts("\t\tPlayer 2 win \n\n");
            return;
        }else if(_x+_o == 9){
            g.print();
            puts("\t\tDraw\n\n");
            return;
        }
    }
}

int main(){
    while(1){
        puts("\n\n\t\t     Tic Tac Toe\n");
        int choice;
        puts("Enter Number 1 for 2 Player Game:");
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
