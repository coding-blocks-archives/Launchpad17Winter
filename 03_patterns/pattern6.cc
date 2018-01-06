// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int nLines;
    cin >> nLines;

    for(int curRow = 1; curRow <= nLines; ++curRow){
        char val = 'A';
        for(int i = 0; i < curRow; ++i){
            cout << (char)(val + i) << " ";
        }
        cout << endl;
    }   
}