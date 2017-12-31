// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int divisor = 2;
    bool isPrime = true;

    while (divisor < n ) {
        if (n % divisor == 0) {
            // num is no more prime
            isPrime = false;
            break;
        }
        ++divisor;
    }

    if (isPrime == true) {
        cout << "prime";
    } else {
        cout << "not prime";
    }

}