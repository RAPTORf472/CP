struct Hash {
    
    const static int S = 1e3 + 100;
    
    int Base1 = 31, Base2 = 311;
    int Mod1 = 1e9 + 9, Mod2 = 1e9 + 31;
    int sz = 0;
    
    
    int Hash1[S], Hash2[S], powBase1[S], powBase2[S];
    
    Hash() {
        
        powBase1[0] = powBase2[0] = 1;
        
        for (int i = 1; i < S; i++) {
            
            powBase1[i] = (powBase1[i-1] * Base1) % Mod1;
            powBase2[i] = (powBase2[i-1] * Base2) % Mod2;
            
        }
        
    }
    
    Hash(string &s) : Hash() {
        
        hash(s);
        
    }
    
    void hash(string &s) {
        
        sz = s.size();
        for (int i = 1; i <= sz; i++) {
            
            Hash1[i] = (Hash1[i-1] * Base1 + (s[i-1] - 'a' + 1)) % Mod1;
            Hash2[i] = (Hash2[i-1] * Base2 + (s[i-1] - 'a' + 1)) % Mod2;
            
        }
        
    } 
    
    int get1(int l, int r) {
        
        return (Hash1[r] - Hash1[l-1] * powBase1[r-l+1] + sqr(Mod1)) % Mod1;
        
    }
    
    int get2(int l, int r) {
        
        return (Hash2[r] - Hash2[l-1] * powBase2[r-l+1] + sqr(Mod2)) % Mod2;
        
    }
    
    ii get(int l, int r) {
        
        return {get1(l, r), get2(l, r)};
        
    }
    
    ii get() {
        
        return get(1, sz);
        
    }
    
};
