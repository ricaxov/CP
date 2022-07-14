vector<int>vet,seg(100000);
int build(int l, int r, int i){
    if(l==r){
        return seg[i]=vet[l];
    }
    int mid=(l+r)/2;
    return seg[i]=min(build(l,mid,2*i+1),build(mid+1,r,2*i+2));
}
int query(int l, int r, int ql, int qr, int i){
    if(l>=ql && r<=qr) return seg[i];
    if(l>qr || r<ql) return inf;
    int mid=(l+r)/2;
    return min(query(l,mid,ql,qr,2*i+1),query(mid+1,r,ql,qr,2*i+2));
}
