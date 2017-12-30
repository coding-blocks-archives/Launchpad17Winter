// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int curNum = 1;
    while (curNum <= n) {
        cout << curNum << " ";
        curNum = curNum + 1;
        // ++curNum; curNum++;
    }
}