
struct comparePair
{
    bool operator()(const Pair& a, const Pair& b){
        // shall a  come before b
        return a.wt > b.wt;
    }   
};


vi dijkstra(WeightedGraph& g, int src){
    // SSSP : Single Src Shortest Path
    auto n = g.nv;
    auto adjList = g.v;

    vi dist(n, inf);

    priority_queue<Pair, vp, comparePair> pq;

    pq.push(Pair(src, 0));  // Pair : id, distFromSrc
    
    while(pq.empty() == false){
        auto p = pq.top();
        pq.pop();

        int id = p.id;
        int wt = p.wt;

        if (wt >= dist[id]) continue;
        dist[id] = wt;  // distFromSrc

        auto nbrList = adjList[id];
        for(auto nbrPair : nbrList){
            int nbrId = nbrPair.id;
            int nbrWt = nbrPair.wt + dist[id];
            if (nbrWt < dist[nbrId]){
                pq.push(Pair(nbrId, nbrWt));
            }
        }
    }
    return dist;
}