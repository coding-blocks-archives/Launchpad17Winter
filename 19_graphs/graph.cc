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

struct Pair {
    int wt;
    int id;
    Pair() {}
    Pair(int i, int w) {
        id = i;
        wt = w;
    }
};

typedef vector<vector<Pair> > vvp;
typedef vector<Pair> vp;

class WeightedGraph {
public:
    vvp v;
    int nv;
    WeightedGraph(int n) {
        nv = n;
        v.resize(n);
    }

    int addEdge(int src, int dest, int wt, bool bidirectional = true) {
        v[src].push_back(Pair(dest, wt));
        if (bidirectional) {
            v[dest].push_back(Pair(src, wt));
        }
    }
};


#include "shortestDist.h"
#include "topologicalSort.h"
// #include "dijkstra.h"
#include "prim.cc"
int main() {
    // int n = 6;
    // UnweightedGraph g(n);

    // // shortest dist
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(0, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(2, 3);

    // int src; cin >> src;
    // vi ans = shortestDist(g, src);
    // printVec(ans);

    // // toposort
    // g.addEdge(0, 1, false);
    // g.addEdge(0, 2, false);
    // g.addEdge(1, 3, false);
    // g.addEdge(3, 4, false);
    // g.addEdge(3, 5, false);
    // g.addEdge(2, 3, false);
    // auto ans = topologicalSortBFS(g);
    // reverse(ans.begin(), ans.end());
    // printVec(ans);


    // // dijkstra
    // int n = 8;
    // WeightedGraph g(n);
    // g.addEdge(0, 1, 80);
    // g.addEdge(0, 3, 10);
    // g.addEdge(1, 2, 2);
    // g.addEdge(2, 7, 15);
    // g.addEdge(2, 3, 6);
    // g.addEdge(3, 4, 5);
    // g.addEdge(4, 5, 10);
    // g.addEdge(4, 6, 23);
    // g.addEdge(5, 6, 5);
    // int src; cin >> src;
    // auto ans = dijkstra(g, src);
    // printVec(ans);

    // // prim
    int n = 9;
    WeightedGraph g(n);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 8, 6);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 7);
    int ans = prim(g);
    cout << ans;
}