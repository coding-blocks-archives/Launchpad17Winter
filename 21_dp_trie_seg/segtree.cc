#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
const int D = 100;
void inputVec(vi&v)     {for (auto&i : v)cin >> i;}
void printVec(vi&v)     {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         { return 2 * i;}
int right(int i)        { return 2 * i + 1; }
int mid(int a, int b)   { return (a + b) / 2;}
/********************************/
vi t, v;

void build(int root, int be, int en) {
    if (be > en) {
        return;
    }

    if (be == en) {
        // array has only one element
        t[root] = v[be];
        return;
    }

    build(left(root), be, mid(be, en));
    build(right(root), mid(be, en)  + 1, en);
    t[root] = t[left(root)] + t[right(root)];
}

int query(int root, int be, int en, int i, int j) {
    if (be > en || en < i || j < be) {
        return 0;
    }

    if (i <= be && j >= en) {
        return t[root];
    }

    int q1 = query(left(root), be, mid(be, en), i, j);
    int q2 = query(right(root), mid(be, en) + 1, en, i, j);
    return q1 + q2;
}


int main() {
    int n,q;
    cin >> n >> q;
    t.resize(4 * n);
    v.resize(n);
    inputVec(v);
    build(1, 0, n - 1); 

    for (int k = 0; k < q; ++k) {
        int i, j;
        cin >> i >> j;
        cout << query(1, 0, n - 1, i, j);
    }
}