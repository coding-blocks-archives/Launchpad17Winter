// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    /*int i = 0;
    while (i < 10){
        // do something
        // ....
        // ....
        ++i;
    }


    for(int i = 0; i < 10; ++i){

    }*/


    int n;
    cin >> n;

    for (int curNum = 2; curNum <= n; ++curNum) {
        int div = 2;
        bool isPrime = true;
        while (div < curNum) {
            if (curNum % div == 0) {
                isPrime = false;
                break;
            }
            ++div;
        }
        
        if (isPrime == true) {
            cout << curNum << " ";
        }
    }
}