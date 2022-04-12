#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>

using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},cont,maior;
char matrix[21][21],terra,agua;
void elimina(int x, int y, int mx, int my){
    matrix[x][y]=agua;
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            elimina(ax,ay,mx,my);
        }
    }
}
void floodfill(int x, int y, int mx, int my){
    matrix[x][y]=agua;
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            cont++;
            floodfill(ax,ay,mx,my);
        }
        if(matrix[ax][0]==terra && matrix[ax][mx-1]==terra){
            floodfill(ax,my-1,mx,my);
        }
        if(matrix[ax][my-1]==terra && matrix[ax][0]==terra){
            floodfill(ax,0,mx,my);
        }
    }
    if(cont>maior){
		maior=cont;
	}
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,x,y;
    while(cin>>n>>m){
        cont=0,maior=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        cin>>x>>y;
        terra=matrix[x][y];
        elimina(x,y,n,m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]!=terra){
                    agua=matrix[i][j];
                    i=n;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==terra){
                    floodfill(i,j,n,m);
                }
            }
        }
        if(maior==0){
            cout<<maior<<endl;
        }
        else{
            cout<<maior+1<<endl;
        }
    }
}
