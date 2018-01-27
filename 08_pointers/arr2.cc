// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void foo(int arr[], int n){

}

int main() {
    // int arr[10] = {1, 2, 3 , 4, 5};

    // int* p = &arr[3];
    // cout << "arr " << arr << endl;
    // cout << "&arr[0] " << &arr[0] << endl;
    // cout << "p " << p << endl;

    // p = &arr[1];
    // arr = &arr[2];
    // cout << arr[-2] << endl; // 3rd ele of arr
    // cout << p[-2] << endl;
    // cout << *(p + 2) << endl;

    // cout << sizeof(arr) << endl;
    // cout << sizeof(p) << endl;

    // foo(p, 5);   // ptrs and arrays are related
    // decomposition

    char a[] = "apple";
    int i[] = {1,2, 3};
    char* c = a;
    cout << (int*)c << endl;
    cout << c << endl;
    cout << i << endl;



}