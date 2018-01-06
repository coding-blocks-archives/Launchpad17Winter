// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1
01
101
0101
*/

int main() {
    int n;
    cin >> n;

    for (int curRow = 1; curRow <= n; ++curRow) {
        int startVal = curRow % 2;          // int startVal = (curRow % 2 == 1) ? 1 : 0;
        for (int i = 1; i <= curRow; ++i) {
            cout << startVal;
            startVal = 1 - startVal;
        }
        cout << endl;
    }

}