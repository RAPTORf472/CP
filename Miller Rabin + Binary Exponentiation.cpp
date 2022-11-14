#include <bits/stdc++.h>
#define int long long

using namespace std;

int binPow(int a, int b, int MOD) {
    
    a %= MOD;
    
    int res = 1;
    
    while (b > 0) {
        
        if (b & 1) res = res * a % MOD;
        
        a = a * a % MOD;
        b /= 2;
        
    }
    
    return res;
    
}

bool MillerRabin(int n, int k = 40) {

    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    
    int D = n - 1;
    
    while (D % 2 == 0) D /= 2;
    
    for (int i = 0; i < k; i++) {
        
        int d = D;    
        bool ok = false;        
        
        int a = 2 + rand() % (n - 4);
        int x = binPow(a, d, n);
        
        if (x == 1 || x == n - 1) continue;
        
        while (d != n - 1) {
            
            x = (x * x) % n;
            d *= 2;
            
            if (x == 1) return false;
            if (x == n-1) {
                
                ok = true;
                break;
                   
            }
            
        }
        
        if(ok) continue;
        return false;        
        
    }
    
    return true;
    
}

signed main() {
    
    cout << MillerRabin(999999733) << endl;
    
}
