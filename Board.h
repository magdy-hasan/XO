#pragma once
#include "AI.h"
#include<stdio.h>
using namespace std;

class Board
{
    public:
        char _board[9];
        void initialize();

		void get_move(bool is_2_player_game,AI &_AI,int cur_player);
        bool readMove(int curPlayer);
        bool place(int idx,int player);

        bool checkWin(char ch);
		bool checkDraw();
        void print();
};

