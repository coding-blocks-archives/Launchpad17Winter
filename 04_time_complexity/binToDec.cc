// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int toBinary(int num){
    int ans = 0;
    int mul = 1;

    while(num > 0){
        int rem = num % 2;
        ans = ans + (rem * mul);
        mul = mul * 10;
        num = num / 2;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = toBinary(n);
    cout << ans;   
}