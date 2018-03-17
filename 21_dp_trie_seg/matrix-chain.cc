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

int matrixMul(vi& v) {
    int dp[100][100] = {};

    int n = v.size();

    for (int len = 2; len < n; ++len) {
        for (int j = 0; j < n - len; ++j)
        {
            int srt = j;
            int end = srt + len;
            dp[srt][end] = inf;
            for (int k = 1; k <= len - 1; ++k) {
                dp[srt][end] = min(dp[srt][end],
                                   dp[srt][srt + k] +
                                   dp[srt + k][end] +
                                   v[srt]*v[srt + k]*v[end]
                                  );
            }
        }
    }
    return dp[0][n-1];
}


int main() {
    int n; cin >> n;
    vi v(n);
    inputVec(v);
    printVec(v);
    int ans = matrixMul(v);
    cout << ans;
}