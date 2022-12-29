#include <bits/stdc++.h>

#define ii pair<int, int>
#define fs first
#define sc second
#define iii pair<int, ii>
#define fs3 fs
#define sc3 sc.fs
#define rd3 sc.sc
#define iiii pair<ii, ii>
#define fs4 fs.fs
#define sc4 fs.sc
#define rd4 sc.fs
#define fo4 sc.sc
#define db double
#define int long long

#define show(v) for (auto i : v) cout << i << " "; cout << endl;
#define showlr(v, l, r) for (int i = l; i <= r; i++) cout << v[i] << " "; cout << endl;
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v));
#define Sortlr(v, l, r) sort(v + l, v + r);
#define rev(v) reverse(v.begin(), v.end());
#define revlr(v) reverse(v + l, v + r);
#define Unique(v) v.erase(unique(all(v)), v.end());
#define SUnique(v) Sort(v); Unique(v);
#define Fill(v) memset(v, 0, sizeof v);
#define Filldp(v) memset(v, -1, sizeof v);
#define mp(a, b) make_pair(a, b)
#define Has(v, l, r, val) binary_search(v + l, v + r, val)

#pragma GCC Optimize("O2")
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precise(x) cout << fixed << setprecision(x);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 100;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 25;

ostream& operator << (ostream &os, ii a) {
    
    os << a.fs << ' ' << a.sc;
    
    return os;
    
}

ostream& operator << (ostream &os, iii a) {
    
    os << a.fs3 << " " << a.sc3 << " " << a.rd3;
    
    return os;
    
}

ostream& operator << (ostream &os, iiii a) {
    
    os << a.fs4 << ' ' << a.sc4 << " " << a.rd4 << " " << a.fo4;
    
    return os;
    
}

int ceil(int a, int b) {
    
    return (a + b - 1) / b;
    
}

int binPow(int a, int b, int m) {
    
    int prod = 1;
    a %= m;
    
    while (b) {
        
        if (b & 1) prod = prod * a % m;
        a = a * a % m;
        b /= 2;
        
    }
    
    return prod;
    
}

int sqr(int a) {
    
    return a * a;
    
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int a[N], n;

struct Node {
        
    int val;
    int lazy;
    
} seg[4 * N];

vector<int> adj[N];

void build(int id, int l, int r) {
        
    if (l == r) {
        
        seg[id].val = a[l];
        return;
    }
    
    int mid = (l+r) / 2;
    
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    
    seg[id].val = max(seg[id*2].val, seg[id*2+1].val);
}

void push(int id) {
    
    if (!seg[id].lazy) return;
    
    seg[id*2].lazy = seg[id].lazy;
    seg[id*2].val = seg[id].lazy;
    
    seg[id*2+1].lazy = seg[id].lazy;
    seg[id*2+1].val = seg[id].lazy;
    
    seg[id].lazy = 0;
    
}

void update(int id, int l, int r, int u, int v, int add) {
    
    if (v < l || r < u) return;
    
    if (u <= l && r <= v) {
        
        seg[id].val = add;
        seg[id].lazy = add;
        return;
        
    }
    
    push(id);
    int mid = (l+r) / 2;
    
    update(id*2, l, mid, u, v, add);
    update(id*2+1, mid+1, r, u, v, add);
    
    seg[id].val = max(seg[id*2].val, seg[id*2+1].val);
    
}

void update(int l, int r, int val) {
    
    update(1, 1, n, l, r, val);
    
}

void update(int u, int val) {
    
    update(1, 1, n, u, u, val);
    
}

int get(int id, int l, int r, int u, int v) {
    
    if (v < l || r < u) return 0;
    
    if (u <= l && r <= v) {
        
        return seg[id].val;
        
    }
    
    push(id);
    int mid = (l+r) / 2;
    
    return (get(id*2, l, mid, u, v) +
               get(id*2+1, mid+1, r, u, v));
               
}

int get(int l, int r) {
    
    return get(1, 1, n, l, r);
    
}

int get(int u) {
    
    return get(u, u);
    
}

int nBase = 1, nChain = 1;
int head[N], ind[N], basePos[N], par[N], cnt[N], rbasePos[N];

void hld(int u) {
    
    if(head[nChain] == 0) head[nChain] = u;
    ind[u] = nChain;
    basePos[u] = nBase;
    rbasePos[nBase++] = u;

    int mx = -1;

    for (int v : adj[u]) {
        
        if (v == par[u]) continue;

        if (mx == -1 || cnt[v] > cnt[mx])
            mx = v;
        
    }

    if (mx > -1) hld(mx);

    for(int v : adj[u]) {
        
        if(v == par[u]) continue;
        
        if(v != mx) {
            
            nChain++;
            hld(v);
        }
        
    }
    
}

void dfs(int u, int pre) {
    
    cnt[u] = 1;
    
    for(int v : adj[u]) {
        
        if(v == pre) continue;
        par[v] = u;
        dfs(v, u);
        cnt[u] += cnt[v];
        
    }
    
}

void init() {
    
    dfs(1, 1);
    hld(1);
    
}

int sal[N], arr[N];

int bs(int L, int R, int val) {
    
    if (get(L) < val) return -1;
    
    int l = L, r = R, mid, ans = L;
    
    while (l <= r) {
        
        mid = (l + r) / 2;
        
        if (get(mid) > val) {
            
            l = mid + 1;
            ans = mid;
            
        } else r = mid - 1;
        
    }
    
    return ans;
    
}

int query(int u, int val) {

    int v = 1;

    int sum = 0;

    while(true) {
        
        int uchain = ind[u], vchain = ind[v];
        
        if (uchain == vchain) {

            int lo = basePos[u], hi = basePos[v];
            
            if(lo > hi) {
                
                swap(lo, hi);
                swap(u, v);
            }                
            
            int pos = bs(lo, hi, val);

            if (pos == -1) {
            
                sum += hi - lo + 1;
                update(lo, hi, val);

            } else {
                
                sum += hi - pos;
                update(pos + 1, hi, val);

            }
            
            // end point
            
            return sum;

        }
        
        if (uchain < vchain) {
            
            swap(u, v);
            swap(uchain, vchain);
            
        }
        
        int hi = basePos[u], lo = basePos[head[uchain]];
        int pos = bs(lo, hi, val);

        if (pos == -1) {
            
            sum += hi - lo + 1;

        } else {
            
            sum += hi - pos;
            update(pos + 1, hi, val);
            return sum;
            
        }
        
        update(lo, hi, val);
        u = par[head[uchain]];
        uchain = ind[u];
        
    }
    
    return 0;
    
}

void solve() {
    
    cin >> n;
    
    int boss; cin >> boss;
    
    for (int i = 2, a, b; i <= n + 1; i++) {
        
        cin >> a >> b;
        b++;
        adj[b].push_back(i);
        adj[i].push_back(b);
        sal[i] = a;
        
    }
    
    init();
    build(1, 1, n+1);
    update(1, boss);
    
    for (int i = 2; i <= n + 1; i++) {
        
        int cur = sal[i];
        update(basePos[i], cur);
        cout << query(par[i], cur) << endl;
        
    }
    
}

signed main() {
    
    fastIO;
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
