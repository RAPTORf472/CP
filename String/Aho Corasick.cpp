const int S = 26;
 
int occ[N];
 
struct Trie {
    
    char base = 'a';
    
    struct Node {
        
        int nxt[S];
        int leaf = -1;
        int p = -1;
        char pch;
        int link = -1, leaflink = -1;
 
        Node(int p = -1, char ch = '$') : p(p), pch(ch) {
            
            memset(nxt, -1, sizeof nxt);
            
        }
        
    };
    
    vector<Node> trie;
    Trie() : trie(1) {}
 
    void insert(string &s, int idx) {
        
        int pos = 0;
        
        for (char c : s) {
            
            int id = c - base;
            
            if (trie[pos].nxt[id] == -1 || trie[pos].nxt[id] == trie[pos].link) {
                
                trie[pos].nxt[id] = trie.size();
                trie.emplace_back(pos, c);
                
            }
            
            pos = trie[pos].nxt[id];
            
        }
        
        trie[pos].leaf = idx;
        
    }
 
    int getLink(int u) {
        
        if (trie[u].link == -1) {
            
            if (u == 0 || trie[u].p == 0) trie[u].link = 0;
            else trie[u].link = go(getLink(trie[u].p), trie[u].pch);
            
            getLink(trie[u].link);
            trie[u].leaflink = (trie[trie[u].link].leaf != -1) ? trie[u].link : trie[trie[u].link].leaflink;
            
        }
        
        return trie[u].link;
        
    }
 
    int go(int u, char c) {
        
        int id = c - base;
        
        if (trie[u].nxt[id] == -1) {
            
            trie[u].nxt[id] = (u == 0) ? 0 : go(getLink(u), c);
                
        }
        
        return trie[u].nxt[id];
        
    }
 
    void findString(string &s) {
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            pos = go(pos, s[i]);
            getLink(pos);
            int cur = (trie[pos].leaf == -1) ? trie[pos].leaflink : pos;
            
            while (cur != -1) {
                
                if (occ[trie[cur].leaf] == -1) occ[trie[cur].leaf] = i;
                cur = trie[cur].leaflink;
                
            }
            
        }
        
    }
    
};
