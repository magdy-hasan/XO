#pragma once
#include <utility>
#include <algorithm>

class Board;
using namespace std;
#define position first 
#define value second

class AI
{
public:
	int _AI_player;
	pair<int,int> get_move(Board &_cur_board,int cur_player,int alpha,int beta);
};

