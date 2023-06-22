int n, m;

vector<int> adj[N];

int low[N], num[N], timeDfs, scc;
stack<int> order;
vector<int> comps[N];

void tarjan(int u) {
    
    low[u] = num[u] = ++timeDfs;
    order.push(u);
    
    for (int v : adj[u]) {
        
        if (num[v]) {
            
            low[u] = min(low[u], num[v]);
            
        } else {
            
            tarjan(v);
            low[u] = min(low[u], low[v]);
            
        }
        
    }
    
    if (num[u] == low[u]) {
        
        scc++;
        int tmp;
        
        do {
            
            tmp = order.top();
            order.pop();
            comps[scc].push_back(tmp);
            num[tmp] = INF;
            
        } while (tmp != u);
        
    }
    
}

void solve() {
    
    cin >> n >> m;
    scc = 0;
    timeDfs = 0;
    
    int a, b;
    forlr(i, 1, m) {
        
        cin >> a >> b;
        adj[a].push_back(b);
        
    }
    
    forlr(i, 1, n) {
        
        if (!num[i]) tarjan(i);
        
    }
    
    cout << scc << endl;
    forrl(i, scc, 1) {
        
        cout << comps[i].size() << " ";
        for (int v : comps[i]) cout << v << " "; cout << endl;
        
    }

}
