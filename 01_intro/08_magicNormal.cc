// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;

    if (y != 0) {
        int quotient = x / y;
        int remainder = x % y;
        
        if (quotient == remainder) {
            cout << "Magic Number";
        }
        
    } else {
        cout << "Normal Number";
    }
}