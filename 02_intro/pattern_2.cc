// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1
2 3
4 5 6
*/

int main() {
    int nLines;
    cin >> nLines;

    int val = 1;
    for (int curRow = 1; curRow <= nLines; ++curRow) {
        for (int ithVal = 1; ithVal <= curRow; ++ithVal) {
            cout << val << " ";
            ++val;
        }
        cout << endl;
    }

}