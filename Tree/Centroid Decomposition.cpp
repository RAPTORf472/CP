namespace CD {
    
    vector<int> cenAdj[N];
    int par[N], sz[N];
    bool vist[N];
    
    int dfsCnt(int u, int pre) {
        
        sz[u] = 1;
        
        for (int v : adj[u]) {
            
            if (v == pre || vist[v]) continue;
            sz[u] += dfsCnt(v, u);

        }
        
        return sz[u];
        
    }
    
    int findCentroid(int u, int pre, int s) {
        
        for (int v : adj[u]) {
            
            if (v == pre || vist[v]) continue;
            if (sz[v] * 2 > s) return findCentroid(v, u, s);
            
        }
        
        return u;
        
    }
    
    int cd(int u) {
        
        int uc = findCentroid(u, 0, dfsCnt(u, 0));
        vist[uc] = 1;
        
        for (int v : adj[uc]) {
            
            if (vist[v]) continue;
            int vc = cd(v);
            cenAdj[uc].push_back(vc);
            cenAdj[vc].push_back(uc);
            par[vc] = uc;
            
        }
        
        return uc;
        
    }
    
    void init() {
        
        cd(1);
        
    }
    
}
