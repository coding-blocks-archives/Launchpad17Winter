// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int squareRoot(int n) {
    int root = 0;

    while (root * root <= n) {
        ++root;
    }
    return root - 1 ;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        int diff = c - 'A';
        char lower_equiv = 'a' + diff;
        return lower_equiv;
    }

    return c;
}


int main() {
    // int n;
    // cin >> n;
    // int root = squareRoot(n);
    // cout << root;

    char c; cin >> c;
    cout << toLower(c);
}