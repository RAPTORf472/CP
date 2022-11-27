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

using namespace std;

const double PI = acos(-1);
const int INF = 1e9;
const int N = 1005;

struct Point {
    
    db x, y;
    
    bool operator == (const Point &p) {
        
        return (x == p.x && y == p.y);
        
    }
    
    bool operator < (const Point &p) {
        
        return (x == p.x) ? (y < p.y) : (x < p.x);
        
    }
    
    Point operator + (const Point a) {
        
        return {x + a.x, y + a.y};
        
    }
    
    Point operator - (const Point a) {
        
        return {x - a.x, y - a.y};
        
    }
    
    db dist(Point &p) {
     
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        
    }
    
    db cross(Point a) {
        
        return x * a.y - y * a.x;
        
    }
    
};

struct Line {
    
    db a, b, c;
    
    Point inter(const Line &l) {
        
        db D = a * l.b - b * l.a;
        db Dx = b * l.c - c * l.b;
        db Dy = c * l.a - a * l.c;
        
        if (D == 0) return dummy;
        
        return {Dx / D, Dy / D};
        
    }
    
    // 1 điểm nằm trên đt và điểm còn lại ngoài vẫn tính cùng phía
    
    bool sameSide(Point p1, Point p2) {
        
        return (a * p1.x + b * p1.y + c) * (a * p2.x + b * p2.y + c) >= 0;
        
    }
    
    // Còn cái này là hong nha bé ơi (onLineSame để xác định xem 2 điểm trên cùng 1 đường có tính cùng không)
    
    bool sameSide(Point p1, Point p2, bool onLineSame) {
        
        double d1 = a * p1.x + b * p1.y + c, d2 = a * p2.x + b * p2.y + c;
        
        if (d1 == 0 && d2 == 0) return onLineSame;
        
        return d1 * d2 > 0;
        
    }
    
};

struct Segment {
    
    db x1, y1, x2, y2;
    
    Point d1, d2;
    
    Segment(db x1, db y1, db x2, db y2) {
        
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
    
    bool has(Point a) {
    
        return ((a.x - x1) * (a.x - x2) <= 0) && ((a.y - y1) * (a.y - y2) <= 0);
        
    }
    
    Point interSeg(Segment s) {
        
        Line l1 = getLine(), l2 = s.getLine();
        
        Point p = l1.inter(l2);
        if (has(p) && s.has(p)) return p;
        return dummy;
        
    }
    
    Point interLine(const Line &l) {
        
        Line l1 = getLine();
        
        Point p = l1.inter(l);
        if (has(p)) return p;
        else return dummy;
        
    }
    
};

struct Helper {
    
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
    
    bool isPoint(Point p) {
        
        return !(p.x == INF && p.y == INF);
        
    }
    
} misc;

void convexHull(vector<Point> &p) {
    
    if (p.size() == 1) return;
    
    sort(p.begin(), p.end());
    
    Point p1 = p[0], p2 = p.back();

    vector<Point> up, down;
    
    up.push_back(p1), down.push_back(p1);
    
    for (int i = 1; i < p.size(); i++) {
        
        if (i == p.size() - 1 || misc.cw(p1, p[i], p2)) {
            
            while (up.size() >= 2 && !misc.cw(up[up.size() - 2], up[up.size() - 1], p[i])) 
                up.pop_back();
                
            up.push_back(p[i]);
            
        }
        
        if (i == p.size() - 1 || misc.ccw(p1, p[i], p2)) {
            
            while (down.size() >= 2 && !misc.ccw(down[down.size() - 2], down[down.size() - 1], p[i]))
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

//Tìm các cặp điểm xuyên tâm chiếu (Là mấy cái cặp mà tồn tại 2 đường thẳng song song đi qua 2 điểm đó mà không cắt vào cái đa giác đang xét á)
//Nó là two pointer trên convex hull. YES, STOP MESSING WITH MEEEE
db caliper(vector<Point> &p) { //Đổi kiểu return theo nhu cầu sử dụng (Sẽ nói ở dưới)
   
   if (p.size() == 1) return 0;
   if (p.size() == 2) return p[0].dist(p[1]);
   
   int k = 1, sz = p.size();
   
   while (misc.S3(p[sz - 1], p[0], p[(k + 1) % sz]) > misc.S3(p[sz - 1], p[0], p[k])) k++;
   
   db res = 0;
   
   for (int i = 0, j = k; i <= k && j < sz; i++) {
       
       res = max(res, p[i].dist(p[j])); // 2 điểm này đạt (Có thể push vào vector hay j đó)
       
       while (j < sz && misc.S3(p[i], p[(i + 1) % sz], p[(j + 1) % sz]) >
                        misc.S3(p[i], p[(i + 1) % sz], p[j])) {
           
           res = max(res, p[i].dist(p[(j + 1) % sz])); //2 điểm này cũng vậy
           j++;
           
       }
       
   }
   
   return res;
    
}

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
    
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    
    cin >> n;
    Line l;
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++) {
        
        cin >> l.a >> l.b >> l.c;
        
        if (l.sameSide(p1, p2)) continue;
        cnt++;
        
    }
    
    cout << cnt << endl;
    
}

signed main() {
    
    int T;
    bool multiTest = 0;
    if (multiTest) cin >> T;
    else T = 1;
    //setprecision
    precise(6);
    
    while (T--) solve();
    
}
