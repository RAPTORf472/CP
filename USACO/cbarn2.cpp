#include <bits/stdc++.h>
#define ii pair<int, int>
#define fs first
#define sc second
#define iii pair<int, ii>
#define fs3 fs
#define sc3 sc.fs
#define rd3 sc.sc
#define endl "\n"
#define all(v) v.begin(), v.end()
#define showv(v) for (auto i : v) cout << i << " "; cout << endl;
#define showvlr(v, l, r) for (int i = l; i <= r; i++) cout << v[i] << ' '; cout << endl;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N = 2e5 + 100;
const int INF = 1e9;

using namespace std;

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int n, m;

int a[N], dp[10][N];

int solve(int l, int r) {
    
    memset(dp, 0x3f, sizeof dp);
    
    dp[1][l] = 0;
    for (int i = l + 1; i <= r; i++) dp[1][i] = dp[1][i-1] + a[i] * (i - l);
    
    for (int i = 2; i <= m; i++) {
        
        for (int j = l; j <= r; j++) {
            
            int val = 0;
            
            for (int k = j; k <= r; k++) {
                
                val += a[k] * (k - j);
                dp[i][k] = min(dp[i][k], dp[i-1][j-1] + val);
                
            }
            
        }
        
    }
    
    // for (int i = 1; i <= m; i++) {
        
    //     for (int j = l; j <= r; j++) cout << dp[i][j] << ' '; cout << endl;
        
    // }
    
    return dp[m][r];
    
}

void solve() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        
        cin >> a[i];
        a[i + n] = a[i];
        
    }
    
    int res = INF;
    
    for (int i = 1; i <= n; i++) res = min(res, solve(i, i + n - 1));
    
    cout << res << endl;
    
}

signed main() {
    
    faster;
    setIO("cbarn2");
    
    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
