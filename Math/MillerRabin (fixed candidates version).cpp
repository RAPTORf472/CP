int modMul(int a, int b, int m) {
    
    a %= m;
    int res = 0;
    
    while (b) {
        
        if (b & 1) res = (res + a) % m;
        a = (2 * a) % m;
        b /= 2;
        
    }
    
    return res;
    
}

int binPowMod(int a, int b, int m) {
    
    a %= m;
    
    int prod = 1;
    
    while (b) {
        
        if (b & 1) prod = modMul(prod, a, m);
        a = modMul(a, a, m);
        b /= 2;
        
    }
    
    return prod;
    
}

bool checkMillerRabin(int x, int mod, int s, int k) {
    
    x = binPowMod(x, s, mod);
    if (x == 1) return true;
    
    while(k--) {
        
        if (x == mod - 1) return true;
        x = modMul(x, x, mod);
        if (x == 1) return false;
        
    }
    
    return false;
    
}

bool millerRabin(int x) {
    
    if (x == 2 || x == 3 || x == 5 || x == 7) return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;
    if (x < 121) return x > 1;

    int s = x - 1;
    int k = 0;
    
    while (s % 2 == 0) {
        s /= 2;
        k++;
    }
    
    vector<int> pfac32 = {2, 7, 61};
    vector<int> pfac64 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    if (x < (1ll << 32)) {
        
        for (int z : pfac32) {
        
            if (!checkMillerRabin(z, x, s, k)) return false;
            
        }
        
    } else {
     
        for (int z : pfac64) {
            
            if (!checkMillerRabin(z, x, s, k)) return false;
            
        }
    
    }
    
    return true;
    
}
