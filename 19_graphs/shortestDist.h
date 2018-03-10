vi shortestDist(UnweightedGraph& g, int src){
    int nv = g.nv;
    vector<vi>& v = g.v;

    vector<int> dist(nv, inf);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while(q.empty() == false){
        int cur = q.front();
        q.pop();

        vi& nbrList = v[cur];
        for(int i = 0; i < nbrList.size(); ++i){
            int nbr = v[cur][i];
            if (dist[nbr] == inf){
                dist[nbr] = 1 + dist[cur];
                q.push(nbr);
            }
        }
    }
    return dist;
}