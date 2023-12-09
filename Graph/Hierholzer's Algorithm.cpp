bool used[N];
vector<int> path;
vector<ii> adj[N];

void dfsEuler(int u) {
	
	while (adj[u].size()) {
		
		auto [v, id] = adj[u].back();
		adj[u].pop_back();
		if (used[id]) continue;
		used[id] = true;
		dfsEuler(v);
		adj[u].push_back({v, id});
		
	}
	
	path.push_back(u);
	
}

void solve() {
    
    cin >> n >> m;
    forlr(i, 1, m) {
    	
    	int u, v; cin >> u >> v;
    	adj[u].push_back({v, i});
    	adj[v].push_back({u, i});
    	
    }
    
    forlr(i, 1, n) {
    	
    	if (adj[i].size() % 2) {
    		
    		cout << "IMPOSSIBLE" << endl;
    		return;
    		
    	}
    	
    }
        
    dfsEuler(1);
    if (path.size() != m + 1) cout << "IMPOSSIBLE" << endl;
    else show(path);
    
}
