void pruefer_decode(vector<ii> &edges, vector<int> &code) {
    
    int sz = code.size() + 2;
    vector<int> degree(sz, 1);
    for (int i : code) degree[i]++;

    int ptr = 0;
    
    while (degree[ptr] != 1)
        ptr++;
        
    int leaf = ptr;

    for (int v : code) {
        edges.push_back({leaf + 1, v + 1});
        
        if (--degree[v] == 1 && v < ptr) {
            
            leaf = v;
            
        } else {
            
            ptr++;
            while (degree[ptr] != 1) ptr++;
            leaf = ptr;
            
        }
    }
    
    edges.push_back({leaf + 1, sz});

}
