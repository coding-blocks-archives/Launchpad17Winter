// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int curNum;
    int ithNum = 0;
    int sum = 0;
    while(ithNum < n){
        cin >> curNum;
        sum = sum + curNum;
        ++ithNum;
    }

    cout << sum;

}