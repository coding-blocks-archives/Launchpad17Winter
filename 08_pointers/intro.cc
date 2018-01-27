// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    // int x = 10;
    // int* ptr = &x;

    // ptr = 10;   // 10 is an integer
    // ptr = 0;
    // ptr = NULL;

    // cout << "&x " << &x << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;  

    // int* ptr = NULL;
    // cout << ptr; 
    // cout << *ptr;   // SEG Fault

    // int x = 10;
    // int* p = &x;
    // *p = 20;
    // cout << x << endl;

    // int arr[100];
    // int* p1 = &arr[0];
    // int* p2 = &arr[2];
    // cout << p2 - p1 << endl;

    // int x = 10;
    // int* p = &x;
    // cout << "&x " << &x << endl;
    // cout << "p  " << p << endl;
    // cout << "p+1 " << (void*)((char*)p + 1) << endl;

    // double x = 10;
    // double* p = &x;
    // cout << *((int*)p + 1) << endl;

    // pointers and functions
    // int x, y;
    // x = 2; y = 3;
    // mySwap(&x, &y);
    // cout << x << " " << y;
}