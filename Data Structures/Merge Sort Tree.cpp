
const int INF = 1e9 + 1;

int c(int a, int b) {
    
    return min(a, b);
    
}
 
template<typename T> struct mergeSortTree {
    
    vector<multiset<T>> tree;
    vector<T> mem;
 
    T dummy;
    
    T (*combine) (T a, T b);
 
    mergeSortTree(int n, vector<T> &mem, T dummy, T (*combine) (T a, T b)) {
        
        tree.resize(4 * n);
        this -> mem = mem;
        this -> dummy = dummy;
        this -> combine = combine;
        build(1, 1, n);
        
    }
    
    void build(int id, int l, int r) {
    
        if(l == r) {
            
            tree[id].insert(mem[l]);
            return;
            
        }
 
        int mid = (l + r) >> 1;
 
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
 
        multiset<T> s(tree[id * 2]);
        s.insert(tree[id * 2 + 1].begin(), tree[id * 2 + 1].end());
        tree[id] = s;
        
    }
    
    void update(int id, int l, int r, T u, T v) {
    
        if(u < l || r < u) return;
 
        tree[id].erase(tree[id].lower_bound(mem[u]));
        tree[id].insert(v);
        
        if (l == r) {
            
            mem[u] = v;
            return;
            
        }
        
        int mid = (l + r) >> 1;
 
        update(id << 1, l, mid, u, v);
        update(id << 1 | 1, mid + 1, r, u, v);
        
    }
 
    int get(int id, int l, int r, int u, int v, int k) {
        
        if(v < l || r < u) return INF;
        if(u <= l && r <= v) {
            
            auto i = tree[id].lower_bound(k);
            if (i == tree[id].end()) return INF;
            return *i;
            
        }
 
        int mid = (l + r) >> 1;
 
        return combine(get(id << 1, l, mid, u, v, k), get(id << 1 | 1, mid + 1, r, u, v, k));
    }
 
};
 
//MergeSortTree<int> mt(n, mem, dummy, combine);
