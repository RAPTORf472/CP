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

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
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

int Pow(int a, int b) {
    
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

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int len(int x) {
    
    return log10(x) + 1;
    
}

int n;
int arr[N];

void solve() {
    
    cin >> n;
    int sum = 0, numDig = 0;
    for (int i = 1; i <= n; i++) {
        
        cin >> arr[i];
        numDig += Pow(10, len(arr[i]));
            
    }
    
    for (int i = 1; i <= n; i++) {
        
        sum += arr[i] % MOD * (n - 1);
        sum %= MOD;
        sum += (arr[i] * ((numDig - (int) Pow(10, len(arr[i]))) % MOD)) % MOD; 
        sum %= MOD;
        
    }
    
    cout << sum << endl;

}

signed main() {
    
    fastIO;
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
