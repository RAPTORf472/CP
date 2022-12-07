#include <bits/stdc++.h>
#define sortv(a) sort(a.begin(), a.end())
#define sorta(a, l, r) sort(a + l, a + r)
#define showvlr(a, l, r) for (int i = l; i <= r; i++) cout << a[i] << " "; cout << endl;
#define showv(a) for (int i : a) cout << i << " "; cout << endl;
#define yes "YES"
#define no "NO"

using namespace std;

const int N = 2e5 + 100;

int dp[N][24][4], a[N];

void solve() {

    int n, K; cin >> n >> K;
    
    char tem;
    for (int i = 1; i <= n; i++) {
        
        cin >> tem;
        if(tem == 'H') a[i] = 1;
        if(tem == 'P') a[i] = 2;
        if(tem == 'S') a[i] = 3;
        
    } 
    
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 0; j <= K; j++) {
            
            for (int k = 1; k <= 3; k++) {
                
                if (k == a[i]) dp[i][j][k]++;
                
                dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][k]);
                dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][k]);
                dp[i+1][j+1][3] = max(dp[i+1][j+1][3], dp[i][j][k]);
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                
            }
            
        }
        
    }

    
    for (int i = 1; i <= 3; i++) res = max(res, dp[n][K][i]);
    
    cout << res << endl;

}

signed main() {
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    bool multiTest = 0;
    int T;
    if (multiTest) cin >> T;
    else T = 1;
    
    while (T--) solve();
    
}
