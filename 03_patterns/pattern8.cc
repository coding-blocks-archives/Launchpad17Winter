// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
5
44
333
2222
11111
*/
int main() {
    int nLines;
    cin >> nLines;
    int val = nLines;

    for (int curRow = 1; curRow <= nLines; ++curRow) {
        for (int i = 1; i <= curRow; ++i) {
            cout << val;
        }
        --val;
        cout << endl;
    }
}