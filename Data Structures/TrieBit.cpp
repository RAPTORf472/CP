struct TrieBit {
    
    static const int S = 32;
    int cnt = 0;

    struct TrieNode {
        
        int nxt[2];
        int cnt = 0, End = 0;
        
    };
    
    vector<TrieNode> trie;
    
    TrieBit() {
        
        trie.emplace_back();
           
    }

    void insert(int x) {
        
        bitset<S> s(x);
        cnt++;
        
        int pos = 0;
        
        forrl(i, S - 1, 0) {
            
            int id = s[i];
            if (!trie[pos].nxt[id]) {
                
                trie[pos].nxt[id] = trie.size();
                trie.emplace_back();
                
            }
            
            pos = trie[pos].nxt[id];
            trie[pos].cnt++;
            
        }
        
        trie[pos].End++;
        
    }
    
    int count(int x) {
        
        bitset<S> s(x);
        
        int pos = 0;
        
        forrl(i, S - 1, 0) {
            
            int id = s[i];
            if (!trie[pos].nxt[id]) return 0;
            pos = trie[pos].nxt[id];
            
        }
        
        return trie[pos].End;
        
    }
    
    bool erase(int x) {
        
        bitset<S> s(x);
        
        int pos = 0;
        
        forrl(i, S - 1, 0) {
            
            int id = s[i];
            if (!trie[pos].nxt[id]) return 0;
            
            int tmp = pos;
            pos = trie[pos].nxt[id];
            trie[pos].cnt--;
            if (trie[pos].cnt == 0) trie[tmp].nxt[id] = 0; 
            
        }
        
        trie[pos].End--;
        
        return true;
        
    }
    
    int maxXor(int x) {
        
        if (cnt == 0) return 0;
        
        bitset<S> s(x);
        int res = 0, pos = 0;
        
        forrl(i, S - 1, 0) {
            
            int id = s[i];
            bool found = false;
            if (trie[pos].nxt[!id]) pos = trie[pos].nxt[!id], found = 1;
            else pos = trie[pos].nxt[id];

            res += (1 << i) * (id ^ found);

        }
        
        return res;
        
    }
    
} tb;
