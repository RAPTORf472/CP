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
#define db long double
#define dummy {-INF, -INF}
#define precise(x) cout << setprecision(x) << fixed;
#pragma GCC Optimize("O2")
#define endl "\n"

using namespace std;

const double PI = acos(-1);
const int INF = 1e9;

using namespace std;

int n;

const int N = 401;

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
    
    inline Point operator / (db a) {
        
        return {x / a, y / a};
        
    }
    
    inline void operator /= (int a) {
        
        this -> x /= a;
        this -> y /= a;
        
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
    
    inline bool isPoint() {
        
        return !(x == -INF && y == -INF);
        
    }
    
    inline Point midpoint(Point b) {
        
        return {(x + b.x) / 2, (y + b.y) / 2};
        
    }
    
};

struct Vector {
    
    db x, y;
    
    Vector() {};
    Vector(db x, db y) : x(x), y(y) {};
    
    //cross product
    
    inline db operator ^ (Vector a) {
        
        return x * a.y - y * a.x;
        
    }
    
    Vector getRoot() {
        
        return {0.0, 1.0};
        
    }
    
    //dot product
    inline db operator * (Vector a) {
        
        return x * a.x + y * a.y;
        
    }
    
    
    inline Vector operator - (Vector a) {
        
        return {x - a.x, y - a.y};
        
    }
    
    inline Vector operator / (db a) {
        
        return {x / a, y / a};
        
    }
    
    inline bool operator == (Vector a) {
        
        return x == a.x && y == a.y;
        
    }
    
};

inline bool A (Vector v) {
    
    return ((v.getRoot() ^ v) > 0) || ((v.getRoot() ^ v) == 0 && v.getRoot() * v > 0);
    
}

inline bool operator < (Vector a, Vector b) {
    
    return (A(a) && !A(b)) || (A(a) == A(b) && (a ^ b) > 0);
    
}

vector<Vector> mid[N][N];
Point P[N* N];
set<Point> mids;

int count(int x, int y) {
    
    vector<Vector> v = mid[x][y];
    sort(v.begin(), v.end());
    
    int sz = v.size();
    // for (Vector vv : v) cout << "debug " << vv.x << " " << vv.y << endl;
    int j = 0, k = 0;
    
    int ans = 0;
    
    for (int i = 0; i < sz; i++) {
        
        j = max(i + 1, j), k = max(i + 1, k);
        
        while (j < 2 * sz && v[i] * v[j % sz] > 0.0 && (v[i] ^ v[j % sz]) >= 0.0) {
            
            if (j >= sz && (v[i] ^ v[j % sz]) == 0.0) break;
            j++;
            
        }
        
        while (k < 2 * sz && v[i] * v[k % sz] >= 0.0 && (v[i] ^ v[k % sz]) >= 0.0) {
            
            if (k >= sz && (v[i] ^ v[k % sz]) == 0.0) break;
            k++;
            
        }
        
        // cout << j << " " << k << endl;
        
        ans += k - j;
        
    }
    
    // cout << ans << endl;
    
    return ans;
    
}

signed main() {
    
    precise(1);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        
        cin >> P[i].x >> P[i].y;
        
    }
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = i + 1; j <= n; j++) {
            
            if (P[i] == P[j]) continue;
            
            Point m = (P[i] + P[j]);
            
            Vector a = {P[i].x, P[i].y};
            Vector midp = {m.x / 2, m.y / 2};
            Vector tem = a - midp;
            
            mid[(int) m.x+200][(int) m.y+200].push_back(tem);
            mids.insert({m.x+200, m.y+200});
            
        }
        
    }
    
    int ans = 0;
    
    for (Point p : mids) {
        
        // cout << (p.x - 200) / 2.0 << " " << (p.y - 200) / 2.0 << endl;
        ans += count(p.x, p.y);
    
    }
    
    cout << ans << endl;
    
}
