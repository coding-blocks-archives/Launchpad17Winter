// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
   1
  123
 12345
*/
int main(){
    int N;
    cin >> N;

    for(int curRow = 1; curRow <= N; ++curRow){
        // print spaces
        int nSpaces = N - curRow;
        for(int curSpace = 1; curSpace <= nSpaces; ++curSpace){
            cout << " ";
        }

        // print values
        int nValues = 2 * curRow - 1;
        for(int val = 1; val <= nValues; ++val){
            cout << val;
        }

        cout << endl
    }
}