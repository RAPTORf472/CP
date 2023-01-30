int h[N], up[N][LOG];
vector<int> adj[N];

void preLca(int u, int pre) {

    for (int v : adj[u]) {
        
        if (v == pre) continue;
        
        h[v] = h[u] + 1;

        up[v][0] = u;
        
        for (int i = 1; i < LOG; i++) {
            
            up[v][i] = up[up[v][i-1]][i-1];

        }
        
        preLca(v, u);
        
    }
    
}

int lca(int a, int b) {
    
    if (h[a] < h[b]) swap(a, b);
    
    int d = h[a] - h[b];
    
    for (int i = LOG - 1; i >= 0; i--) {
        
        if (d & (1 << i)) {
            
            a = up[a][i];
            
        }
        
    }
    
    if (a == b) return a;
    
    for (int i = LOG - 1; i >= 0; i--) {
        
        if (up[a][i] == up[b][i]) continue;
        a = up[a][i], b = up[b][i];
        
    }
    
    return up[a][0];
    
}

int dist(int a, int b) {
    
    return h[a] + h[b] - 2 * h[lca(a, b)] + 1;
    
}
