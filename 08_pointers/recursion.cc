// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n){
    // function that gives factorial of n

    if (n <= 0){
        return 1;
    }

    int nMinus1 = fact(n - 1);
    int ans = n * nMinus1;
    return ans;
}

void printInc(int n){
    if (n <= 0){
        return;
    }

    printInc(n - 1);
    cout << " " << n;
}


int main(){
    int n;

    // cin >> n;
    // int ans = fact(n);
    // cout << ans << endl; 

    cin >> n; 
    printInc(n); 
}