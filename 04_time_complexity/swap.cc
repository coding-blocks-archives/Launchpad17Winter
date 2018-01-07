// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void swapFunc(int& a, int& b){
    // changes should be reflected
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int x = 2;
    int y = 3;
    // swapFunc(2, 3);
    swapFunc(x, y);
    cout << x << y; // 32
}