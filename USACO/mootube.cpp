#include <bits/stdc++.h>
#define ii pair<int, int>
#define fs first
#define sc second
#define iii pair<ii, int>
#define fs3 fs.fs
#define sc3 fs.sc
#define rd3 sc

using namespace std;

typedef long long ll;

struct DSU {
    
    int n; 
    
    vector<int> dsu, sz;
    
    void init(int n) {
        
        dsu.resize(n + 1);
        sz.resize(n + 1, 1);
        
        for (int i = 1; i <= n; i++) dsu[i] = i;
        
    }
    
    int findSet(int a) {
        
        int n = a;
        
        while (a != dsu[a]) a = dsu[a];
        
        return dsu[n] = a;
        
    }
    
    bool joinSet(int a, int b) {
        
        a = findSet(a), b = findSet(b);
        
        if (a == b) return false;
        
        if (sz[a] < sz[b]) swap(a, b);
        
        dsu[b] = a;
        sz[a] += sz[b];
        
        return true;
        
    }
    
};

map<ii, int> res;

int n, m;

const int N = 1e5 + 100;
iii edges[N];
ii query[N], org[N];

signed main() {
    
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    
    DSU d;
    cin >> n >> m;
    
    d.init(n);
    
    for (int i = 1, a, b, c; i < n; i++) {
        
        cin >> a >> b >> c;
        edges[i] = {{c, a}, b};
        
    }
    
    sort(edges + 1, edges + n, greater<iii>());
    
    for (int i = 1, k, v; i <= m; i++) {
        
        cin >> k >> v;
        org[i] = query[i] = {k, v};
        
    }
    
    sort(query + 1, query + m + 1, greater<ii>());
    
    int it = 1;
    
    for (int i = 1, k, u, v; i <= m; i++) {
        
        k = query[i].fs, u = query[i].sc;
        
        while (true) {
            
            if (edges[it].fs3 < k) break;
            d.joinSet(edges[it].sc3, edges[it].rd3);
            it++;
            
        }
        
        res[make_pair(k, u)] = d.sz[d.findSet(u)];
        
    }
    
    for (int i = 1; i <= m; i++) cout << res[{org[i].fs, org[i].sc}] - 1 << endl;
    
    return 0;
    
}
