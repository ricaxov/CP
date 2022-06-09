void topoSort(vector<string>&bebidas){
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i=0; i<bebidas.size(); i++){
        if(vet[ligacoes[bebidas[i]]]==0){
            q.push(i);
        }
    }
    int index=0;
    while(!q.empty()){
        int u=q.top(); q.pop();
        ordenado[index++]=bebidas[u];
        for(string i : adj[ligacoes[bebidas[u]]]){
            vet[ligacoes[i]]--;
            if(vet[ligacoes[i]]==0){
                q.push(ligacoes[i]);
            }
        }
    }
}
