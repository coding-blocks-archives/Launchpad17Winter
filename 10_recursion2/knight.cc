// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
const int DIM = 8;

bool canPlace(int board[][DIM], int x, int y){
    if (x == 0 && y == 0) return false;
    return (x >= 0 && x < DIM &&
            y >= 0 && y < DIM &&
            board[x][y] == 0);
}


bool knightSolver(int board[][DIM], int x, int y, int move_no) {
    if (move_no == 64) {
        return true;
    }

    int rowDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};
    int colDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};

    for(int dir = 0; dir < 8; ++dir){
        int nextX = x + rowDir[dir];
        int nextY = y + colDir[dir];
        if (canPlace(board, nextX, nextY)){
            board[nextX][nextY] = move_no;
            bool success = knightSolver(board, nextX, nextY, move_no + 1);
            if (success) return true;
            board[nextX][nextY] = 0;   
        }
    }
    return false;
}

void printBoard(int board[][DIM]){
    for(int i = 0; i < DIM; ++i){
        for (int j = 0; j < DIM; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[DIM][DIM] = {};

    bool isSuccessful = knightSolver(board, 0, 0, 1);
    if (isSuccessful) {
        // print board
        printBoard(board);
    }
    else {
        cout << "Hey Man!! This board cannot be visited by a knight";
    }
}