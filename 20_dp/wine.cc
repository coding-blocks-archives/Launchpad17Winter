#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
const int D = 100;
void inputVec(vi&v) {for (auto&i : v)cin >> i;}
void printVec(vi&v) {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
/********************************/

int memo[D][D];

int maxPrice(vi bottles, int be, int en, int year) {
    if (be > en) {
        // no bottles on the table
        return 0;
    }

    if (memo[be][en] != -1) {
        return memo[be][en];
    }

    int soldFromBegin = year * bottles[be] + maxPrice(bottles, be + 1, en, year + 1);
    int soldFromEnd = year * bottles[en] + maxPrice(bottles, be, en - 1, year + 1);

    return memo[be][en] = max(soldFromBegin, soldFromEnd);
}

int maxPrice(vi bottles) {
    int dp[D][D] = {};
    int n = bottles.size();

    for (int len = 1; len <= n; ++len) {
        int yr = n - len + 1;
        int srt = 0;
        int end = n - len;
        int en = srt + len - 1;
        while(srt <= end){
            dp[srt][en] = max(
                yr * bottles[srt] + dp[srt + 1][en],
                yr * bottles[en] + dp[srt][en - 1]
                );
            ++srt;
            ++en;
        }
    }
    return dp[0][n - 1];
}


int main() {
    int n;
    cin >> n;
    vi bottles(n);
    inputVec(bottles);
    memset(memo, -1, sizeof memo);
    // int ans = maxPrice(bottles, 0, n - 1, 1);
    int ans = maxPrice(bottles);
    cout << ans;
}