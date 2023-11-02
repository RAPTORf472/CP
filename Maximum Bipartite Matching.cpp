bool bfsbm() {
	
    queue<int> q;
    forlr(i, 1, n) {
    	
        if (mx[i] == 0) {
        	
            q.push(i);
            dist[i] = 0;
            
        } else dist[i] = -1;
    }
    
    while(!q.empty()) {
    	
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
        	
            if (my[u] == 0) return true;
            else if (dist[my[u]] < 0) {
            	
                dist[my[u]] = dist[v] + 1;
                q.push(my[u]);
                
            }
            
        }
        
    }
    
    return false;
}

bool dfsbm(int v) {
	
    for (int u : adj[v]) {
    	
        if (my[u] == 0) {
        	
            mx[v] = u;
            my[u] = v;
            return true;
            
        } else if (dist[my[u]] == dist[v] + 1 && (dfsbm(my[u]))) {
        	
            mx[v] = u;
            my[u] = v;
            return true;
            
        }
        
    }
    
    return false;
    
}
