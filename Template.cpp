#include <bits/stdc++.h>

#define ii pair<int, int>
#define fs first
#define sc second
#define db double
#define int long long

#define show(v) for (auto i : v) cout << i << " "; cout << endl;
#define showlr(v, l, r) for (int i = l; i <= r; i++) cout << v[i] << " "; cout << endl;
#define all(v) v.begin(), v.end()
#define Unique(v) v.erase(unique(all(v)), v.end());
#define SUnique(v) Sort(v); Unique(v);
#define forlr(i, l, r) for (int i = l; i <= r; i++)
#define forrl(i, r, l) for (int i = r; i >= l; i--)

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
const int LINF = 1e15 + 100;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
 
ostream& operator << (ostream &os, ii a) {
    
    os << a.fs << ' ' << a.sc;
    
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

int modInv(int a, int m) {

    return binPow(a, m - 2, m);
 
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

int len(int x) {
    
    return log10(x) + 1;
    
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

//Try Brute Force (maybe there is a pattern)
//Try DP
//Try Graph
//Try Geometry
//Try switching between problem
//Put down what you have on paper
//IMPORTANT: WRITE DOWN THE FORMULA

int n, m, q, k;
int arr[N];
vector<int> adj[N];
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

void solve() {
    

}

signed main() {
    
    fastIO;
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
