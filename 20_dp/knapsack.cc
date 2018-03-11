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

int knapsack(vi& p, vi& w, int k){

}


int main(){
    int n;
    cin >> n;
    vi price(n),wt(n);
    int w; cin >> w;
    int ans = knapsack(price, wt, k);
    cout << ans;
}

