namespace LCA {
    
    int h[N], id[2*N], pos[2*N];
    ii st[2*N][LOG];
    int timeDfs;
    
    void dfs(int u, int pre) {
        
        id[u] = ++timeDfs;
        pos[timeDfs] = u;
        h[u] = h[pre] + 1;
        
        for (int v : adj[u]) {
            
            if (v == pre) continue;
            dfs(v, u);
            pos[++timeDfs] = u;
            
        }
        
    }
    
    void init() {
        
        dfs(1, 1);
        
        for (int i = 1; i <= timeDfs; i++) st[i][0] = {h[pos[i]], pos[i]};
        for (int i = 1; i < LOG; i++) {
            
            for (int j = 1; j + (1 << i) - 1 <= timeDfs; j++) {
                
                st[j][i] = min(st[j][i-1], st[j + (1 << (i - 1))][i - 1]);
                
            }
            
        }
        
    }
    
    int getLca(int a, int b) {
        
        a = id[a], b = id[b];
        if(a > b) swap(a, b);
        int lg = __lg(b - a + 1);
        
        return min(st[a][lg], st[b - (1 << lg) + 1][lg]).sc;
        
    }
    
}
