struct FenwickTree {
    ll n;
    vl bit;
    void init(ll _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void upd(ll p, ll v) {
        for(; p <= n; p += p&-p) {
            bit[p] += v;
        }
    }
    void upd(ll l, ll r, ll v) {
        upd(l, v);
        upd(r + 1, -v);
    }
    ll query(ll p) {
        ll res = 0;
        for(; p > 0; p -= p&-p) {
            res += bit[p];
        }
        rtn res;
    }
    ll query(ll l, ll r) {
        rtn query(r) - query(l - 1);
    }
};
