//Suffix Array

namespace SuffixArray {
    
    int sa[N], pos[N], tmp[N], lcp[N];
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
    
    void init(string str) {
        
        s = str;
        sz = str.size();
        buildSA();
        
    }
    
}
