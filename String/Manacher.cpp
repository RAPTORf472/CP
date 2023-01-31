int pOdd[N], pEven[N];
int p[N];

void manacher(string &str) {
    
    string s = "";
    
    for (char c : str) {
        
        s += "#";
        s += c;
        
    }
    
    s += "#";
    
    int n = s.size();
    
    s = "$" + s + "^";
    
    int l = 1, r = 1;
    
    for(int i = 1; i <= n; i++) {
        
        p[i] = max(0ll, min(r - i, p[l + (r - i)]));
        
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    
    for (int i = 1; i <= n; i++) {
        
        if (i % 2 == 0) pOdd[i / 2] = p[i] / 2;
        else pEven[i / 2] = (p[i] - 1) / 2;
        
    }
    
}
