// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printOdd(int n){
    for(int i = 1; i <= n; i = i + 2){
        cout << i << " ";
    }
}

int main(){
    int n;
    cin >> n;
    printOdd(n);    
}