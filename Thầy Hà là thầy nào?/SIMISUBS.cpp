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
#define mp(a, b) make_pair(a, b)
#define Has(v, l, r, val) binary_search(v + l, v + r, val)

#pragma GCC Optimize("O2")
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precise(x) cout << fixed << setprecision(x);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 25;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
 
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

int pow(int a, int b) {
    
    int prod = 1;
    
    while (b) {
        
        if (b & 1) prod *= a;
        a *= a;
        b /= 2;
        
    }
    
    return prod;
    
}

int sqr(int a) {
    
    return a * a;
    
}

int len(int x) {
    
    return log10(x) + 1;
    
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int n;
int arr[N];
int pre[N];

void solve() {
    
    string s; cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        
        pre[i] += pre[i-1] + (s[i] == '1');
        
    }
    
    if (pre[n] == 0) {
        
        cout << 1 << ' ' << n - 1 << " " << 2 << " " << n << endl;
        return;
        
    }
    
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    
    for (int i = 0; i <= n; i++) {
        
        s1 += (pre[i] == pre[0]);
        s2 += (pre[i] == pre[0] + 1);
        s3 += (pre[i] == pre[n] - 1);
        s4 += (pre[i] == pre[n]);
        
    }
    
    if (s1 >= 2 && s4 >= 2) {
        
        cout << 1 << ' ' << n - 1 << " " << 2 << " " << n << endl;
        return;
        
    }
    
    int l = lower_bound(pre, pre + n + 1, 1) - pre;
    int r = lower_bound(pre, pre + n + 1, pre[n]) - pre;
    
    int res = r - l;
    
    int Max1 = 0, Max2 = 0, r1, l1;
    
    if (s1 >= 2) {
        
        for (int i = 1; i < n; i++) {
            
            if (pre[i] == pre[i + 1]) {
                
                Max1 = max(Max1, i);
                r1 = i;

            }
            
        }
        
    }
    
    if (s4 >= 2) {
        
        for (int i = n - 1; i >= 1; i--) {
            
            if (pre[i] == pre[i + 1]) {
                
                Max2 = max(Max2, n - i);
                l1 = i;
                
            }
            
        }

    }
    
    vector<int> tem = {res, Max1, Max2};
    Sort(tem);

    if (tem[2] == res) {
        
        cout << l << " " << r - 1 << " " << l + 1 << " " << r << endl;
        
    } else if (tem[2] == Max1) {
        
        cout << 1 << " " << r1 << " " << 2 << " " << r1 + 1 << endl;
        
    } else {
        
        cout << l1 + 1 << " " << n - 1 << " " << l1 + 2 << " " << n << endl;
        
    }

    
}

signed main() {
    
    fastIO;
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
