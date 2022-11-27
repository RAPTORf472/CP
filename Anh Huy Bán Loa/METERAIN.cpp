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
#define dummy {-INF, -INF}
#define precise(x) cout << setprecision(x) << fixed;
#pragma GCC Optimize("O2")
#define endl "\n"

using namespace std;

const double PI = acos(-1);
const int INF = 1e9;
const int N = 1005;

struct Point {
    
    db x, y;
    
    inline bool operator == (const Point &p) const {
        
        return (x == p.x && y == p.y);
        
    }
    
    inline bool operator < (const Point &p) const {
        
        return (x == p.x) ? (y < p.y) : (x < p.x);
        
    }
    
    inline Point operator + (Point a) {
        
        return {x + a.x, y + a.y};
        
    }
    
    inline Point operator - (Point a) {
        
        return {x - a.x, y - a.y};
        
    }
    
    inline void operator += (Point a) {
        
        this->x += a.x;
        this->y += a.y;
        
    }
    
    inline void operator -= (Point a) {
        
        this->x -= a.x;
        this->y -= a.y;
        
    }
    
    inline db dist(Point &p) {
     
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        
    }
    
    inline db cross(Point a) {
        
        return x * a.y - y * a.x;
        
    }
        
    inline bool isPoint() {
        
        return !(x == -INF && y == -INF);
        
    }
    
};

struct Line {
    
    db a, b, c;
    
    inline Point inter(const Line &l) {
        
        db D = a * l.b - b * l.a;
        db Dx = b * l.c - c * l.b;
        db Dy = c * l.a - a * l.c;
        
        if (D == 0) return dummy;
        
        return {Dx / D, Dy / D};
        
    }
    
    // 1 điểm nằm trên đt và điểm còn lại ngoài vẫn tính cùng phía
    
    inline bool sameSide(Point p1, Point p2) {
        
        return (a * p1.x + b * p1.y + c) * (a * p2.x + b * p2.y + c) >= 0;
        
    }
    
    // Còn cái này là hong nha bé ơi (onLineSame để xác định xem 2 điểm trên cùng 1 đường có tính cùng không)
    
    inline bool sameSide(Point p1, Point p2, bool onLineSame) {
        
        double d1 = a * p1.x + b * p1.y + c, d2 = a * p2.x + b * p2.y + c;
        
        if (d1 == 0 && d2 == 0) return onLineSame;
        
        return d1 * d2 > 0;
        
    }
    
    inline bool has(Point &p) {
        
        return (abs(a * p.x + b * p.y + c) <= (0.01));
        
    }
    
};

struct Segment {
    
    db x1, y1, x2, y2;
    Line L;
    
    Point d1, d2;
    
    Segment(db x1, db y1, db x2, db y2) {
        
        this -> x1 = x1;
        this -> y1 = y1;
        this -> x2 = x2;
        this -> y2 = y2;

        process();
        
    }
    
    Segment(Point p1, Point p2) {
        
        this -> x1 = p1.x;
        this -> y1 = p1.y;
        this -> x2 = p2.x;
        this -> y2 = p2.y;    

        process();
        
    }
    
    inline void process() {
        
        d1 = {x1, y1};
        d2 = {x2, y2};
        
        if (d2 < d1) {
            
            swap(x1, x2);
            swap(y1, y2);
            swap(d1, d2);
            
        }
        
        L = getLine();
        
    }
    
    inline Line getLine() {
     
        return {(y1 - y2), (x2 - x1), (x1 * y2 - x2 * y1)};
        
    }
    
    inline bool operator == (const Segment &s) {
        
        return (x1 == s.x1) && (y1 == s.y1) && (x2 == s.x2);
        
    }
    
    inline db slope() {
        
        if (x1 == x2) return INF;
        return (y2 - y1) / double(x2 - x1);
        
    }
    
    inline db len() {
        
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        
    }
    
    inline bool perpen(Segment &s) {
        
        db sl1 = slope(), sl2 = s.slope();
        
        if (sl1 > sl2) swap(sl1, sl2);
        
        return (sl1 * sl2 == -1) || (sl1 == 0.0 && sl2 == INF);
        
    }
    
    inline bool has(Point a) {

        return L.has(a) && ((a.x - x1) * (a.x - x2) <= 0) && ((a.y - y1) * (a.y - y2) <= 0);
        
    }
    
    inline Point interSeg(Segment s) {
        
        Line l1 = getLine(), l2 = s.getLine();
        
        Point p = l1.inter(l2);
        if (has(p) && s.has(p)) return p;
        return dummy;
        
    }
    
