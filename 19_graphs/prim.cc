// PRIM's algorithm
struct comparePair
{
    bool operator()(const Pair& a, const Pair& b){
        // shall a  come before b
        return a.wt > b.wt;
    }   
};

int prim(WeightedGraph& g){
    auto n = g.nv;
    auto adjList = g.v;
    priority_queue<Pair, vp, comparePair> pq;
    vb visited(n, false);

    int cost = 0;
    pq.push(Pair(0, 0));

    while(pq.empty() == false){
        auto cur = pq.top();
        pq.pop();

        if (visited[cur.id] == false){
            visited[cur.id] = true;
            cout << cur.id << " ";
            cost += cur.wt;
        }

        auto nbrList = adjList[cur.id];
        for(auto p : nbrList){
            if (visited[p.id]) continue;
            pq.push(p);
        }
    } 
    return cost;
}