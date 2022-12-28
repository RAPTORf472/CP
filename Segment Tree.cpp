//warning: cause segmentation fault when N ~ 2e5

const int N = 1e5 + 100;

struct SegmentTree {
    
    int n;
    int *a;
    
    struct Node {
        
        int val;
        int lazy;
        
    } seg[4 * N];
    
    SegmentTree() {}
    
    SegmentTree(int n, int *a) : n(n) {
        
        this -> a = a;
        build(1, 1, n);
        
    }
    
    void setData(int *a) {
        
        this -> a = a;
        
    }
    
    void setData(int n) {
        
        this -> n = n;
        
    }
    
    void setData(int *a, int n) {
        
        this -> n = n;
        
    }
    
    void init() {
        
        build(1, 1, n);
        
    }
    
    void build(int id, int l, int r) {
        
        if (l == r) {
            
            seg[id].val = a[l];
            return;
        }
        
        int mid = (l+r) / 2;
        
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        
        seg[id].val = max(seg[id*2].val, seg[id*2+1].val);
    }
    
    void push(int id) {
        
        seg[id*2].lazy += seg[id].lazy;
        seg[id*2].val += seg[id].lazy;
        
        seg[id*2+1].lazy += seg[id].lazy;
        seg[id*2+1].val += seg[id].lazy;
        
        seg[id].lazy = 0;
        
    }
    
    void update(int id, int l, int r, int u, int v, int add) {
        
        if (v < l || r < u) return;
        
        if (u <= l && r <= v) {
            
            seg[id].val += add;
            seg[id].lazy += add;
            return;
            
        }
        
        push(id);
        int mid = (l+r) / 2;
        
        update(id*2, l, mid, u, v, add);
        update(id*2+1, mid+1, r, u, v, add);
        
        seg[id].val = max(seg[id*2].val, seg[id*2+1].val);
        
    }
    
    void update(int l, int r, int val) {
        
        update(1, 1, n, l, r, val);
        
    }
    
    void update(int u, int val) {
        
        update(1, 1, n, u, u, val);
        
    }
    
    int query(int id, int l, int r, int u, int v) {
        
        if (v < l || r < u) return -1e17;
        
        if (u <= l && r <= v) {
            
            return seg[id].val;
            
        }
        
        push(id);
        int mid = (l+r) / 2;
        
        return max(query(id*2, l, mid, u, v),
                   query(id*2+1, mid+1, r, u, v));
                   
    }
    
    int query(int l, int r) {
        
        return query(1, 1, n, l, r);
        
    }
    
    int query(int u) {
        
        return query(u, u);
        
    }
    
};
