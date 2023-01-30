//Warning: cause segmentation fault when N is ~2e5

const int N = 1e5 + 100;

struct HLD {
    
    int nBase = 1, nChain = 1;
    int head[N], ind[N], basePos[N], par[N], cnt[N], rbasePos[N];
    vector<int> *adj;
    
    void init(vector<int> *adj) {
        
        this -> adj = adj;
        dfs(1, 1);
        hld(1);
        
    }

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
    
    int query(int u, int v) {
    
        while(true) {
            
            int uchain = ind[u], vchain = ind[v];
            
            if (uchain == vchain) {
    
                int st = basePos[u], en = basePos[v];
                if(st > en) {
                    
                    swap(st, en);
                    swap(u, v);
                       
                }
                
                // end point
                
                return u;

            }
            
            if (uchain < vchain) {
                
                swap(u, v);
                swap(uchain, vchain);
                
            }
            
            int hi = basePos[u], lo = basePos[head[uchain]];
            u = par[head[uchain]];
            uchain = ind[u];
            
        }
        
        return 0;
        
    }
    
};
