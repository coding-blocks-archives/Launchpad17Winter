#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<bool> vb;
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

class UnweightedGraph {
public:
    vector<vector<int> > v;
    int nv;

    UnweightedGraph(int n) {
        nv = n;
        v.resize(n);
    }

    void addEdge(int src, int dest, bool bidirectional = true) {
        v[src].push_back(dest);
        if (bidirectional) v[dest].push_back(src);
    }
};

#include "shortestDist.h"
#include "topologicalSort.h"

int main() {
    int n = 6;
    UnweightedGraph g(n);

    // shortest dist
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(0, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(2, 3);

    // int src; cin >> src;
    // vi ans = shortestDist(g, src);
    // printVec(ans);

    // toposort
    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(3, 5, false);
    g.addEdge(2, 3, false);
    auto ans = topologicalSort(g);
    reverse(ans.begin(), ans.end());
    printVec(ans);
}