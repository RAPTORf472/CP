int work[2 * N], dist[2 * N], source, sink;

struct Edge {
	
    int v, pre, flow, cap;
    
};

//2 * N for bipartite graph
vector<Edge> adj[N];

void addEdge(int u, int v, int w) {
	
    Edge e1 = {v, adj[v].size(), 0, w};
    Edge e2 = {u, adj[u].size(), 0, 0};
    adj[u].push_back(e1);
    adj[v].push_back(e2);
    
}

bool bfsFlow() {
	
    queue<int> q;
    q.push(source);
    
    memset(dist, -1, sizeof dist);
    
    dist[source] = 0;
    while(!q.empty()) {
    	
        int u = q.front(); q.pop();
        
        for (auto [v, pre, flow, cap] : adj[u]) {
        	
            if (dist[v] < 0 && (flow < cap)) {
            	
                dist[v] = dist[u] + 1;
                q.push(v);
                
            }
            
        }
        
    }
    
    return (dist[sink] > 0);
}

int dfsFlow(int u, int f) {
	
    if (u == sink) return f;
    
    for (int &i = work[u]; i < adj[u].size(); i++) {
    	
        auto [v, pre, flow, cap] = adj[u][i];
        
        if (dist[v] == (dist[u] + 1) && (flow < cap)) {
        	
            int nf = dfsFlow(v, min(f, cap - flow));
            
            if (nf > 0) {
            	
                flow += nf;
                adj[v][pre].flow -= nf;
                return nf;
                
            }
            
        }
        
    }
    
    return 0;
    
}
