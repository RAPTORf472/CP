struct DynamicSegmentTree {
	
	int nCnt;
	int LIM = INF;
	
	struct Node {
		
		int L, R;
		int val;
		
	} seg[4 * N];
	
	DynamicSegmentTree() {
		
		nCnt = 1;
		
	}
	
	void update(int id, int l, int r, int u, int val) {
		
		if (u < l || r < u) return;
		if (l == r) {
			
			seg[id].val += val;
			return;
			
		}
		
		int mid = (l + r) / 2;
		int &L = seg[id].L, &R = seg[id].R;
		
		if (!L) L = ++nCnt;
		if (!R) R = ++nCnt;
		update(L, l, mid, u, val);
		update(R, mid + 1, r, u, val);
		
		seg[id].val = 0;
		if (L) seg[id].val += seg[L].val;
		if (R) seg[id].val += seg[R].val;
				
	}
	
	void update(int u, int val) {
		
		update(1, 1, LIM, u, val);
		
	}
	
	int get(int id, int l, int r, int u, int v) {
		
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return seg[id].val;
				
		int mid = (l + r) / 2;
		
		int res = 0;
		if (seg[id].L) res += get(seg[id].L, l, mid, u, v);
		if (seg[id].R) res += get(seg[id].R, mid + 1, r, u, v);
		
		return res;
		
	}
	
	int get(int l, int r) {
		
		return get(1, 1, LIM, l, r);
		
	}

} st;
