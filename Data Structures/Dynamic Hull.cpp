bool queryMode;

struct Line {
    
	mutable int a, b, rightX;
	
	bool operator<(const Line& o) const {
	    
		return queryMode ? rightX < o.rightX : a < o.a;
		
	}
	
};
 
struct DynamicHull : multiset<Line> {

	bool bad(iterator x, iterator y) {
	    
		if (y == end()) { 
		    
		    x->rightX = INF; 
		    return false;
		    
		}
		
		if (x->a == y->a) x->rightX = x->b > y->b ? INF : -INF;
		else x->rightX = (y->b - x->b) / (x->a - y->a);
		
		return x->rightX >= y->rightX;
		
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
