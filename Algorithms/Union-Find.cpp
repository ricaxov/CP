vector<int>pai(1000000),r(1000000);
vector<pair<double,pair<double,double>>>adj;
void makeSet(int n){
    for(int i=0; i<n; i++){
        pai[i]=i;
        r[i]=1;
    }
}
int find(int x){
    if(pai[x]==x){
        return x;
    }
    return pai[x]=find(pai[x]);
}
bool sameSet(int x, int y){
    return find(x)==find(y);
}
void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(r[x]>r[y]){
        pai[y]=x;
        r[x]+=r[y];
    }
    else{
        pai[x]=y;
        r[y]+=r[x];
    }
}
double kruskal(int n){
    double ans=0;
    for(int i=0; i<n; i++){
        float peso=adj[i].f,a=adj[i].s.f,b=adj[i].s.s;
        if(!sameSet(a,b)){
            unite(a,b);
            ans+=peso;
        }
    }
    return ans;
}
