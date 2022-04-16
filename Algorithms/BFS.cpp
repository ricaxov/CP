bool vis[maxX][maxY];
int bfs(int sx, int sy, int fx, int fy, int mx, int my){
    queue<pair<int,ii> >q;
    q.push({sx,{sy,0}});
    vis[sx][sy]=true;
    while(!q.empty()){
        pair<int,ii>u=q.front();q.pop();
        if(u.f==fx && u.s.f==fy){
            return u.s.s;
        }
        if(u.f-1>=0 && !vis[u.f-1][u.s.f]){
            q.push({u.f-1,{u.s.f,u.s.s+1}});
            vis[u.f-1][u.s.f]=true;
        }
        if(u.f+1<mx && !vis[u.f+1][u.s.f]){
            q.push({u.f+1,{u.s.f,u.s.s+1}});
            vis[u.f+1][u.s.f]=true;
        }
        if(u.s.f-1>=0 && !vis[u.f][u.s.f-1]){
            q.push({u.f,{u.s.f-1,u.s.s+1}});
            vis[u.f][u.s.f-1]=true;
        }
        if(u.s.f+1<my && !vis[u.f][u.s.f+1]){
            q.push({u.f,{u.s.f+1,u.s.s+1}});
            vis[u.f][u.s.f+1]=true;
        }
    }
    return 0;
}
