const int S = 26;
 
int occ[N];
 
struct Trie {
    
    char base = 'a';
    
    struct Node {
        
        int nxt[S];
        char pch;
        int p = -1, exit = -1, link = -1, exitLink = -1;
 
        Node(int p = -1, char ch = '$') : p(p), pch(ch) {
            
            memset(nxt, -1, sizeof nxt);
            
        }
        
    };
    
    vector<Node> trie;
    Trie() {trie.emplace_back(0);}
 
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
        
        trie[pos].exit = idx;
        
    }
 
    int getLink(int u) {
        
        if (trie[u].link == -1) {
            
            if (u == 0 || trie[u].p == 0) trie[u].link = 0;
            else trie[u].link = go(getLink(trie[u].p), trie[u].pch);
            
            int back = trie[u].link;
            getLink(back);
            
            if (trie[back].exit != -1) trie[u].exitLink = back;
            else trie[u].exitLink = trie[back].exitLink;

        }
        
        return trie[u].link;
        
    }
 
    int go(int u, char c) {
        
        int id = c - base;
        
        if (trie[u].nxt[id] == -1) {
            
            if (u == 0) trie[u].nxt[id] = 0;
            else trie[u].nxt[id] = go(getLink(u), c);

        }
        
        return trie[u].nxt[id];
        
    }
 
    void findString(string &s) {
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            pos = go(pos, s[i]);
            getLink(pos);
            int cur = (trie[pos].exit == -1) ? trie[pos].exitLink : pos;
            
            while (cur != -1) {
                
                if (occ[trie[cur].exit] == -1) occ[trie[cur].exit] = i;
                cur = trie[cur].exitLink;
                
            }
            
        }
        
    }
    
};
