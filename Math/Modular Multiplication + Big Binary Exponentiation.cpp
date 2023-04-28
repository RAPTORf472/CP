
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

int bigBinPow(int a, int b, int m) {
    
    a %= m;
    
    int prod = 1;
    
    while (b) {
        
        if (b & 1) prod = modMul(prod, a, m);
        a = modMul(a, a, m);
        b /= 2;
        
    }
    
    return prod;
    
}
