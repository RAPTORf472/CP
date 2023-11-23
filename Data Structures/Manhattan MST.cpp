struct Point {
	
	int x, y;
	
} P[N];

struct BIT {
	
	ii bit[N];
	
	void init(int n) {
		
		fill(bit + 1, bit + n + 10, make_pair(INF, -1));
		
	}
	
	void add(int u, ii val) {
		
		for (int idx = u; idx < N; idx += idx & -idx)
			bit[idx] = min(bit[idx], val);
		
	}
	
	ii get(int u) {
		
		ii res = {INF, -1};
			
		for (int idx = u; idx > 0; idx -= idx & -idx)
			res = min(res, bit[idx]);
			
		return res;
		
	}
	
} bit;

int dist(int a, int b) {
	
	return abs(P[a].x - P[b].x) + abs(P[a].y - P[b].y);
	
}

struct Compress {
	
	vector<int> Idx;
	
	void init() {
		
		Idx.clear();
		
	}
	
	void add(int x) {
		
		Idx.push_back(x);
		
	}
	
	void compress() {
		
		SUnique(Idx);
		
	}
	
	int id(int x) {
		
		return upper_bound(all(Idx), x) - Idx.begin();
		
	}
	
} Idx;

struct Item {
	
	int num1, num2, cost, idx;
	bool operator < (Item &other) {
		
		pair<ii, ii> p1 = {{num1, num2}, {cost, idx}};
		pair<ii, ii> p2 = {{other.num1, other.num2}, {other.cost, other.idx}};
		return p1 < p2;
		
	}
	
};

struct Edge {
	
	int u, v, w;
	
	bool operator < (Edge &other) {
		
		return w < other.w;
		
	}
	
};

vector<Edge> edges;

void addEdge(int a1, int a2, int b1, int b2, int c1, int c2) {
	
	vector<Item> v;
	Idx.init();
	
	forlr(i, 1, n) {
		
		v.push_back({
            a1 * P[i].x + a2 * P[i].y,
            b1 * P[i].x + b2 * P[i].y,
            c1 * P[i].x + c2 * P[i].y,
            i
        });
        
        Idx.add(b1 * P[i].x + b2 * P[i].y);
		
	}
		
	Idx.compress();
	sort(all(v));
	bit.init(n);
		
	for (auto [num1, num2, cost, idx]: v) {
		
        num2 = Idx.id(num2);

        auto [val, res] = bit.get(num2);
        if (res != -1) edges.push_back({res, idx, dist(res, idx)});

        bit.add(num2, {cost, idx});
        
    }
	
}


struct DSU {
	
	int dsu[N], sz[N];
	
	void init(int n) {
		
		iota(dsu + 1, dsu + n + 1, 1);
		fill(sz + 1, sz + n + 1, 1);
		
	}
	
	int findSet(int a) {
		
		return (a == dsu[a]) ? a : dsu[a] = findSet(dsu[a]);
		
	}
	
	bool joinSet(int a, int b) {
		
		a = findSet(a), b = findSet(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		dsu[b] = a;
		return true;
		
	}
	
} dsu;

void manhattanMST() {
	
	  addEdge(1, -1, -1, 0, 1, 1); 
    addEdge(-1, 1, 0, -1, 1, 1); 
    addEdge(-1, -1, 0, 1, 1, -1); 
    addEdge(1, 1, -1, 0, 1, -1); 
    addEdge(-1, 1, 1, 0, -1, -1);
    addEdge(1, -1, 0, 1, -1, -1); 
    addEdge(1, 1, 0, -1, -1, 1); 
    addEdge(-1, -1, 1, 0, -1, 1); 
        
    sort(all(edges));
    dsu.init(n);
    
    for (auto [u, v, w] : edges) {
    	    	
    	if (dsu.joinSet(u, v)) {
    		
    		
    		
    	}
    	
    }
	
}
