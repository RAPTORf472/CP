#include <bits/stdc++.h>
#define db long double
#define int long long

using namespace std;

const int N = 1e5 + 100;

int n;

struct pt {
    
    int x, y;
    
    bool operator < (const pt &v) {
        
        return (v.x == x) ? (y < v.y) : (x < v.x); 
        
    }
    
    bool operator == (const pt &v) {
        
        return (x == v.x) && (y == v.y);
        
    }
    
    
};

bool cw(pt a, pt b, pt c) {
    
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
    
}

bool ccw(pt a, pt b, pt c) {
    
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
    
}

void convexHull(vector<pt> &p) {
    
    if (p.size() == 1) return;
    
    sort(p.begin(), p.end());
    
    pt p1 = p[0], p2 = p.back();

    vector<pt> up, down;
    
    up.push_back(p1), down.push_back(p1);
    
    for (int i = 1; i < p.size(); i++) {
        
        if (i == p.size() - 1 || cw(p1, p[i], p2)) {
            
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p[i])) 
                up.pop_back();
                
            up.push_back(p[i]);
            
        }
        
        if (i == p.size() - 1 || ccw(p1, p[i], p2)) {
            
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], p[i]))
                down.pop_back();
            
            down.push_back(p[i]);

        }
        
    }
    
    p.clear();
    
    for (int i = 0; i < down.size(); i++) p.push_back(down[i]);
    for (int i = up.size() - 2; i > 0; i--) p.push_back(up[i]);
    auto it = unique(p.begin(), p.end());
    p.resize(distance(p.begin(), it));
    
}

db S(pt a, pt b, pt c) {
    
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0;
    
}

db d(pt a, pt b) {
    
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    
}

db caliper(vector<pt> &p) {
   
   if (p.size() == 1) return 0;
   if (p.size() == 2) return d(p[0], p[1]);
   
   int k = 1, sz = p.size();
   
   while (S(p[sz - 1], p[0], p[(k + 1) % sz]) > S(p[sz - 1], p[0], p[k])) k++;
   
   db res = 0;
   
   for (int i = 0, j = k; i <= k && j < sz; i++) {
       
       res = max(res, d(p[i], p[j]));
       
       while (j < sz && S(p[i], p[(i + 1) % sz], p[(j + 1) % sz]) >
                        S(p[i], p[(i + 1) % sz], p[j])) {
           
           res = max(res, d(p[i], p[(j + 1) % sz]));
           j++;
           
       }
       
   }
   
   return res;
    
}

void solve() {
    
    cin >> n;
    
    vector<pt> p(n);
    
    for (int i = 0, a, b; i < n; i++) {
        
        cin >> a >> b;
        p[i] = {a, b};
        
    }
    
    convexHull(p);

    cout << sqrt(caliper(p)) << endl;
    
}

signed main() {
    
    int T = 1;
    
    cout << fixed << setprecision(6);
    
    while (T--) solve();
    
}
