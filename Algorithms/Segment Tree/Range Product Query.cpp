//Range Product Query
vector<int>vec(100005),seg(4*100005);
void build(int l, int r, int i){
    if(l==r){
        seg[i]=vec[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*i+1);
    build(mid+1,r,2*i+2);
    seg[i]=seg[2*i+1]*seg[2*i+2];
}
void update(int l, int r, int pos, int valor, int i){
    if(r<pos || pos<l) return;
    if(l==r){
        seg[i]=valor;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,pos,valor,2*i+1);
    update(mid+1,r,pos,valor,2*i+2);
    seg[i]=seg[2*i+1]*seg[2*i+2];
}
int query(int l, int r, int ql, int qr, int i){
    if(l>qr || r<ql) return 1;
    if(ql<=l && r<=qr) return seg[i];  
    int mid=(l+r)/2;
    int qL=query(l,mid,ql,qr,2*i+1);
    int qR=query(mid+1,r,ql,qr,2*i+2);
    return qL*qR;
}
