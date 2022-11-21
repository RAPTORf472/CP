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

signed main() {
    
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    DSU d;
    cin >> n >> m;
    
    d.init(n);
    fill(d.sz.begin(), d.sz.end(), 0);
    
    bool OK = true;
    int total = 0;
    
    for (int i = 1, a; i <= n; i++) {
        
        cin >> a;
        if (a != i) {
            
            OK = false;
            d.sz[i] = 1;
            total++;
            
        }
        
    }
    
    if (OK) {
        
        cout << -1 << endl;
        exit(0);
        
    }
    
    for (int i = 1, a, b, c; i <= m; i++) {
        
        cin >> a >> b >> c;
        edges[i] = {{c, a}, b};
        
    }
    
    sort(edges + 1, edges + m + 1, greater<iii>());
    
    for (int i = 1; i <= m; i++) {
        
        int u = edges[i].sc3, v = edges[i].rd3;
        
        d.joinSet(u, v);
        
        if (d.sz[d.findSet(u)] == total) {
            
            cout << edges[i].fs3 << endl;
            exit(0);
            
        }
        
    }
    
    return 0;
    
}
