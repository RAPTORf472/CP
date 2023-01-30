int pre[N];

void preFunc(string &s) {
    
    int sz = s.size();
    
    for(int i = 1; i < sz; i++) {
        
        int j = pre[i - 1];
        while(j > 0 && s[i] != s[j]) j = pre[j - 1];
        if(s[i] == s[j]) j++;
        
        pre[i] = j;
        
    }

}
