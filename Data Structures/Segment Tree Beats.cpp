
struct SegmentTreeBeats {
	
	struct Node {
		
		int sum, lazy;
		int min1, min2, minc;
		
	} seg[4 * N];
	
	void merge(int id) {
		
		seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
		seg[id].min1 = min(seg[id * 2].min1, seg[id * 2 + 1].min1);
		
		if (seg[id * 2].min1 == seg[id * 2 + 1].min1) {
			
 			seg[id].minc = seg[id * 2].minc + seg[id * 2 + 1].minc;
 			seg[id].min2 = min(seg[id * 2].min2, seg[id * 2 + 1].min2);
			
		} else if (seg[id * 2].min1 < seg[id * 2 + 1].min1) {
			
			seg[id].minc = seg[id * 2 + 1].minc;
			seg[id].min2 = min(seg[id * 2].min1, seg[id * 2 + 1].min2);
			
		} else {
			
			seg[id].minc = seg[id * 2].minc;
			seg[id].min2 = min(seg[id * 2 + 1].min1, seg[id * 2].min2);
			
		}
		
	}
	
	void build(int id, int l, int r) {
		
		if (l == r) {
			
			seg[id] = {arr[l], 0, arr[l], LINF, 1};
			return;
			
		}
		
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		
		merge(id);
		
	}
	
	void pushAdd(int id, int l, int r, int val) {
		
		if (!val) return;
		
		seg[id].sum += val * (r - l + 1);
		seg[id].lazy += val;
		seg[id].min1 += val;
		if (seg[id].min2 != LINF) seg[id].min2 += val;
		
	}
	
	void pushMax(int id, int val) {
		
		if (val <= seg[id].min1) return;
		int &min1 = seg[id].min1;
		seg[id].sum -= min1 * seg[id].minc;
		min1 = val;
		seg[id].sum += min1 * seg[id].minc;
		
	}
	
	void push(int id, int l, int r) {
		
		//sum
		
		int &lazy = seg[id].lazy, min1 = seg[id].min1;
		int mid = (l + r) / 2;
		
		pushAdd(id * 2, l, mid, lazy);
		pushAdd(id * 2 + 1, mid + 1, r, lazy);
		lazy = 0;
		
		//max
		
		pushMax(id * 2, min1);
		pushMax(id * 2 + 1, min1);
				
	}
	
	void updateAdd(int id, int l, int r, int u, int v, int val) {
		
		if (v < l || r < u) return;
		if (u <= l && r <= v) {
			
			pushAdd(id, l, r, val);
			return;
			
		}
		
		push(id, l, r);
		int mid = (l + r) / 2;
		
		updateAdd(id * 2, l, mid, u, v, val);
		updateAdd(id * 2 + 1, mid + 1, r, u, v, val);
		
		merge(id);
		
	}
	
	void updateAdd(int l, int r, int val) {
		
		updateAdd(1, 1, n, l, r, val);
		
	}
	
	void updateMax(int id, int l, int r, int u, int v, int val) {
		
		if (v < l || r < u || val <= seg[id].min1) return;
		if (u <= l && r <= v && val < seg[id].min2) {
			
			pushMax(id, val);
			return;
			
		}
		
		push(id, l, r);
		int mid = (l + r) / 2;
		
		updateMax(id * 2, l, mid, u, v, val);
		updateMax(id * 2 + 1, mid + 1, r, u, v, val);
		
		merge(id);
		
	}
	
	void updateMax(int l, int r, int val) {
		
		updateMax(1, 1, n, l, r, val);
		
	}
	
	int get(int id, int l, int r, int u, int v) {
		
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return seg[id].sum;
		
		push(id, l, r);
		int mid = (l + r) / 2;
		
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
		
	}
	
	int get(int l, int r) {
		
		return get(1, 1, n, l, r);
		
	}
	
	int get(int x) {
		
		return get(x, x);
		
	}
	
} st;
