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
#define int long long

#define show(v) for (auto i : v) cout << i << " "; cout << endl;
#define showlr(v, l, r) for (int i = l; i <= r; i++) cout << v[i] << " "; cout << endl;
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v));
#define Sortlr(v, l, r) sort(v + l, v + r);
#define rev(v) reverse(v.begin(), v.end());
#define revlr(v) reverse(v + l, v + r);
#define Unique(v) v.erase(unique(all(v)), v.end());
#define SUnique(v) Sort(v); Unique(v);
#define Fill(v) memset(v, 0, sizeof v);
#define Filldp(v) memset(v, -1, sizeof v);
#define Has(v, l, r, val) binary_search(v + l, v + r, val)

#pragma GCC Optimize("O2")
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precise(x) cout << fixed << setprecision(x);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 25;
const int MAX = 1000;

ostream& operator << (ostream &os, ii a) {
    
    os << a.fs << ' ' << a.sc;
    
    return os;
    
}

ostream& operator << (ostream &os, iii a) {
    
    os << a.fs3 << " " << a.sc3 << " " << a.rd3;
    
    return os;
    
}

ostream& operator << (ostream &os, iiii a) {
    
    os << a.fs4 << ' ' << a.sc4 << " " << a.rd4 << " " << a.fo4;
    
    return os;
    
}

int ceil(int a, int b) {
    
    return (a + b - 1) / b;
    
}

int binPow(int a, int b, int m) {
    
    int prod = 1;
    a %= m;
    
    while (b) {
        
        if (b & 1) prod = prod * a % m;
        a = a * a % m;
        b /= 2;
        
    }
    
    return prod;
    
}

int sqr(int a) {
    
    return a * a;
    
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int m, n;

int cnt1[N], cnt2[N], a[N];

bool solve(int x) {
    
    cnt1[a[x]]++;
    cnt2[a[x]]--;
    cnt2[a[x * 2]]++;
    cnt2[a[x * 2 - 1]]++;
    
    int l = 1, r = 1, bin1 = 0, bin2 = 0;
    
    while (l <= MAX || r <= MAX) {
        
        while (!cnt1[l] && l < MAX) l++;
        while (!cnt2[r] && r < MAX) r++;
        
        if (l == MAX && r == MAX) return true;
        
        if (l >= r) return false;
        
        if (!bin1) bin1 += cnt1[l];
        if (!bin2) bin2 += cnt2[r];
        
        if (bin1 < bin2) {
            
            bin2 -= bin1;
            bin1 = 0;
            l++;

        } else if (bin1 == bin2) {
            
            bin1 = bin2 = 0;
            l++, r++;

        } else {
            
            bin1 -= bin2;
            bin2 = 0;
            r++;

        }
        
    }
    
    return true;
    
}

void solve() {
    
    cin >> m >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    
    for (int i = 1; i * 2 <= n; i++) {
        
        int tem = solve(i);
        if (tem) {
            
            res = max(res, i);
        
        }
        
    }
    
    cout << res << endl;
    
}

signed main() {
    
    fastIO;

    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
