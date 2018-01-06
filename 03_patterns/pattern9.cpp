// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
   *
  ***
 *****
  ***
   *
*/

int main(){
    int nLines;
    cin >> nLines;

    // Increasing Order Pattern
    int nRows = (nLines / 2) + 1;

    for(int curRow = 1; curRow <= nRows; ++curRow){
        // print spaces
        int nSpaces = nRows - curRow;
        for(int i = 0; i < nSpaces; ++i) {
            cout << " ";
        }

        // print stars
        int nStars = 2 * curRow - 1;
        for(int i = 0; i < nStars; ++i){
            cout << "*";
        }
        cout << endl;
    }

    // Decreasing Order
    nRows = nLines / 2;

    for(int curRow = 1; curRow <= nRows; ++curRow){
        // print spaces
        for(int i = 1; i <= curRow; ++i) {
            cout << " ";
        }

        // print stars
        int nStars = nLines - 2 * curRow;
        for(int i = 0; i < nStars; ++i){
            cout << "*";
        }
        cout << endl;
    }


}