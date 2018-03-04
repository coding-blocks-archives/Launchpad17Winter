// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<list<int> > v;
    int nV;
public:
    Graph(int n) {
        nV = n;
        v.resize(n);
    }

    void addEdge(int src, int dest) {
        v[src].push_back(dest);
        v[dest].push_back(src);
    }

    void bfs(int src) {
        vector<bool> visited(nV, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (q.empty() == false) {
            int curVtx = q.front();
            cout << curVtx << " ";
            q.pop();

            for(list<int>::iterator it = v[curVtx].begin(); it != v[curVtx].end(); ++it){
                int ngbr = *it;
                if (visited[ngbr] == false){
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }
    }

    void printGraph() {
        int i = 0;
        for (list<int>& l : v) { // for(list l = v[0];)
            cout << i << ":";
            ++i;

            for (int vtx : l) {
                cout << vtx << " ";
            }

            cout << endl;
        }
    }

    void dfs(int src, vector<bool>& visited) {
        cout << src << " ";
        visited[src] = true;

        // for(auto x : v[src])

        list<int>::iterator it = v[src].begin();   // list* it = head
        while (it != v[src].end()) {
            int ngbr = *it;
            if (visited[ngbr] != true) {
                dfs(ngbr, visited);
            }
            ++it;
        }
    }

    void dfs(int src) {
        vector<bool> visited(nV, false);

        dfs(src, visited);

    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    g.printGraph();
    cout << "/*******************************/\n";
    // g.dfs(0);
    g.bfs(0);
}