    inline Point interLine(const Line &l) {
        
        Line l1 = getLine();
        
        Point p = l1.inter(l);
        if (has(p)) return p;
        else return dummy;
        
    }
    
};

struct Helper {
    
    inline db S3raw(Point a, Point b, Point c) {
        
        return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
        
    }
    
    inline db S3(Point a, Point b, Point c) {
        
        return abs(S3raw(a, b, c));
        
    }
    
    inline bool cw(Point a, Point b, Point c) {
        
        return S3raw(a, b, c) > 0;
        
    }
    
    inline bool ccw (Point a, Point b, Point c) {
        
        return S3raw(a, b, c) < 0;
        
    }
    
    inline bool isPoint(Point p) {
        
        return !(p.x == -INF && p.y == -INF);
        
    }
    
    
    inline vector<Point> reorder(vector<Point> P) {
    
        int pos = 0; 
        
        for (int i = 1; i < P.size(); i++) {
            
            if (P[i].y < P[pos].y || P[i].y == P[pos].y && P[i].x < P[pos].x) pos = i;
            
        }
        
        rotate(P.begin(), P.begin() + pos, P.end());
        
        return P;
    
    }
    
    inline vector<Point> neg(vector<Point> P) {
        
        for (int i = 0; i < P.size(); i++) {
            
            P[i] = {-P[i].x, -P[i].y};
            
        }
        
        return P;
        
    }
    
} misc;

struct Ray {
    
    Point start, dir;
    
    Ray() {}
    
    Ray(Point start, Point dir) {
        
        this -> start = start;
        this -> dir = dir;
        
    }
    
    Ray (db x1, db y1, db x2, db y2) {
        
        this -> start = {x1, y1};
        this -> dir = {x2, y2};
        
    }
    
    inline Line getLine() {
        
        Segment s(start.x, start.y, dir.x, dir.y);
        return s.getLine();
        
    }
    
    inline bool has(const Point &p) {
        
        Segment s1(start, dir), s2(start, p);
        
        return s1.has(p) || s2.has(dir); 
        
        
    }
    
    inline Point interRay(Ray r) {
        
        Line l1 = getLine(), l2 = r.getLine();
        Point p = l1.inter(l2);
        
        if (r.has(p) && has(p)) return p;
        return dummy;
        
    }   
    
    inline Point interSeg(Segment s) {
        
        Line l1 = getLine(), l2 = s.getLine();
        
        Point p = l1.inter(l2);
        
        if (s.has(p) && has(p)) return p;
        return dummy;        
    }
    
    inline Point interLine(const Line &l2) {
        
        Line l1 = getLine();
        Point p = l1.inter(l2);
        
        if (has(p)) return p;
        return dummy;
        
    }
    
};

//nên để theo chiều kim đồng hồ

struct Polygon {
    
    vector<Point> P;
    set<Point> Points;
    
    Polygon() {}
    
    Polygon (vector<Point> P) {
        
        this->P = P;
        for (Point p : P) Points.insert(p);
        
    }
    
    inline void insert(Point p) {
        
        P.push_back(p);
        Points.insert(p);
        
    }
    
    inline bool isVertice(Point p) {
        
        return *Points.lower_bound(p) == p;
        
    }
    
    inline vector<Point> getConvexHull() {
    
        if (P.size() == 1) return P;
        
        sort(P.begin(), P.end());
        
        Point p1 = P[0], p2 = P.back();
    
        vector<Point> up, down;
        
        up.push_back(p1), down.push_back(p1);
        
        for (int i = 1; i < P.size(); i++) {
            
            if (i == P.size() - 1 || misc.cw(p1, P[i], p2)) {
                
                while (up.size() >= 2 && !misc.cw(up[up.size() - 2], up[up.size() - 1], P[i])) 
                    up.pop_back();
                    
                up.push_back(P[i]);
                
            }
            
            if (i == P.size() - 1 || misc.ccw(p1, P[i], p2)) {
                
                while (down.size() >= 2 && !misc.ccw(down[down.size() - 2], down[down.size() - 1], P[i]))
                    down.pop_back();
                
                down.push_back(P[i]);
    
            }
            
        }
        
        vector<Point> cv;
        
        for (int i = 0; i < down.size(); i++) cv.push_back(down[i]);
        for (int i = up.size() - 2; i > 0; i--) cv.push_back(up[i]);
        auto it = unique(cv.begin(), cv.end());
        cv.resize(distance(cv.begin(), it));
        
        return cv;
        
    }
    
