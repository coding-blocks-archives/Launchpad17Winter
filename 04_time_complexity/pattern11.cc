// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printStars(int n){
    for(int i = 0; i < n; ++i){
        cout << "*";
    }
}

void pattern(int nLines){
    for(int curRow = 1; curRow <= nLines; ++curRow){
        printStars(curRow);
        cout << " ";
        printStars(nLines - curRow + 1);
        cout << " ";
        printStars(nLines - curRow + 1);
        cout << " ";
        printStars(curRow);
        cout << " ";
        cout << endl;
    }
}


int main(){
    int n;
    cin >> n;
    pattern(n);      
}

/*
*_***_***_*
**_**_**_**
***_*_*_***
*/