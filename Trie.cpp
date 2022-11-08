#include <bits/stdc++.h>

using namespace std;

const int S = 26;
struct Trie {
    struct TrieNode {
        int nxt[S], cnt, idx, app;
    
        TrieNode() {
            for(int i = 0; i < S; i++) nxt[i] = 0;
            cnt = idx = app = 0;
        }
    };

    vector<TrieNode> trie;

    Trie() {
        trie.emplace_back();
    }

    void insert(string val) {
        int pos = 0;
        for(int b = 0; b < val.size(); b++) {
            int id = val[b] - 'a';
            if(!trie[pos].nxt[id]) {
                trie[pos].nxt[id] = trie.size();
                trie.emplace_back();
            }
    
            pos = trie[pos].nxt[id];
            trie[pos].cnt++;
        }
        trie[pos].app++;
    }

    int count(string val) {
        int pos = 0;
        for(int b = 0; b < val.size(); b++) {
            int id = val[b] - 'a';
            if(!trie[pos].nxt[id]) return 0;
            pos = trie[pos].nxt[id];
        }
        return trie[pos].app;
    }

    int erase(string val, int t) {
        int c = count(val);
        if(c == 0) return 0;
        t = min(t, c);

        int pos = 0;
        for(int b = 0; b < val.size(); b++) {
            int id = val[b] - 'a';
            pos = trie[pos].nxt[id];
            trie[pos].cnt -= t;
        }
        trie[pos].app -= t;

        return t;
    }
};

signed main() {
    
    Trie trie;
    
    trie.insert("abcd");
    
    cout << trie.count("abcd") << endl;
    
}
