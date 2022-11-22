#include <bits/stdc++.h>
#define ii pair<int, int>
#define fs first
#define sc second
#define iii pair<ii, int>
#define fs3 fs.fs
#define sc3 fs.sc
#define rd3 sc
#define endl "\n"
#pragma GCC Optimize("O2")
#define int long long

using namespace std;

const int N = 500 + 100;
const int LOG = 22;
const int INF = 1e9 + 100;

const int dx[2] = {0, 1};
const int dy[4] = {1, 0};

typedef long long ll;

ll sqr(int x) {
    
    return x * x;
    
}

ll res = 0;

int n, m, T;

struct DSU {
    
    vector<int> dsu, sz, start;
    
    void init(int n) {
        
        dsu.resize(n + 1), sz.resize(n + 1, 1), start.resize(n + 1);
        for (int i = 1; i <= n; i++) dsu[i] = i;
        
    }
    
    int findSet(int a) {
        
        int x = a;
        
        while (a != dsu[a]) a = dsu[a];
        
        return dsu[x] = a;
        
    }
    
    bool joinSet(int a, int b, int k) {
        
        a = findSet(a), b = findSet(b);
        
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        
        sz[a] += sz[b];
        start[a] += start[b];
        dsu[b] = a;
        
        if (sz[a] >= T) {
            
            res += start[a] * k;
            start[a] = 0;
            
        }
        
        return true;
        
    }
    
};

vector<iii> w;

int g[N][N], s[N][N];

int id(int x, int y) {
    
    return (x - 1) * m + y;
    
}

bool in(int x, int y) {
    
    return (x > 0) && (y > 0) && (x <= n) && (y <= m);
    
}

signed main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    
    DSU d;
    
    cin >> n >> m >> T;
    d.init(n * m);
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= m; j++) {
            
            cin >> g[i][j];
            
        }
        
    }
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= m; j++) {
            
            cin >> s[i][j];
            
            if (s[i][j]) d.start[id(i, j)] = 1;
            
        }
        
    }
    
    for (int X = 1; X <= n; X++) {
        
        for (int Y = 1; Y <= m; Y++) {
            
            for (int i = 0; i < 2; i++) {
                
                int x = X + dx[i], y = Y + dy[i];
                if (!in(x, y)) continue;
                w.push_back({{abs(g[x][y] - g[X][Y]), id(x, y)}, id(X, Y)});
                
            }
            
        }
        
    }
    
    sort(w.begin(), w.end());
    
    for (iii i : w) {
        
        int W = i.fs3, u = i.sc3, v = i.rd3;
        d.joinSet(u, v, W);
        
    }
    
    cout << res << endl;
    
}
