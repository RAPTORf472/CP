struct ModInt {
	
	int x;

	ModInt() {}

	ModInt(int a) {
		
		a %= MOD;
		x = a;
		
	}
	
	void operator = (int a) {
		
		a %= MOD;
		x = a;
		
	}
	
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
	
	int invMod(int a) {
		
		return binPow(a, MOD - 2, MOD);
		
	}

	int operator * (int a) {
		
		a %= MOD;
		return (x * a) % MOD;
		
	}
	
	void operator *= (int a) {
		
		x = (x * a) % MOD;
		
	}
	
	int operator % (int a) {
		
		return x % a;
		
	}
	
	void operator %= (int a) {
		
		x %= a;
		
	}
	
	int operator / (int a) {
		
		return x / a;
		
	}
	
	void operator /= (int a) {
		
		x = x / a;
		
	}
	
	int divMod(int a) {
		
		return (x * invMod(a) % MOD);
		
	}
	
	int operator + (int a) {
		
		return ((x + a) % MOD + MOD) % MOD;
		
	}
	
	void operator += (int a) {
		
		x = (x + a) % MOD;
		
	}
	
	int operator - (int a) {
		
		return ((x - a) % MOD + MOD) % MOD;
		
	}
	
	void operator -= (int a) {
		
		x = ((x - a) % MOD + MOD) % MOD;

	}
	
	int operator * (ModInt a) {
		
		return (x * a.x) % MOD;
		
	}
	
	void operator *= (ModInt a) {
		
		x = (x * a.x) % MOD;
		
	}
	
	int operator % (ModInt a) {
		
		return x % a.x;
		
	}
	
	void operator %= (ModInt a) {
		
		x %= a.x;
		
	}
	
	int operator / (ModInt a) {
		
		return x / a.x;
		
	}
	
	void operator /= (ModInt a) {
		
		x = x / a.x;
		
	}
	
	int divMod(ModInt a) {
		
		return (x * invMod(a.x) % MOD);
		
	}
	
	int operator + (ModInt a) {
		
		return ((x + a.x) % MOD + MOD) % MOD;
		
	}
	
	void operator += (ModInt a) {
		
		x = (x + a.x) % MOD;
		
	}
	
	int operator - (ModInt a) {
		
		return ((x - a.x) % MOD + MOD) % MOD;
		
	}
	
	void operator -= (ModInt a) {
		
		x = ((x - a.x) % MOD + MOD) % MOD;

	}
	
	bool operator == (ModInt a) {
		
		return x == a.x;
		
	}
	
	bool operator < (ModInt a) {
		
		return x < a.x;
		
	}
	
	bool operator > (ModInt a) {
		
		return x > a.x;
		
	}
	
	bool operator == (int a) {
		
		return x == a;
		
	}
	
	bool operator < (int a) {
		
		return x < a;
		
	}
	
	bool operator > (int a) {
		
		return x > a;
		
	}
	
	friend void operator >> (istream& os, ModInt &x) {
		
		os >> x.x;
		
	}
	
	friend ostream& operator << (ostream &os, ModInt x) {
		
		os << x.x;
		return os;
		
	}
	
};
