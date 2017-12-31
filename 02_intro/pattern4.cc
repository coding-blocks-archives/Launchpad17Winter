// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
    1
   232
  34543
 4567654
*/
int main() {
    int N;
    cin >> N;

    for (int curLine = 1 ; curLine <= N; ++curLine) {
        // spaces
        int nSpace = N - curLine;
        for (int i = 1; i <= nSpace; ++i) {
            cout << " ";
        }

        // inc order [curRow...2 * curRow - 1]
        int maxVal = 2 * curLine - 1;
        int curVal;
        for (curVal = curLine; curVal <= maxVal; ++curVal) {
            cout << curVal;
        }

        curVal = curVal - 2;
        // dec order [curVal...curRow]
        for(; curVal >= curLine; --curVal){
            cout << curVal;
        }
        cout << endl;
    }
}