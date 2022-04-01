struct BIT{
    int n;
    vi bit;
    void setup(int _n){
        n = _n;
        bit = vi(n + 1, 0);
    }
    void update(int i, int deta){
        for(; i<=n; i+=i&-i){
            bit[i] += deta;
        }
    }
    int query(int i){
        int sum = 0;
        for(; i>0; i-=i&-i){
            sum += bit[i];
        }
        return sum;
    }
    int get(int l, int r){
        return query(r) - query(l-1);
    }
} be;