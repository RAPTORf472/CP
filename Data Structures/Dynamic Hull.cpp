bool Q;

struct Line {
    
	mutable ll a, b, preX;
	
	bool operator<(const Line& o) const {
	    
		return Q ? preX < o.preX : a < o.a;
		
	}
	
};
 
struct DynamicHull : multiset<Line> {

	bool bad(iterator x, iterator y) {
	    
		if (y == end()) { 
		    
		    x->preX = INF; 
		    return false;
		    
		}
		
		if (x->a == y->a) x->preX = x->b > y->b ? INF : -INF;
		else x->preX = (y->b - x->b) / (x->a - y->a);
		
		return x->preX >= y->preX;
		
	}
	
    void add(ll k, ll m) {
	    
		auto z = insert({k, m, 0}), y = z++, x = y;
		
		while (bad(y, next(y))) erase(next(y));
        while (y != begin() && bad(prev(y), y)) bad(prev(y), erase(y));
		
	}
	
	ll query(ll x) {
	    
		assert(!empty());
		
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return l.a * x + l.b;
		
	}
	
};
