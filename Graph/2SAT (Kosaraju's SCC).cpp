int n, m, q, k;
vector<int> adj[2 * N], Radj[2 * N];
int scc;

stack<int> order;
int sccID[2 * N];
bool vist[2 * N];
int res[2 * N];

void dfs1(int u) {
    
    if (vist[u]) return;
    vist[u] = true;
    
    for (int v : adj[u]) dfs1(v);
    
    order.push(u);
    
}

void dfs2(int u) {
    
    if (vist[u]) return;
    vist[u] = true;
    sccID[u] = scc;
    
    for (int v : Radj[u]) dfs2(v);
    
}

int id1(int x) {
    
    if (x > 0) return x * 2;
    return -x * 2 + 1;
    
}

int id2(int x) {
    
    return id1(-x);
    
}

void solve() {
    
    string s; cin >> s >> s >> n >> m;
    
    int a, b, c;
    
    forlr(i, 1, m) {
        
        cin >> a >> b >> c;
        adj[id2(a)].push_back(id1(b));
        adj[id2(b)].push_back(id1(a));
        Radj[id1(b)].push_back(id2(a));
        Radj[id1(a)].push_back(id2(b));
        
    }
    
    fill(vist + 1, vist + 2 * n + 2, false);
    
    forlr(i, 1, 2 * n + 1) {
        
        if (!vist[i]) dfs1(i);
        
    }
    
    fill(vist + 1, vist + 2 * n + 2, false);
    
    while (order.size()) {
        
        int u = order.top(); order.pop();
        if (!vist[u]) {
            
            scc++;
            dfs2(u);
            
        }
        
    }
    
    forlr(i, 1, n) {
        
        if (sccID[i * 2] == sccID[i * 2 + 1]) {
            
            cout << "s UNSATISFIABLE" << endl;
            return;
            
        }
        
        res[i] = sccID[i * 2] > sccID[i * 2 + 1];
        
    }
    
    cout << "s SATISFIABLE" << endl;
    cout << "v ";
    forlr(i, 1, n) {

        cout << (res[i] ? i : -i) << " ";

    }
    
    cout << 0 << endl;

}
