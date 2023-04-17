bool queryMode;

struct Line {
    
	mutable int a, b, leftX;
	
	bool operator<(const Line& o) const {
	    
		return queryMode ? leftX < o.leftX : a < o.a;
		
	}
	
};
 
struct DynamicHull : multiset<Line> {

	bool bad(iterator x, iterator y) {
	    
		if (y == end()) { 
		    
		    x->leftX = INF; 
		    return false;
		    
		}
		
		if (x->a == y->a) x->leftX = x->b > y->b ? INF : -INF;
		else x->leftX = (y->b - x->b) / (x->a - y->a);
		
		return x->leftX >= y->leftX;
		
	}
	
	void add(int a, int b) {
	    
		auto it = insert({a, b, 0});

		while (bad(it, next(it))) erase(next(it));
		while (it != begin() && bad(prev(it), it)) bad(prev(it), erase(it));
		
	}
	
	int query(int x) {
	    
		assert(!empty());
		
		queryMode = 1; auto l = *lower_bound({0,0,x}); queryMode = 0;
		return l.a * x + l.b;
		
	}
	
};
