// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int revNum(int n){
    int ans = 0;
    // int quotient = n;

    while(n != 0){
        int lastDig = n % 10;
        ans = ans * 10 + lastDig;
        n = n / 10;
    }
    return ans;
}


int main(){
    int num;
    cin >> num;

    int ans = revNum(num);
    cout << ans;   
}