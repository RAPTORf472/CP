//etour

vector<int> adj[N];
int start[N], stop[N], pos[N], timeDfs = 0;

//

void etour(int u, int par) {
    
    start[u] = ++timeDfs;
    pos[timeDfs] = u;
    
    for (int v : adj[u]) {
        
        if (v == par) continue;
        etour(v, u);
        
    }
    
    stop[u] = timeDfs;
    
}
