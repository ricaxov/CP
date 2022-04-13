int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool matrix[maxX][maxY];
void floodfill(int x, int y, int m){
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<m && ay>=0 && ay<m && matrix[ax][ay]==0){
            matrix[ax][ay]=1;
            floodfill(ax,ay,m);
        }
    }
}
