int knapsack(int elementos, int *lucro, int *peso, int maximo){
    int ks[elementos+1][maximo+1];
    for(int i=0; i<=elementos; i++){
        for(int j=0; j<=maximo; j++){
            if(i==0 || j==0){
                ks[i][j]=0;
            }
            else{
                if(peso[i]<=j){
                    ks[i][j]=max(lucro[i]+ks[i-1][j-peso[i]], ks[i-1][j]);
                }
                else{
                    ks[i][j]=ks[i-1][j];
                }
            }
        }
    }
    return ks[elementos][maximo];
}
