#include <bits/stdc++.h>
#define ii pair<int, int>
#define fs first
#define sc second
#define iii pair<int, ii>
#define fs3 fs
#define sc3 sc.fs
#define rd3 sc.sc
#define iiii pair<ii, ii>
#define fs4 fs.fs
#define sc4 fs.sc
#define rd4 sc.fs
#define fo4 sc.sc
#define db double

using namespace std;

const double PI = acos(-1);
const int INF = 1e9;
const int N = 1e5 + 100;

struct Point {
    
    int x, y;
    
    bool operator == (const Point &p) {
        
        return (x == p.x && y == p.y);
        
    }
    
    bool operator < (const Point &p) {
        
        return (x == p.x) ? (y < p.y) : (x < p.x);
        
    }
    
    db dist(Point &p) {
     
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        
    }
    
};

struct Line {
    
    int a, b, c;

    
};

struct Segment {
    
    int x1, y1, x2, y2;
    
    Point d1, d2;
    
    Segment(int x1, int y1, int x2, int y2) {
        
        this -> x1 = x1;
        this -> y1 = y1;
        this -> x2 = x2;
        this -> y2 = y2;
        
    }
    
    void process() {
        
        d1 = {x1, y1};
        d2 = {x2, y2};
        
        if (d2 < d1) {
            
            swap(x1, x2);
            swap(y1, y2);
            swap(d1, d2);
            
        }
        
    }
    
    Line getLine() {
     
        return {(y1 - y2), (x2 - x1), (x1 * y2 - x2 * y1)};
        
    }
    
    bool operator == (const Segment &s) {
        
        return (x1 == s.x1) && (y1 == s.y1) && (x2 == s.x2);
        
    }
    
    bool isPoint() {
        
        return (x1 == x2) && (y1 == y2);
        
    }
    
    db slope() {
        
        if (x1 == x2) return INF;
        return (y2 - y1) / double(x2 - x1);
        
    }
    
    db len() {
        
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        
    }
    
    bool perpen(Segment &s) {
        
        db sl1 = slope(), sl2 = s.slope();
        
        if (sl1 > sl2) swap(sl1, sl2);
        
        return (sl1 * sl2 == -1) || (sl1 == 0.0 && sl2 == INF);
        
    }
    
    bool in(Point a) {
    
        return ((a.x - x1) * (a.x - x2) <= 0) && ((a.y - y1) * (a.y - y2) <= 0);
        
    }
};

db S3raw(Point a, Point b, Point c) {
    
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    
}

db S3(Point a, Point b, Point c) {
    
    return abs(S3raw(a, b, c));
    
}

bool cw(Point a, Point b, Point c) {
    
    return S3raw(a, b, c) > 0;
    
}

bool ccw (Point a, Point b, Point c) {
    
    return S3raw(a, b, c) < 0;
    
}

void convexHull(vector<Point> &p) {
    
    if (p.size() == 1) return;
    
    sort(p.begin(), p.end());
    
    Point p1 = p[0], p2 = p.back();

    vector<Point> up, down;
    
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

db S(vector<Point> &pt) {
    
    db area = 0;
    int sz = pt.size() - 1;
    
    for (int i = 0; i < sz; i++) {
        
        area += ((pt[i + 1].x - pt[i].x) * (pt[i + 1].y + pt[i].y));

    }
    
    return abs(area) / 2;
    
}

db P(vector<Point> &pt) {
    
    db peri = 0;
    int sz = pt.size() - 1;
    
    for (int i = 0; i < sz; i++) {
        
        peri += pt[i].dist(pt[i + 1]);
    }
    
    return peri;
    
}

struct Circle {
    
    Point a; db R;
    
    double S, P;
    
    Circle(const int x, const int y, const db R) {
        
        this -> a = {x, y};
        this -> R = R;
        this -> S = R * R * PI;
        this -> P = 2 * R * PI;
        
    }
    
    Circle(const Point a, const db R) {
        
        Circle(a.x, a.y, R);
        
    }
    
    Circle() {}
    
    void init (const int x, const int y, const db R) {
        
        this -> a = {x, y};
        this -> R = R;
        this -> S = R * R * PI;
        this -> P = 2 * R * PI;
        
    }
    
    db peri() {
        
        return this -> P;
        
    } 
    
    db area() {
        
        return this -> S;
        
    }
    
    Point center() {
        
        return this -> a;
        
    }
    
};

int n, R;
db d;

typedef long long ll;
#define ll double
#define int double

struct line {
    ll m, b;

    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != -INF) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct DynamicHull : public multiset<line> { 
    bool bad(iterator y) {
        auto z = next(y);
        if(y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }

        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b) * (z->m - y->m) 
            >= 1.0 * (y->b - z->b) * (y->m - x->m);
    }

    void add(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { 
            return next(y) == end() ? 0 : &*next(y); 
        };
        
        if(bad(y)) {
            erase(y);
            return;
        }

        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    ll eval(ll x) {
        auto l = *lower_bound((line) { x, -INF });
        return l.m * x + l.b;
    }
};

db t[N], s[N];

void solve() {
    
    int n; cin >> n;
    
    DynamicHull dh;
    
    for (db i = 1, a; i <= n; i++) {
        
        cin >> a;
        double d1 = -1 / i, d2 = a / i;

        dh.add(d1, d2);
    
    }
    
    int m; cin >> m;
    
    for (int i = 1, a; i <= m; i++) {
        
        cin >> a;
        cout << 1 / dh.eval(a) << " ";
        
    }
    
    cout << endl;

}

signed main() {
    
    cout << setprecision(6) << fixed;
    
    int T;
    
    T = 1;
    
    while (T--) solve();
    
}
