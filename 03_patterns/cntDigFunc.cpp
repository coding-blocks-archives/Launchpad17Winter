// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cmath>
using namespace std;

int cntDig(int num){
    int ans = log10(num) + 1;
    return ans;
}

int main(){
    int x;
    cin >> x;
    int nDigits = cntDig(x);
    cout << nDigits;

}