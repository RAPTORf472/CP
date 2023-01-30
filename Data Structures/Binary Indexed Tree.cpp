struct BIT {
    
    int bit1[N], bit2[N];
    int n;
    
    BIT() {
        
        memset(bit1, 0, sizeof bit1);
        memset(bit2, 0, sizeof bit2);
        
    }
    
    BIT(int n) : BIT() {
        
        this -> n = n;
        
    }
    
    void update(int *b, int u, int val) {
        
        int id = u; 
        
        while (id <= n) {
            
            b[id] += val;
            id += (id & (-id));
            
        }
        
    }
    
    void update(int *b, int u, int v, int val) {
        
        update(b, u, val);
        update(b, v + 1, -val);
    
    }
    
    void add(int l, int r, int val) {
        
        update(bit1, l, (n - l + 1) * val);
        update(bit1, r + 1, -(n - r) * val);
        update(bit2, l, val);
        update(bit2, r + 1, -val);
    
    }
    
    void add(int u, int val) {
        
        add(u, u, val);
        
    }
    
    int get(int *b, int r) {
        
        int id = r, ans = 0;
        
        while (id > 0) {
            
            ans += b[id];
            id -= (id & (-id));
            
        }
        
        return ans;
        
    }
    
    int getSum(int u) {
        
        return get(bit1, u) - get(bit2, u) * (n - u);
        
    }
    
    int get(int l, int r) {
        
        return getSum(r) - getSum(l-1);
        
    }
    
    int get(int u) {
        
        return get(u, u);
        
    }
    
};
