// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int x;                  // var declaration
    x = 0;                  // assignment
    0 = x;                  // Wrong
    cout << x << endl;      // garbage val

    int y;                  // variable declaration

    // input into x , y
    // cout << "please enter a no ";
    cin >> x;

    // cout << "please enter a no ";
    cin >> y;

    int a = 0;  // initialisation. Declaration + assignment

    int z = x + y;

    cout << z;   
}