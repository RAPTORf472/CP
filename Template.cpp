/*CP template version 3.1 - Laconic*/

#include <bits/stdc++.h>

#define ii pair<int, int>
#define fs first
#define sc second

//use struct instead of pair<int, ii>

#define int long long

#define show(v) {for (auto i : v) cout << i << " "; cout << endl;}
#define showlr(v, l, r) {for (int i = l; i <= r; i++) cout << v[i] << " "; cout << endl;}
#define all(v) v.begin(), v.end()
#define SUnique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define forlr(i, l, r) for (int i = l; i <= r; i++)
#define forrl(i, r, l) for (int i = r; i >= l; i--)
#define sz(v) ((int) v.size());

#pragma GCC optimize("O2")
#define endl "\n"
#define precise(x) cout << fixed << setprecision(x);

using namespace std;

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 25;
const long long LINF = 1e15 + 100;

const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {0, 0, -1, 0, 1};
 
ostream& operator << (ostream &os, ii a) {
    
    os << a.fs << ' ' << a.sc;
    return os;
    
}

int binPow(int a, int b, int m = LLONG_MAX) {
    
    int prod = 1;
    a %= m;
    
    while (b) {
        
        if (b & 1) prod = prod * a % m;
        a = a * a % m;
        b /= 2;
        
    }
    
    return prod;
    
}

void chMax(int &a, int b) {

	a = max(a, b);

}

void chMin(int &a, int b) {
	
	a = min(a, b);
	
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

//Try Brute Force (maybe there is a pattern)
//Try DP (Weird constraints (sum of all elements <= 10000), small constraints)
//Try Graph (a pair of number, condition between elements)
//Try Geometry (Same as graph, for coordinate)

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
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) {
        
        solve();
    
    }
    
}
