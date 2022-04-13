#include <bits/stdc++.h>
#define f first
#define s second
#define maxN 9999
#define inf 1e9
#define pi 3.14159
#define pb push_back
#define ll long long
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pair<int,int>>

using namespace std;

vii adj[maxN];
int dijkstra(int o, int d){
	vi dist(maxN, inf);
	priority_queue<ii, vii, greater<ii> >pq;
	vi pai(maxN, -1);
	dist[o]=0;
	pq.push({0,o});
	while(!pq.empty()){
		ii u=pq.top(); pq.pop();
		if(dist[u.s]!=u.f) continue;
		for(auto v : adj[u.s]){
			int to=v.s;
			int len=v.f;
			if(dist[to]>len+dist[u.s]){
				dist[to]=len+dist[u.s];
				pai[to]=u.s;
				pq.push({dist[to],to});
			}
		}
	}
	return dist[d];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	
}
