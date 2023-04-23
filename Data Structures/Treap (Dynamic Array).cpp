struct Treap {
    
    Treap *L, *R;
    int w, sz;
    int val, sum;
    bool rev;
    
    Treap(int val) {
        
        L = R = 0;
        w = rng();
        sz = 1;
        this->val = val;
        sum = val;
        rev = false;
        
    }
    
};

namespace TreapUtils {
    
    int size(Treap *treap) {
        
        return treap == 0 ? 0 : treap -> sz;
        
    }
    
    int sum(Treap *treap) {
        
        return treap == 0 ? 0 : treap -> sum;
        
    }
    
    void push(Treap *cur) {
        
        if (cur && cur->rev) {
            
            cur->rev = 0;
            swap(cur->L, cur->R);
            if (cur->L) cur->L->rev ^= 1;
            if (cur->R) cur->R->rev ^= 1;
            
        }
        
    }

    void split(Treap *cur, Treap *&L, Treap *&R, int k) {
        
        if (cur == 0) L = R = 0;
        else {
            
            push(cur);
                
            if (size(cur->L) < k) {
                
                split(cur->R, cur->R, R, k - size(cur->L) - 1);
                L = cur;
                
            } else {
                
                split(cur->L, L, cur->L, k);
                R = cur;
                
            }
            
            cur->sz = size(cur->L) + size(cur->R) + 1;
            cur->sum = sum(cur->L) + sum(cur->R) + cur->val;
        
        }
        
    }

    void merge(Treap *&cur, Treap *L, Treap *R) {
        
        if (L == 0) cur = R;
        else if(R == 0) cur = L;
        else {
            
            push(L);
            push(R);
            
            if (L->w < R->w) {
                
                merge(L->R, L->R, R);
                cur = L;
                
            } else {
                
                merge(R->L, L, R->L);
                cur = R;
                
            }   
            
            cur->sum = sum(cur->L) + sum(cur->R) + cur->val;
            cur->sz = size(cur->L) + size(cur->R) + 1;
        }
        
    }
    
    void reverse(Treap *cur, int l, int r) {
        
        Treap *t1, *t2, *t3;
        
        split(cur, t1, t2, l - 1);
        split(t2, t2, t3, r - l + 1);
        t2 -> rev ^= 1;
        merge(cur, t1, t2);
        merge(cur, cur, t3);
        
    }
    
    void print(Treap *cur) {
        
        if (cur == 0) return;
        push(cur);
        print(cur->L);
        cout << cur->val << " ";
        print(cur->R);
        
    }
    
    int getSum(Treap *cur, int u) {
        
        if (cur == 0 || u == 0) return 0;
        
        push(cur);
        
        if (size(cur->L) < u) {
            
            return sum(cur->L) + cur->val + getSum(cur->R, u - size(cur->L) - 1);
            
        } else return getSum(cur->L, u);
        
    }
    
    int getSum(Treap *cur, int l, int r) {
        
        return getSum(cur, r) - getSum(cur, l - 1);
        
    }
    
}

using namespace TreapUtils;

void solve() {
    
    cin >> n >> m;
    forlr(i, 1, n) cin >> arr[i];
    Treap *root = 0;
    forlr(i, 1, n) merge(root, root, new Treap(arr[i]));
    
    for (int i = 1, Q, l, r; i <= m; i++) {
        
        Treap *a, *b, *c, *d;
        cin >> Q >> l >> r;
        if (Q == 1) reverse(root, l, r);
        else cout << getSum(root, l, r) << endl;

    }

}