    inline db getS() {
    
        db area = 0;
        int sz = P.size();
        
        for (int i = 0; i < sz; i++) {
            
            area += ((P[(i + 1) % sz].x - P[i].x) * (P[(i + 1) % sz].y + P[i].y));
    
        }
        
        return abs(area) / 2;
        
    }
    
    inline db getP() {
        
        db peri = 0;
        int sz = P.size();
        
        for (int i = 0; i < sz; i++) {
            
            peri += P[i].dist(P[(i + 1) % sz]);
        }
        
        return peri;
        
    }
    
    //Caliper cho đa giác móp méo đc á
    
    inline db caliper() { //Đổi kiểu return theo nhu cầu sử dụng (Sẽ nói ở dưới)
       
       if (P.size() == 1) return 0;
       if (P.size() == 2) return P[0].dist(P[1]);
       
       int k = 1, sz = P.size();
       
       while (misc.S3(P[sz - 1], P[0], P[(k + 1) % sz]) > misc.S3(P[sz - 1], P[0], P[k])) k++;
       
       db res = 0;
       
       for (int i = 0, j = k; i <= k && j < sz; i++) {
           
           res = max(res, P[i].dist(P[j])); // 2 điểm này đạt (Có thể push vào vector hay j đó)
           
           while (j < sz && misc.S3(P[i], P[(i + 1) % sz], P[(j + 1) % sz]) >
                            misc.S3(P[i], P[(i + 1) % sz], P[j])) {
               
               res = max(res, P[i].dist(P[(j + 1) % sz])); //2 điểm này cũng vậy
               j++;
               
           }
           
       }
       
       return res;
        
    }
    
    inline vector<Point> minkowskiSum(Polygon Q) {
        
        vector<Point> P1 = P, P2 = Q.P;
        P1 = misc.reorder(P1);
        P2 = misc.neg(P2);
        P2 = misc.reorder(P2);
        
        P1.push_back(P1[0]);
        P1.push_back(P1[1]);
        P2.push_back(P2[0]);
        P2.push_back(P2[1]);
        
        vector<Point> res;
        
        int i = 0, j = 0;
        
        while (i < P1.size() - 2 || j < P2.size() - 2) {
            
            res.push_back(P1[i] + P2[j]);
            
            int cross = (P1[i + 1] - P1[i]).cross(P2[j + 1] - P2[j]);
            
            if (cross >= 0) i++;
            if (cross <= 0) j++;
            
        }
        
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;
        
    }
    
    inline bool has(Point p) {
        
        Point right = {1, 0};
        Point dir = p + right;
        
        Ray r(p.x, p.y, dir.x, dir.y);
        int cnt = 0;
        int sz = P.size();
        
        for (Point i : P) if (i == p) return false;
        
        for (int i = 0; i < sz; i++) {
            
            Segment s(P[i], P[(i + 1) % sz]);
            Line l = s.getLine();
            if (l.has(p)) return false;
            Point p1 = r.interSeg(s);
            
            if (p1 == P[i]) {
                
                if (l.sameSide(p, P[(i + 2) % sz])) continue;
                return false;
                
            }
            if (p1.isPoint()) {
                
                cnt++;

            }
            
        }
        
        return cnt & 1;
        
    }
    
};

//Tìm các cặp điểm xuyên tâm chiếu (Là mấy cái cặp mà tồn tại 2 đường thẳng song song đi qua 2 điểm đó mà không cắt vào cái đa giác đang xét á)
//Nó là two pointer trên convex hull. YES, STOP MESSING WITH MEEEE

struct Circle {
    
    Point a; db R;
    
    double S, P;
    
    Circle(const db x, const db y, const db R) {
        
        this -> a = {x, y};
        this -> R = R;
        this -> S = R * R * PI;
        this -> P = 2 * R * PI;
        
    }
    
    Circle(const Point a, const db R) {
        
        Circle(a.x, a.y, R);
        
    }
    
    Circle() {}
    
    void init (const db x, const db y, const db R) {
        
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

int n;

void solve() {

    cin >> n;
    
    vector<Point> poly(n);
    
    for (db i = 0, a, b; i < n; i++) {
        
        cin >> poly[i].x >> poly[i].y;

    }
    
    Polygon p(poly);
    
    cin >> n;
    
    for (db i = 1, a, b; i <= n; i++) {
        
        cin >> a >> b;
        
        cout << (p.has({a, b}) ? "YES" : "NO") << endl;

    }
    
}

signed main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T;
    bool multiTest = 0;
    if (multiTest) cin >> T;
    else T = 1;
    //setprecision
    precise(6);
    
    while (T--) solve();
    
}
