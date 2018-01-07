// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntUptoDollar() {
    char c;
    int cnt = 0;
    // cin >> c;
    // c = cin.get();
    cin.get(c);

    while (c != '$') {
        ++cnt;
        cin.get(c);
        // cin >> c;
    }
    return cnt;
}


int main() {
    int ans = cntUptoDollar();
    cout << ans;
}