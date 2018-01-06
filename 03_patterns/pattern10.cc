// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int nLines;
    cin >> nLines;

    for(int curRow = 1; curRow <= nLines; ++curRow){
        int nVal = curRow;
        // A->E
        char val = 'A';
        
        for(int i = 1; i <= nVal; ++i){
            cout << val << " ";
            val++;
        }

        --val;

        // E->A
        for(int i = 1; i <= nVal; ++i){
            cout << val << " ";
            --val;
        }
        cout << endl;

    }   
}