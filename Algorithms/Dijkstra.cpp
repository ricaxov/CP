vector<ii>adj[maxN];
int dijkstra(int o, int d){
    vector<int>dist(maxN, inf);
    priority_queue<ii, vector<ii>, greater<ii> >pq;
    vector<int>pai(maxN, -1);
    dist[o]=0;
    pq.push({0,o});
    while(!pq.empty()){
        ii u=pq.top(); pq.pop();
        for(auto v : adj[u.s]){
            int to=v.f;
            int len=v.s;
            if(dist[to]>len+dist[u.s]){
                dist[to]=len+dist[u.s];
                pai[to]=u.s;
                pq.push({dist[to],to});
            }
        }
    }
    return dist[d];
}
