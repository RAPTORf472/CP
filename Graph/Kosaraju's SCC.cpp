int n, m, q, k;
int arr[N];
vector<int> adj[N], Radj[N];

vector<int> comps[N];
stack<int> order;

int scc = 0;

bool vist[N];

void dfs1(int u) {
    
    if (vist[u]) return;
    vist[u] = 1;
    
    for (int v : adj[u]) dfs1(v);
    
    order.push(u);
    
}

void dfs2(int u) {
    
    if (vist[u]) return;
    vist[u] = 1;
    comps[scc].push_back(u);

    for (int v : Radj[u]) dfs2(v);
    
}

void solve() {
    
    cin >> n >> m;
    
    for (int i = 1, a, b; i <= m; i++) {
        
        cin >> a >> b;
        adj[a].push_back(b);
        Radj[b].push_back(a);
        
    }
    
    fill(vist + 1, vist + n + 1, false);
    
    forlr(i, 1, n) {
        
        if (!vist[i]) dfs1(i);
        
    }
    
    fill(vist + 1, vist + n + 1, false);
    
    while (order.size()) {
        
        int v = order.top(); order.pop();
        if (!vist[v]) {
            
            scc++;
            dfs2(v);
            
        }
        
    }
    
    cout << scc << endl;
    forlr(i, 1, scc) {
        
        cout << comps[i].size() << " ";
        for (int u : comps[i]) cout << u << " "; cout << endl;
        
    }

}
