int dsu[N];

int findSet(int a) {
    
    int x = a;
    
    while (a != dsu[a]) a = dsu[a];
    
    return dsu[x] = a;
    
}

void solve() {
    
    cin >> n;
    iota(dsu, dsu + n + 10, 0);
    
    for (int i = 1, a, b; i < n; i++) {
        
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    
    forlr(i, 1, n) {
        
        for (int v : adj[i]) {
            
            if (v < i) {
                
                v = findSet(v);
                adjMax[v].push_back(i);
                dsu[v] = i;
                
            }
            
        }
        
    }
  
}
