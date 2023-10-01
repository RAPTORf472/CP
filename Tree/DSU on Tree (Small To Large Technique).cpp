void dfsCnt(int u, int pre) {
    
    sz[u] = 1;
    
    for (int v : adj[u]) {
        
        if (v == pre) continue;
        dfsCnt(v, u);
        sz[u] += sz[v];
        
    }
    
}

void add(int x) {
    
}

void del(int x) {
    
}
 
void dfs(int u, int pre, bool keep) {
    
    int mx = -1;
    for (int v : adj[u]) {
        
        if (v == pre) continue;
        if (mx == -1 || sz[v] > sz[mx]) mx = v;
        
    }
    
    for (int v : adj[u]) {
        
        if (v == pre) continue;
        if (v != mx) dfs(v, u, 0);
        
    }
    
    if (mx != -1) {
        
        dfs(mx, u, 1);
        swap(active[u], active[mx]);
        
    }
    
    active[u].push_back(u);
    add(u);
    
    for (int v : adj[u]) {
        
        if (v == pre || v == mx) continue;
        for (int x : active[v]) {
            
            add(x);
            active[u].push_back(x);
            
        }
        
    }
    
    // res[u] = total[Mx];
    
    if (keep == 0) {
        
        for (int x : active[u]) del(x);
        
    }
    
}

void solve() {
    
    cin >> n;
    
    forlr(i, 1, n - 1) {
        
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    dfsCnt(1, 1);
    dfs(1, 1, 0);

}
