#include <stdio.h>
#include "Board.h"
#include "AI.h"
using namespace std;

bool is_2_player_game;

void play(){
    // create the game board
    Board gameBoard;
    gameBoard.initialize();
	AI _AI;

	if (is_2_player_game == false){
		puts("\n\n\nEnter one of the following option\n");
		puts("\t1 - If you want to go first");
		puts("\t2 - If you want to go second");
		printf("Enter your option here: ");	
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
			_AI._AI_player = 1;
		else
			_AI._AI_player = 0;
	}
    int curPlayer = 0; // first player
    bool p1win = 0, p2win = 0 , draw = 0; // keep track whether player 1, player 2 win, draw

    while(1){
		gameBoard.get_move(is_2_player_game, _AI,curPlayer);
        // make curPlayer the next player
        curPlayer = (curPlayer+1)%2;

        // check win
        p1win = gameBoard.checkWin('X');
        p2win = gameBoard.checkWin('O');
		// check draw
		draw = gameBoard.checkDraw();


        if(p1win){ // if Player 1 wins
            gameBoard.print();
            puts("\t\tPlayer 1 win \n\n");
            return;
        }else if(p2win){ // if player 2 wins
            gameBoard.print();
            puts("\t\tPlayer 2 win \n\n");
            return;
        }else if(draw){ // if draw ( all board is full )
            gameBoard.print();
            puts("\t\tDraw\n\n");
            return;
        }
    }
}

int main(){
    while(1){
        puts("\n\n\t\t     Tic Tac Toe\n");
		puts("Enter one of the following option\n");
		puts("\t1 - Computer vs player");
		puts("\t2 - player vs player");
		puts("\t3 - Exit");
		printf("Enter your option here: ");
        int choice;
        scanf("%d",&choice);
        if(choice == 1){
			is_2_player_game = 0;
            play();
		}
		else if (choice == 2){
			is_2_player_game = 1;
			play();
		}
		else
			break;
    }
    puts("\n\n\t\tGood Bye");
}
