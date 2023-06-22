int n, m;
vector<int> adj[2 * N];

int low[2 * N], num[2 * N], timeDfs, scc;
stack<int> order;
vector<int> comps[2 * N];
int sccID[2 * N];

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
            sccID[tmp] = scc;
            
        } while (tmp != u);
        
    }
    
}

int id1(int x) {
    
    if (x > 0) return x * 2;
    return -x * 2 + 1;
    
}

int id2(int x) {
    
    return id1(-x);
    
}

int res[N];

void solve() {
    
    string s; cin >> s >> s >> n >> m;
    
    int a, b, c;
    
    forlr(i, 1, m) {
        
        cin >> a >> b >> c;
        adj[id2(a)].push_back(id1(b));
        adj[id2(b)].push_back(id1(a));
        
    }
    
    forlr(i, 1, 2 * n) {
    
        if (!num[i]) tarjan(i);   
        
    }
    
    forlr(i, 1, n) {
        
        if (sccID[i * 2] == sccID[i * 2 + 1]) {
            
            cout << "s UNSATISFIABLE" << endl;
            return;
            
        }
        
        res[i] = sccID[i * 2] < sccID[i * 2 + 1];
        
    }
    
    cout << "s SATISFIABLE" << endl;
    cout << "v ";
    
    forlr(i, 1, n) {
        
        cout << (res[i] ? i : -i) << " ";
        
    }
    
    cout << 0 << endl;
    
}
