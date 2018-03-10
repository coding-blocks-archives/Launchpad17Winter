
void dfsSpecial(UnweightedGraph& g, int src, vb& visited, vi& ans){
    visited[src] = true;
    for(int nbr : g.v[src]){
        if (visited[nbr]) continue;
        dfsSpecial(g, nbr, visited, ans);
    }
    ans.push_back(src);
}

vi topologicalSort(UnweightedGraph& g){
    vi indegree(g.nv, 0);

    for(int i = 0; i < g.nv; ++i){
        for(int j = 0; j < g.v[i].size(); ++j){
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