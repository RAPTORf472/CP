const int N = 1e5 + 100;
const int INF = 1e9;

bool vist[N];
ii minEdge[N];
int adj[N][N];

//recommended on a complete graph

pair<int, vector<int>> primN2() {
    
    vector<int> mst;
    memset(vist, 0, sizeof vist);
    for (int i = 1; i <= n; i++) minEdge[i] = {INF, -1};
    
    int res = 0;
    minEdge[1].fs = 0;

    for (int i = 1; i <= n; i++) {
        
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!vist[j] && (u == -1 || minEdge[j].fs < minEdge[u].fs))
                u = j;
        }

        if (minEdge[u].fs == INF) {
            
            return {-1, mst};
            
        }

        vist[u] = true;
        res += minEdge[u].fs;
        mst.push_back(minEdge[u].fs);
        
        // modify to return a spanning tree
        // if (minEdge[u].sc != -1)
        //     cout << u << " " << minEdge[u].sc << endl;

        for (int to = 1; to <= n; to++) {

            if (adj[u][to] < minEdge[to].fs)
                minEdge[to] = {adj[u][to], u};

        }

    }

    sort(mst.begin(), mst.end());

    return {res, mst};
}
