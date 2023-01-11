struct DSU {
    
    static const int S = 2e3 + 1;
    int dsu[S], sz[S];
    
    DSU() {
        
        init();
        
    }
    
    void init() {
        
        for (int i = 0; i < S; i++) {
            
            sz[i] = 1;
            dsu[i] = i;
            
        }
        
    }
    
    int findSet(int a) {
        
        int x = a;
        
        while (a != dsu[a]) a = dsu[a];
        
        return dsu[x] = a;
        
    }
    
    bool sameSet(int a, int b) {
        
        return findSet(a) == findSet(b);
        
    }
    
    bool joinSet(int a, int b) {
        
        a = findSet(a), b = findSet(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        dsu[b] = a;
        sz[a] += sz[b];
        return true;
        
    }
    
} dsu;
