// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;

    int curNum = 2;
    while(curNum <= N){
        // check for primeness
        int divisor = 2;
        bool isPrime = true;
        while(divisor < curNum){
            if (curNum % divisor == 0){
                isPrime = false;
                break;
            }
            ++divisor;
        }
        // print if prime
        if (isPrime == true){
            cout << curNum << " ";
        }

        ++curNum;
    }   
}