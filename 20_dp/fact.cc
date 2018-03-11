#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<bool> vb;
void inputVec(vi& v){for(auto&i:v)cin>>i;}
void printVec(vector<int>& ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void printMat(vector<vector<int> > mat) {
    for (auto& v : mat) {
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}
/********************************/
int memo[100];
int fib(int n) {
    if (n == 0 || n == 1) return n;

    if (memo[n] != -1) {
        return memo[n];
    }

    int ans = fib(n - 2) + fib(n - 1);
    memo[n] = ans;
    return ans;
}

int fibBU(int n) {
    int dp[100];

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int reduceTo1(int n) {
    if (n < 1) return 1e6;
    if (n == 1) return 0;

    int n3 = inf, n2 = inf, n1 = inf;

    if (n % 3 == 0) {
        n3 = reduceTo1(n / 3);
    }
    if (n % 2 == 0) {
        n2 = reduceTo1(n / 2);
    }
    n1 = reduceTo1(n - 1);

    return min(n1, min(n2, n3)) + 1;
}

int reduceTo1BU(int n) {
    int dp[10000];

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; ++i) {
        int n1 = dp[i - 1];
        int n2 = i % 2 == 0 ? dp[i / 2] : inf;
        int n3 = i % 3 == 0 ? dp[i / 3] : inf;
        dp[i] = min(n1, min(n2, n3)) + 1;
    }

    int i = n;
    while (i != 1) {
        int n1 = dp[i - 1];
        int n2 = i % 2 == 0 ? dp[i / 2] : inf;
        int n3 = i % 3 == 0 ? dp[i / 3] : inf;
        
        if (n1 + 1 == dp[i]) {
            cout << i - 1 << " ";
            i = i - 1;
        }
        else if (n2 + 1 == dp[i]) {
            i = i / 2;
            cout << i << " ";
        }
        else {
            i = i / 3;
            cout << i << " ";
        }
    }
    return dp[n];
}

int change(int val, vi& coins){
    if (val == 0){
        return 0;
    }

    if (memo[val] != -1){
        return memo[val];
    }

    int ans = inf;
    for(int i = 0; i < coins.size(); ++i){
        int remVal = val - coins[i];
        if (remVal >= 0){
            int remChange = change(remVal, coins);
            ans = min(ans, remChange + 1);
        }
    }
    memo[val] = ans;
    return ans;
}

int changeBU(int val, vi& coins){
    vi dp(val + 1, inf);

    dp[1] = 1;
    for(int curVal = 2; curVal <= val; ++curVal){
        for(int i = 0; i < coins.size(); ++i){
            int curCoin = coins[i];
            if (curCoin <= curVal){
                dp[curVal] = min(dp[curVal], dp[curVal - curCoin] + 1);
            }
        }
    }
    return dp[val];
}

int main() {
    // int n;
    // cin >> n;

    // for (int i = 0; i <= n; ++i) {
    //     memo[i] = -1;
    // }

//     int ans = fib(n);
//     cout << ans;

    // int n; cin >> n;
    // int ans = reduceTo1BU(n);
    // cout << ans;

    int n; cin >> n;
    vi coins(n);
    inputVec(coins);
    int val; cin >> val;
    int ans = change(val, coins);
    cout << ans;
}