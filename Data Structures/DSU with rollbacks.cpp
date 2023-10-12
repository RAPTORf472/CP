struct PDSU {
	
	struct Info {
		
		int a, b, szA, szB;
		
	};
	
	int dsu[N], sz[N];
	
	stack<Info> st;
	
	void init(int n) {
		
		iota(dsu + 1, dsu + n + 1, 1);
		fill(sz + 1, sz + n + 1, 1);
		
	}
	
	//For PDSU, path compression is disabled
	
	int findSet(int a) {
		
		return (a == dsu[a]) ? a : findSet(dsu[a]);
		
	}
	
	bool joinSet(int a, int b) {
		
		a = findSet(a), b = findSet(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		st.push({a, b, sz[a], sz[b]});
		dsu[b] = a;
		sz[a] += sz[b];
		
		return true;
		
	} 
	
	void undo() {
		
		if (st.empty()) return;
		auto [a, b, sza, szb] = st.top(); st.pop();
		dsu[a] = a;
		dsu[b] = b;
		sz[a] = sza;
		sz[b] = szb;
 		
	}
	
} dsu;
