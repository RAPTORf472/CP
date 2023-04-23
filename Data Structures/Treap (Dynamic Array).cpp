mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

struct Treap {
    
    Treap *left, *right;
    int w, sz;
    char c;
    
    Treap(char c) {
        
        left = right = NULL;
        w = rng();
        sz = 1;
        this->c = c;
        
    }
    
};

namespace TreapUtils {
    
    int size(Treap *treap) {
        
        if (treap == NULL) return 0;
        return treap->sz;
        
    }

    void split(Treap *cur, Treap *&left, Treap *&right, int k) {
        
        if (cur == NULL) left = right = NULL;
        else {
            
            if (size(cur->left) < k) {
                
                split(cur->right, cur->right, right, k - size(cur->left) - 1);
                left = cur;
                
            } else {
                
                split(cur->left, left, cur->left, k);
                right = cur;
                
            }
            
            cur->sz = size(cur->left) + size(cur->right) + 1;
            
        }
        
    }

    void merge(Treap *&cur, Treap *left, Treap *right) {
        
        if (left == NULL) cur = right;
        else if(right == NULL) cur = left;
        else {
            
            if (left->w < right->w) {
                
                merge(left->right, left->right, right);
                cur = left;
                
            } else {
                
                merge(right->left, left, right->left);
                cur = right;
                
            }   
            
            cur->sz = size(cur->left) + size(cur->right) + 1;
        }
        
    }
    
    void print(Treap *cur) {
        
        if (cur == NULL) return;
        print(cur->left);
        cout << cur->c;
        print(cur->right);
        
    }
    
}

using namespace TreapUtils;
