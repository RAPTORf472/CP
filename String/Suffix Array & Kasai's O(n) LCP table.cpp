//Suffix Array & LCP (Kasai's O(N) LCP table)

namespace SuffixArray {
    
    int sa[N], pos[N], tmp[N], lcp[N], st[N][LOG];
    int gap, sz;
    string s;
    
    bool sufCmp(int i, int j) {
        
        if (pos[i] != pos[j]) return pos[i] < pos[j];
        i += gap, j += gap;
        return (i < sz && j < sz) ? pos[i] < pos[j] : i > j;
        
    }
    
    void buildSA() {
        
        for (int i = 0; i < sz; i++) sa[i] = i, pos[i] = s[i];
        for (gap = 1; tmp[sz - 1] != sz - 1; gap *= 2) {
            
            sort(sa, sa + sz, sufCmp);
            for (int i = 0; i < sz - 1; i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            for (int i = 0; i < sz; i++) pos[sa[i]] = tmp[i];
            
        }
        
    }
    
    void buildLCP() {
        
        for (int i = 0, k = 0; i < sz; i++) {
            
            if (pos[i] != sz - 1) {
                
                for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k]; k++);
                lcp[pos[i]] = k;
                if (k) k--;
                
            }
            
        }
        
    }
    
    void initRMQ() {
        
        for (int i = 0; i < sz; i++) st[i][0] = lcp[i];
        
        for (int i = 1; i < LOG; i++) {
            
            for (int j = 0; j + (1 << i) - 1 < sz; j++) {
                
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
                
            }
            
        }
        
    }
    
    int getLCP(int i, int j) {
        
        i = pos[i], j = pos[j];
        if (i > j) swap(i, j);
        j--;
        int lg = __lg(j - i + 1);
        return min(st[i][lg], st[j - (1 << lg) + 1][lg]);
        
    }
    
    void initSA(string str) {
        
        s = str;
        sz = str.size();
        buildSA();
        buildLCP();
        initRMQ();

    }
    
}

using namespace SuffixArray;
