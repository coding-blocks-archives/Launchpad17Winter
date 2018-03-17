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


int numWays(string& exp, int be, int en, string& op, int i, int j, bool req) {
    if (be > en) {
        // operands does not exist
        return 0;
    }

    if (be == en) {
        // just one opearnd
        if (req) return exp[be] == 'T';
        if (!req) return exp[be] == 'F';
    }

    int ans = 0;
    for (int k = i; k <= j; ++k) {
        char curOp = op[k];
        switch (curOp) {
        case '^':
            ans +=
                numWays(exp, be, k, op, i, k - 1, false) *
                numWays(exp, k + 1, en, op, k + 1, j, true);
            ans +=
                numWays(exp, be, k, op, i, k - 1, true) *
                numWays(exp, k + 1, en, op, k + 1, j, false);
            break;

        case '|':
            ans +=
                numWays(exp, be, k, op, i, k - 1, false) *
                numWays(exp, k + 1, en, op, k + 1, j, true);
            ans +=
                numWays(exp, be, k, op, i, k - 1, true) *
                numWays(exp, k + 1, en, op, k + 1, j, false);
            ans +=
                numWays(exp, be, k, op, i, k - 1, true) *
                numWays(exp, k + 1, en, op, k + 1, j, true);
            break;

        case '&':
            ans +=
                numWays(exp, be, k, op, i, k - 1, true) *
                numWays(exp, k + 1, en, op, k + 1, j, true);
            break;
        }
    }
    return ans;
}

int numWays(string& sym, string& op) {
    int n1 = sym.size();
    int n2 = op.size();

    int T[100][100] = {};
    int F[100][100] = {};
    // setting the base cases of 1 operand
    for (int i = 0; i < n1; ++i) {
        T[i][i] = sym[i] == 'T';
        F[i][i] = sym[i] == 'F';
    }

    for (int len = 2; len <= n1; ++len) {
        for (int j = 0; j <= n1 - len; ++j)
        {
            int srt = j;
            int end = srt + len - 1;
            int t = 0;
            int f = 0;
            for (int k = 1; k <= len - 1; ++k)
            {
                char opr = op[j + k - 1];
                switch (opr) {
                case '^':
                    t += T[srt][k + srt - 1] * F[k + srt][end] +
                         F[srt][k + srt - 1] * T[k + srt][end];
                    f += T[srt][k + srt - 1] * T[k + srt][end] +
                         F[srt][k + srt - 1] * F[k + srt][end];
                    break;
                case '&':
                    t += T[srt][k + srt - 1] * T[k + srt][end];
                    f += T[srt][k + srt - 1] * F[k + srt][end] +
                         F[srt][k + srt - 1] * T[k + srt][end] +
                         F[srt][k + srt - 1] * F[k + srt][end];
                    break;
                case '|':
                    t += T[srt][k + srt - 1] * F[k + srt][end] +
                         F[srt][k + srt - 1] * T[k + srt][end] +
                         T[srt][k + srt - 1] * T[k + srt][end];
                    f += F[srt][k + srt - 1] * F[k + srt][end];
                }
            }
            T[srt][end] = t;
            F[srt][end] = f;
        }
    }
    return T[0][n1 - 1];
}



int main() {
    string a, b;
    cin >> a >> b;
    // int ans = numWays(a, 0, a.size() - 1, b, 0, b.size() - 1, true);
    int ans = numWays(a, b);
    cout << ans;
}