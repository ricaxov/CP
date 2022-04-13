vector<int>adj[maxN];
vector<bool>vis(maxN);
void dfs(int v){
    vis[v]=true;
    for(int i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
