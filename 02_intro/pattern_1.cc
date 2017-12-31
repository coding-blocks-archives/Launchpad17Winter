// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1
1 2
1 2 3
1 2 3 4
*/

int main(){
    int nLines;
    cin >> nLines;

    for(int curRow = 1; curRow <= nLines; ++curRow){
        // think about 1 line
        for(int curVal = 1; curVal <= curRow; ++curVal){
            cout << curVal << " ";
        }
        cout << endl;
    }
}