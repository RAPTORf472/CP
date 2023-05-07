int f(int n, int x, int c) {
    
    return (modMul(x, x, n) + c) % n;
    
}

int pollardRho(int n, int x0 = 2, int c = 1) {
    
    vector<int> pfac = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    for (int p : pfac) {
        
        if (n % p == 0) return p;
        
    }
    
    x0 = rand() % 10 + 1, c = rand() % 10 + 1;
    
    if (millerRabin(n)) return n;
    
    int g = 1;
    
    int x = x0, y = x0;
    
    while (g == 1) {
        
        x = f(n, x, c);
        y = f(n, y, c);
        y = f(n, y, c);
        g = __gcd(abs(x - y), n);
        
    }
    
    if (g == n) return pollardRho(n, rand() % 10 + 1, rand() % 10 + 1);
    
    return g;
    
}
