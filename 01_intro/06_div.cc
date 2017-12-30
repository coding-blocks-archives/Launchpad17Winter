// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int divisor;
    int dividend;
    cin >> dividend >> divisor;

    if (divisor != 0){
        int quotient = dividend / divisor;
        cout << quotient;
    } else {
        cout << "Sorry Man! Cant divide by Zero.\n";
    }
}