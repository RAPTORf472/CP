int binPow(int a, int b, int m = LLONG_MAX) {
    
    int prod = 1;
    a %= m;
    
    while (b) {
        
        if (b & 1) prod = prod * a % m;
        a = a * a % m;
        b /= 2;
        
    }
    
    return prod;
    
}

long long modInv(long long x, long long MOD) { 

    return binPow(x, MOD - 2, MOD); 

}


long long gauss(vector<vector<long long>> &a, vector<long long> &ans, long long MOD) {
	
    int n = a.size(), m = a[0].size() - 1;

    for(int i = 0; i < n; i++) {
    	
        for(int j = 0; j <= m; j++) {
        	
            a[i][j] = (a[i][j] % MOD + MOD) % MOD;
            
        }
        
    }

    vector<int> where(m, -1);
    
    for(int col = 0, row = 0; col < m && row < n; col++) {
    	
        int sel = row;
        
        for(int i = row; i < n; i++) {
        
            if(a[i][col] > a[sel][col]) sel = i;
        
        }

        if(a[sel][col] == 0) { 
        
            where[col] = -1; 
            continue;
            
        }

        where[col] = row;
        for(int i = col; i <= m; i++) swap(a[sel][i], a[row][i]);

        long long c_inv = modInv(a[row][col], MOD);
        
        for(int i = 0; i < n; i++) {
        	
            if(i != row) {
            	
                if(a[i][col] == 0) continue;
                long long c = (a[i][col] * c_inv) % MOD;
                
                for(int j = 0; j <= m; j++) {
                	
                    a[i][j] = (a[i][j] - c * a[row][j] % MOD + MOD) % MOD;
                    
                }
                
            }
            
        }

        row++;
    }

    long long result = 1;
    
    for(int i = 0; i < m; i++) {
    	
        if(where[i] != -1) ans[i] = (a[where[i]][m] * modInv(a[where[i]][i], MOD)) % MOD;
        else result++;
        
    }

    for(int i = 0; i < n; i++) {
    	
		long long sum = a[i][m] % MOD;
		
		for(int j = 0; j < m; j++) {
			
			sum = (sum + MOD - (ans[j] * a[i][j]) % MOD) % MOD;
			
        }

		if(sum != 0) return 0;
		
	}

    return result;
    
}
