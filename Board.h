#define BOARD_H


class Board
{
    public:
        char _board[9];
        void initialize();
        bool readMove(Board &cur_board,int curPlayer);
        bool place(int idx,int player);
        bool checkWin(char ch);
        void print();
};

