// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printN(int arr[], int n){
    for(int i = 0; i < n; ++i){
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

}

int main(){
    int arr[10];
    int n;
    cin >> n;

    printN(arr, n);       
}