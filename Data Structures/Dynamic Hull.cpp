bool queryMode;
 
struct Line {
    
    mutable int a, b, rightX;
    
    bool operator < (const Line &l) const {
        
        return queryMode ? rightX < l.rightX : a < l.a;
        
    }
    
};
 

struct DynamicHull : multiset<Line> {
    
    int div(int a, int b) {
        
        return a / b - ((a ^ b) < 0 && a % b);
        
    }
    
    bool bad(iterator x, iterator y) {
        
        if (y == end()) {
            
            x->rightX = LINF;
            return false;
            
        }
        
        if (x->a == y->a) x->rightX = (x->b > y->b) ? LINF : -LINF;
        else x->rightX = div(y->b - x->b, x->a - y->a);
        
        return x->rightX >= y->rightX;
        
    }
    
    void add(int a, int b) {
        
        auto cur = insert({a, b, 0}), pre = cur;
        
        while (bad(cur, next(cur))) erase(next(cur));
        
        if (pre != begin() && bad(--pre, cur)) bad(pre, cur = erase(cur));
        while ((cur = pre) != begin() && (--pre)->rightX >= cur->rightX) bad(pre, erase(cur));
        

    }
    
    int query(int x) {
        
        assert(!empty());
        queryMode = 1;
        auto l = *lower_bound({0, 0, x});
        queryMode = 0;
        
        return l.a * x + l.b;
        
    }
    
};
