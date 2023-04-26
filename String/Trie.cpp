#include <bits/stdc++.h>

using namespace std;

struct Trie {
    
    static const int S = 26;
    char base = 'a';
    
    struct TrieNode {
        
        int nxt[S], cnt = 0, End = 0;
        
    };
    
    vector<TrieNode> trie;
    
    Trie() {trie.emplace_back();}
    
    void setBase(char c) {base = c;}
    
    void insert(string s) {
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            int id = s[i] - base;
            
            if (!trie[pos].nxt[id]) {
                
                trie[pos].nxt[id] = trie.size();
                trie.emplace_back();
                
            }
            
            pos = trie[pos].nxt[id];
            
        }
        
        trie[pos].End++;
        
    }
    
    int count (string s) {
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            int id = s[i] - base;
            
            if (!trie[pos].nxt[id]) return 0;
            pos = trie[pos].nxt[id];
            
        }
        
        return trie[pos].End;
        
    }
    
    bool erase(string s) {
        
        int pos = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            int id = s[i] - base;
            
            if (!trie[pos].nxt[id]) return false;
            pos = trie[pos].nxt[id];
            
        }
        
        trie[pos].End--;
        
        return true;
        
    }
    
} trie;


signed main() {
        
    trie.insert("abcd");
    
    cout << trie.count("abcd") << endl;
    
}
