#include <bits/stdc++.h>
#define int long long
#define db double
#define dd pair<db, db>
#define ii pair<int, int>
#define fs first
#define sc second

using namespace std;

const int unit = 1e6;
const int INF = 1e18;
const int N = 201;

int dist[N];
vector<ii> adj[N];

int n, S, T;

struct Point {
    
    int x, y;
    
    Point operator + (const Point a) {
        
        return {x + a.x, y + a.y};
        
    }
    
    Point operator - (const Point a) {
        
        return {x - a.x, y - a.y};
        
    }
    
    bool operator == (const Point a) {
        
        return (x == a.x) && (y == a.y);
        
    }
    
    int cross(Point a) {
        
        return x * a.y - y * a.x;
        
    }
    
    bool operator < (const Point &v) {
        
        return (v.x == x) ? (y < v.y) : (x < v.x); 
        
    }
    
    int dist(Point &p) {
     
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        
    }
    
};

void dijkstra(int start) {
    
    priority_queue<ii> q;
    
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[start] = 0;
    
    q.push({0, start});
    
    while (q.size()) {
        
        int u = q.top().sc; q.pop();
        
        if (u == T) return;
        
        for (ii V : adj[u]) {
            
            int v = V.fs, d = V.sc;
            
            if (dist[u] + d < dist[v]) {
                
                dist[v] = dist[u] + d;
                q.push({-dist[v], v});
                
            }
            
        }
        
    }

}

vector<Point> reorder(vector<Point> P) {
    
    int pos = 0; 
    
    for (int i = 1; i < P.size(); i++) {
        
        if (P[i].y < P[pos].y || P[i].y == P[pos].y && P[i].x < P[pos].x) pos = i;
        
    }
    
    rotate(P.begin(), P.begin() + pos, P.end());
    
    return P;

}

vector<Point> neg(vector<Point> P) {
    
    for (int i = 0; i < P.size(); i++) {
        
        P[i] = {-P[i].x, -P[i].y};
        
    }
    
    return P;
    
}

db d(Point a, Point b) {
    
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    
}
 
db dx(Point p, db a, db b, db c) {
    
    return abs(a * p.x + b * p.y + c) / (sqrt(a * a + b * b));
    
}
 
db check(Point p, Point p1, Point p2) {

    db Min = min(sqrt(d(p, p1)), sqrt(d(p, p2)));
    
    vector<db> tem = {d(p, p1), d(p, p2), d(p1, p2)};

    sort(tem.begin(), tem.end());
    
    if (tem[2] > tem[1] + tem[0] && tem[2] == d(p1, p2) || tem[2] <= tem[1] + tem[0]) {
        
        db a = p1.y - p2.y;
        db b = p2.x - p1.x;
        db c = p1.x * p2.y - p2.x * p1.y;
        
        Min = min(Min, dx(p, a, b, c));

    }
    
    return Min;
    
}

bool cw(Point a, Point b, Point c) {
    
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
    
}

bool ccw(Point a, Point b, Point c) {
    
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
    
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


vector<Point> minkowskiSum(vector<Point> P, vector<Point> Q) {
    
    P = reorder(P);
    Q = neg(Q);
    Q = reorder(Q);
    
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    
    vector<Point> res;
    
    int i = 0, j = 0;
    
    while (i < P.size() - 2 || j < Q.size() - 2) {
        
        res.push_back(P[i] + Q[j]);
        
        int cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
        
        if (cross >= 0) i++;
        if (cross <= 0) j++;
        
    }
    
    res.erase(unique(res.begin(), res.end()), res.end());
    
    return res;
    
}

db calc(vector<Point> p) {
    
    p.push_back(p[0]);
    
    db res = INF;
    
    for (int i = 0; i < p.size() - 1; i++) {
        
        res = min(res, check({0, 0}, p[i], p[i + 1]));
        
    }
    
    return res;
    
}

void solve() {
    
    int n; cin >> n;
    vector<Point> s1, s2;
    
    for (int i = 1, a, b, c; i <= n; i++) {
        
        cin >> a >> b >> c;
        Point p = {a, b};
        
        if (c == 0) s1.push_back(p);
        else s2.push_back(p);
        
    }
    
    convexHull(s1), convexHull(s2);
    
    vector<Point> minSum = minkowskiSum(s1, s2);
    
    Point root = {0, 0};
    int res = 0;
    
    for (Point i : minSum) res = max(res, root.dist(i));
    
    cout << res << endl;
    
}

signed main() {
    
    int T; cin >> T;
    while (T--) solve();
    
}
