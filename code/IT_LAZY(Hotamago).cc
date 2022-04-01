struct sem{
    int l, r, w;
} sems[300005];
struct node{
    int val, lazy;
};
struct IT{
    int n;
    vector<node> it;
    void downnode(int i){
        it[i*2].val += it[i].lazy;
        it[i*2 + 1].val += it[i].lazy;
        it[i*2].lazy += it[i].lazy;
        it[i*2 + 1].lazy += it[i].lazy;
        it[i].lazy = 0;
    }
    void init(int _n){
        n = _n;
        it = vector<node>(4*n + 1, {0, 0});
    }
    void update(int i, int l, int r, int u, int v, int val){
        if(l > v || r < u) return;
        if(l >= u && r <= v){
            it[i].val += val;
            it[i].lazy += val;
            return;
        }
        int mid = (l+r)/2;
        downnode(i);
        update(i*2, l, mid, u, v, val);
        update(i*2 + 1, mid + 1, r, u, v, val);
        it[i].val = min(it[i*2].val, it[i*2 + 1].val);
    }
    int query(int i, int l, int r, int u, int v){
        if(l > v || r < u) return 1000000007;
        if(l >= u && r <= v) return it[i].val;
        int mid = (l+r)/2;
        downnode(i);
        return min(query(i*2, l, mid, u, v), query(i*2 + 1, mid + 1, r, u, v));
    }
    void upd(int l, int r, int val){
        update(1,1,n,l,r,val);
    }
    int quy(int l, int r){
        return query(1, 1, n, l, r);
    }
} se;