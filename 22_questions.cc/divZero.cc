// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double divide(int x, int y) {
    if (y == 0) {
        throw;// "Zero Division Error";
    }
    return x / y;
}

int main() {
    try {
        double ans = divide(1, 0);
        cout << ans;
    }
    catch(){

        // cout << e;
        // cout << "Man! Zero division error";
        // ans = 1;
    }
}