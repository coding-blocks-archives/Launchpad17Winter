// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int);     // function header/declaration

int factorial(int n) {  // function definiton
    int nFact = 1;
    for (int x = 1; x <= n; ++x) {
        nFact = nFact * x;
    }
    return nFact;
}

int main() {
    int n, r;
    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n - r);
    int ncr = nfact / rfact / nrfact;
}

