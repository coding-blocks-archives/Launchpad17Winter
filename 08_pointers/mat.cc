// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int foo(int arr[][4]){

}

int main() {
    int mat[4][4] = {
        {1, 2, 3, 4 },
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // cout << mat[0][0] << endl;
    // cout << &mat[0][0] + 1 << endl;
    // cout << mat[0]  + 1<< endl;
    // cout << &mat[0] + 1<< endl;

    // int* p = mat[0];        // pointer to an integer/cell
    
    int (*p1)[4] = &mat[0];  // pointer to an array
    cout << *p1 << endl;
    cout << *(*p1) ;

    int* p[3];              // array of pointers
    
    
    // foo(mat);
}