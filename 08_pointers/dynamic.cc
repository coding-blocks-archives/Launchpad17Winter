// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int* foo(){
    // int x = 10;
    // return &x;

    int* p = new int;
    *p = 1000;
    return p;
}

int main(){ 
    // int* p = NULL;
    // p = foo();
    // cout << *p << endl;
    // delete p;

    int n;
    cin >> n;
    int* p = new int[n];

    // p[1]..p[1]
    // delete [] p;
} 