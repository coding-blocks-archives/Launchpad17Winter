// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x > y) {
        // either x or z can be largest
        if (x > z) {
            cout << x << endl;
        } else {
            cout << z << endl;
        }
    } else {
        // either y or z is largest
        if (y > z) {
            cout << y << endl;
        } else {
            cout << z << endl;
        }
    }
}