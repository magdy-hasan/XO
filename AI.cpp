#include "AI.h"
#include "Board.h"




pair<int,int> AI::get_move(Board &_cur_board,int cur_player,int alpha,int beta){
	bool X_win = _cur_board.checkWin('X');
	bool O_win = _cur_board.checkWin('O');

	if ((_AI_player == 0 && X_win) || (_AI_player == 1 && O_win)) // if AI win wheter he was the X OR O
		return{ 0, 10 };
	if (X_win || O_win) // if AI didn't win and there's a win then the human player win
		return{ 0, -10 };
	if (_cur_board.checkDraw()) // if there was a draw
		return { 0, 0 };

	pair<int, int> best_move = { -1, -(1 << 30) }; // the best move we can make from this position
	pair<int, int> worst_move = { -1, (1 << 30) }; // the worst move we can make from this positon

	for (int i = 0; i < 9;i++)
		if (_cur_board._board[i] == '0' + i){
			// suppose we made this move ( we mark it as we did it )
			_cur_board.place(i, cur_player);
			// get the new move 
			pair<int,int> new_move = get_move(_cur_board, (cur_player + 1) % 2,alpha,beta);
			// if the current player is the AI and we found a move with more value than our best move till now
			if (cur_player == _AI_player && new_move.value > best_move.value){
				best_move.value = new_move.value, best_move.position = i;
				alpha = max(alpha, best_move.value);
				// alpha-beta pruning
				if (beta <= alpha){
					_cur_board.place(i, -1);
					break;
				}
			}
			// if the current player is the human player and we found a move with less value than our worst move till now
			else if (cur_player != _AI_player && new_move.value < worst_move.value){
				worst_move.value = new_move.value, worst_move.position = i;
				beta = min(beta, worst_move.value);
				// alpha-beta pruning
				if (beta <= alpha){
					_cur_board.place(i, -1);
					break;
				}
			}
			// now unmark this position
			_cur_board.place(i, -1);
		}
	if (cur_player == _AI_player)
		return  best_move;
	else
		return worst_move;
}