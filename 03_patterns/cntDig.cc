// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int num;
    cin >> num;

    int div = 10;
    int quotient = num / 10;
    int cnt = 1;

    while(quotient > 0){
        div = div * 10;
        ++cnt;
        quotient = num / div;
    }
    cout << cnt;

}