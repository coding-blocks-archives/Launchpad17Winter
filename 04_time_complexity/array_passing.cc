// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void foo(int y){
    y = y + 1;
}

// void foo(int arr[]){
//     cout << endl;
//     cout << "Calling foo" << endl;
//     arr[0] = 2;

// }


int main(){
    int x = 2;
    foo(2);
    cout << x;

    // int arr[3] = {1,2,3};
    // cout << arr[0] << " ";
    // foo(arr);
    // cout << arr[0] << " ";

    
}