int pre[3][2 * N][N];
//1: slope: x + y
//2: slope: y - x + m;
int g[N][N];

int getRect(int x1, int y1, int x2, int y2) {
	
	if (x1 > x2 || x2 <= 0) return 0;
	return pre[0][x2][y2] - pre[0][x1 - 1][y2] - pre[0][x2][y1 - 1] + pre[0][x1 - 1][y1 - 1];
	
}

//type are clock-wise


int getTria(int x, int y, int d, int type) {
	
	if (type == 1) {
		
		int x1 = x + d, y1 = y;
		int x2 = x, y2 = y + d;
		int slope = x1 + y1;
		if (slope < 2 || slope > n + m) return getRect(x, y, n, m);
		return pre[1][slope][min(y2, m)]- pre[1][slope][y1 - 1] - getRect(1, y1, x - 1, min(m, y2));
		
	}
	
	if (type == 2) {
		
		int x1 = x, y1 = y - d;
		int x2 = x + d, y2 = y;
		int slope = y1 - x1 + n;
		if (slope < 1 || slope >= n + m) return getRect(x, 1, n, y);
		return pre[2][slope][y2] - pre[2][slope][max(1ll, y1) - 1] - getRect(1, max(1ll, y1), x - 1, y2);
		
	}
	
	if (type == 3) {
		
		int x1 = x, y1 = y - d;
		int x2 = x - d, y2 = y;
		int slope = x1 + y1;
		if (slope < 2 || slope > n + m) return getRect(1, 1, x, y);
		return getRect(1, max(1ll, y1), x, y) - (pre[1][slope - 1][y2] - pre[1][slope - 1][max(1ll, y1) - 1]);
		
	}
	
	if (type == 4) {
		
		int x1 = x - d, y1 = y;
		int x2 = x, y2 = y + d;
		int slope = y1 - x1 + n;
		if (slope < 1 || slope >= n + m) return getRect(1, y, x, m);
		return getRect(1, y1, x, min(m, y2)) - (pre[2][slope + 1][min(m, y2)] - pre[2][slope + 1][y1 - 1]);
		
	}
	
	return 0;
	
}
