#define BOARD_H


class Board
{
    public:
        char bo[9];
        void initialize();
        bool place(int idx,int player);
        bool checkWin(char ch);
        void print();
};

