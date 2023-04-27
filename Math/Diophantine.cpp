int gcd(int a, int b, int &x, int &y) {
    
    if (b == 0) {
        
        x = 1, y = 0;
        return a;
        
    }
    
    int x1, y1;
    
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    
    return d;
    
}

ii diophantine(int a, int b, int c) {
    
    if (a == 0 && b == 0 && c == 0) return {INF, INF};
    
    int x0, y0;
    
    int d = gcd(a, b, x0, y0);
    if (d == 0 || c % d) return {-INF, -INF};
    
    x0 *= c / d;
    y0 *= c / d;
    
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    
    return {x0, y0};
    
}
