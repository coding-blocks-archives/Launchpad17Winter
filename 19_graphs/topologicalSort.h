
void dfsSpecial(UnweightedGraph& g, int src, vb& visited, vi& ans) {
    visited[src] = true;
    for (int nbr : g.v[src]) {
        if (visited[nbr]) continue;
        dfsSpecial(g, nbr, visited, ans);
    }
    ans.push_back(src);
}

vi topologicalSort(UnweightedGraph& g) {
    vi indegree(g.nv, 0);

    for (int i = 0; i < g.nv; ++i) {
        for (int j = 0; j < g.v[i].size(); ++j) {
            int nbr = g.v[i][j];
            indegree[nbr]++;
        }
    }

    int src = find(indegree.begin(), indegree.end(), 0) - indegree.begin();
    vb visited(g.nv, false);
    vi ans;
    dfsSpecial(g, src, visited, ans);
    return ans;
}


vi topologicalSortBFS(UnweightedGraph& g) {
    auto nv = g.nv;
    auto adjList = g.v;
    vi indegree(g.nv, 0);

    for (int i = 0; i < g.nv; ++i) {
        for (int j = 0; j < g.v[i].size(); ++j) {
            int nbr = g.v[i][j];
            indegree[nbr]++;
        }
    }

    int src = find(indegree.begin(), indegree.end(), 0) - indegree.begin();
    queue<int> q;
    vi ans;

    q.push(src);

    while(q.empty() == false){
        auto cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(auto nbr : adjList[cur]){
            indegree[nbr]--;
            if (indegree[nbr] == 0){
                q.push(nbr);
            } 
        }
    }
    return ans;
}