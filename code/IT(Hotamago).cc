struct IT{
    int n;
    vector<int> it;
    void init(int _n){
        n = _n;
        it = vector<int>(4*n + 1, 0);
    }
    void update(int i, int l, int r, int u, int val){
        if(l > u || r < u) return;
        if(l >= r){
            it[i] = val;
            return;
        }
        int mid = (l+r)/2;
        update(i*2, l, mid, u, val);
        update(i*2 + 1, mid + 1, r, u, val);
        it[i] = min(it[i*2], it[i*2 + 1]);
    }
    int query(int i, int l, int r, int u, int v){
        if(l > v || r < u) return 1000000007;
        if(l >= u && r <= v) return it[i];
        int mid = (l+r)/2;
        return min(query(i*2, l, mid, u, v), query(i*2 + 1, mid + 1, r, u, v));
    }
    void upd(int u, int val){
        update(1,1,n,u,val);
    }
    int quy(int l, int r){
        return query(1, 1, n, l, r);
    }
} se;