// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
5
54
543
5432
54321
*/
int main(){
    int nLines;
    cin >> nLines;

    for(int curRow = nLines; curRow > 0; --curRow){
        int minVal = curRow;
        for(int val = nLines; val >= minVal; --val){
            cout << val << " ";
        }
        cout << endl;
    }
}