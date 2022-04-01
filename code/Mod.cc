//-----------------------------------------------//
//               Auto mod number                //
//-----------------------------------------------//
template<ll M>
struct modint {
 
    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};
 
using mod = modint<998244353>;
//-----------------------------------------------//
//                  Factorial                    //
//-----------------------------------------------//
struct fac{
    int n; ll mod_fac; vector<ll> f;
    fac(){}
    fac(ll _mod_fac){ n = 0; f = vector<ll>(1); f[0] = 1; mod_fac = _mod_fac; }
    fac(ll _mod_fac, int _n){ n = _n; f = vector<ll>(n + 1, 0); f[0] = 1; mod_fac = _mod_fac; }
    ll get(int index){ if(index <= n) return f[index]; for(int i = n + 1; i<=index; i++){ f.push_back(f.back()*i%mod_fac); n++; } return f[index]; }
} ft;

//-----------------------------------------------//
//                  Math prox                    //
//-----------------------------------------------//
ll pow_hota(ll ax, ll bx){
    ll cx = 1;
    while(bx > 0) {
      if(bx & 1)
        cx = 1ll * cx * ax % mod;
      ax = 1ll * ax * ax % mod;
      bx >>= 1;
    }
    return cx;
}

ll divmod(ll ax, ll bx){
    ax%=mod; bx%=mod;
    return (ax*pow_hota(bx, mod-2))%mod;
}

ll Cx(ll _n, ll _k){
    return divmod(ft.get(_n), ft.get(_k)*ft.get(_n - _k)%mod)%mod;
}

//-----------------------------------------------//
//                  LCM MOD                      //
//-----------------------------------------------//
const int MAX = 200000; 
int prime[MAX];
unordered_map<int, int> max_map;
ll pow_hota(ll ax, ll bx){
    ll cx = 1;
    while(bx > 0) {
      if(bx & 1)
        cx = 1ll * cx * ax % mod;
      ax = 1ll * ax * ax % mod;
      bx >>= 1;
    }
    return cx;
}
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (prime[j] == 0) {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}
// LCM MOD
ll lcmModuloM(const int* ar, int n){
    for (int i = 0; i < n; i++) {
        int num = ar[i];
        unordered_map<int, int> temp;
        while (num > 1) {
            int factor = prime[num];
            temp[factor]++;
            num /= factor;
        }
 
        for (auto it : temp) {
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }
    ll ans = 1;
    for (auto it : max_map) {
        ans = (ans * pow_hota(it.F, it.S)) % mod;
    }
    return ans;
}