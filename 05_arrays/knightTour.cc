// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <bitset>
using namespace std;

const int DIM = 8;
int mat[DIM][DIM];
bitset<DIM * DIM> toVisit;    // available cells to visit
int curMove = 0;

void printMat() {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int m = 0;
bool knightTour(int r, int c, int m) {
    // if nothing to visit
    // if (toVisit.none()) {
    //     return true;
    // }
    // cout << m << " ";
    if (m >= 63) return true;

    // try all the eight directions
    static int rowDir[] = { -1, -2, -2, -1, +1, +2, +2, +1};
    static int colDir[] = { -2, -1, +1, +2, +2, +1, -1, -2};

    // check all possibilities
    for (int i = 0; i < 8; ++i) {
        int nextR = r + rowDir[i];
        int nextC = c + colDir[i];
        int idx = DIM * nextR + nextC;

        if (nextR >= 0 && nextR < DIM && 
            nextC >= 0 && nextC < DIM && 
            mat[nextR][nextC] == -1
        ) {
            ++m;
            mat[nextR][nextC] = m;
            // toVisit[idx] = 0;
            // printMat();
            bool success = knightTour(nextR, nextC, m + 1);
            if (success) return true;
            
            // --m;
            toVisit[idx] = 1;
            mat[nextR][nextC] = -1;
        }
    }
    return false;
}



int main() {
    memset(mat, -1, sizeof mat);
    // printMat();
    toVisit.set();
    toVisit[0] = 0;
    mat[0][0] = 0;
    bool ans = knightTour(0, 0, 1);
    cout << ans << endl;
    if (ans) {
        printMat();
    }

}