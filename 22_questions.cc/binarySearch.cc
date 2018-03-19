// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cmath>
using namespace std;

double root1(int n) {
    // integer binary serach
    // 0.1, 0.01, 0.001. 0.0001
}

double root(int n) {
    const double eps = 1e-5;
    double ans = 0;
    double be = 0;
    double en = n;
    double step = 1;

    while (abs(ans * ans - n) > eps){
        double mid = 0;
        while (mid * mid < n) {
            mid = (be + en) / 2;
            if (mid * mid <= n) {
                be = mid + step;
            }
            else {
                en = mid - step;
            }
        }
        ans = mid - step;
        be = ans;
        en = ans + step;
        step = step / 10;
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    double ans = root(n);
    cout << ans;
}