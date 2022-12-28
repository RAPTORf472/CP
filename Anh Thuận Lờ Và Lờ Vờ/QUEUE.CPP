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

#define showlr(v, l, r) for (int i = l; i <= r; i++) cout << v[i] << " "; cout << endl;
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v));
#define Sortlr(v, l, r) sort(v + l, v + r);
#define rev(v) reverse(v.begin(), v.end());
#define revlr(v) reverse(v + l, v + r);
#define Unique(v) v.erase(unique(all(v)), v.end());
#define SUnique(v) Sort(v); Unique(v);

#pragma GCC Optimize("O2")
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define precise(x) cout << fixed << setprecision(x);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 100;
const int MOD = 1e15 + 7;
const int INF = 1e15;

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

ostream& operator << (ostream &os, ii a) {
    
    os << a.fs << ' ' << a.sc;
    
    return os;
    
}

ostream& operator << (ostream &os, iii a) {
    
    os << a.fs3 << " " << a.sc3 << " " << a.rd3;
    
    return os;
    
}

int ceil(int a, int b) {
    
    return (a + b - 1) / b;
    
}

int floor(int a, int b) {
    
    return (a / b);
    
}

int sqr(int a) {
    
    return a * a;
    
}

void setIO(string s) {
    
    if (s.empty()) return;
    
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    
}

int ans[N + 1];

multiset<iii> s, org;
queue<iii> q;
int n, m, k, cur, cura; 

iii getCandidate(int x) {
    
    int rem = x % k;
    set<iii>::iterator its = s.lower_bound({rem, {-INF, 0}});
    set<iii>::iterator ito = org.lower_bound({x, {-INF, 0}});
    iii cands = (*its);
    iii cando = (*ito);
    if (s.size() && its != s.end()) cands.fs3 += x / k * k;
    if (its == s.end() && s.size()) {
        
        its = s.begin();
        cands = (*its);
        cands.fs3 += x / k * k + k;
        
    }
    
    if (s.empty()) {
        
        cands = {INF, {INF, INF}};
        
    }
    
    if (ito == org.end()) {
        
        cando = {INF, {INF, INF}};
        
    }
    
    iii res;
    int in;

    if (cands > cando) {
        
        res = cando;
        if (org.size() && ito != org.end()) {
            
            org.erase(ito);

        }
        
    } else {
        
        res = cands;
        if (s.size() && its != s.end()) {
            
            s.erase(its);

        }
        
    }
    
    cura = max(cura, res.fs3);
    
    while (q.size() && q.front().fs3 <= res.fs3) {
            
        iii tem = q.front();
        ans[tem.sc3] = tem.fs3;
        q.pop();
        
    }

    int del;
    if (q.size()) del = q.front().rd3;
    else del = res.fs3;
    res.fs3 = max(res.fs3, cur) + res.rd3;

    while (org.size() && (*org.begin()).fs3 <= del) {
        
        int a = (*org.begin()).fs3, b = (*org.begin()).rd3, id = (*org.begin()).sc3;
        s.insert({a % k, {id, b}});
        org.erase(org.begin());
        
    }
    
    return res;
    
}

void solve() {
    
    cin >> n >> m >> k;

    for (int i = 1, a, b; i <= n; i++) {
        
        cin >> a >> b;
        org.insert({a, {i, b}});
        
    }
    
    for (int i = 1; i <= n; i++) {
        
        int nxt;
        if (q.empty()) nxt = cur;
        else nxt = q.back().rd3;
        
        if (q.size() >= m) {
            
            if (nxt < q.front().fs3) nxt = q.front().fs3;
            
        }
        
        iii cand = getCandidate(nxt);
        int a = cand.fs3, b = cand.rd3, id = cand.sc3;

        if (q.size() < m) {
            
            iii tem = {a, {id, cura}};
            q.push(tem);
            
            if (q.size() == m) {
                
                while (org.size() && (*org.begin()).fs3 <= q.front().fs3) {
                    
                    iii tem = *org.begin();
                    int a = tem.fs3, id = tem.sc3, b = tem.rd3;
                    s.insert({a % k, {id, b}});
                    org.erase(org.begin());
                    
                }
                
            }
            
            cur = cand.fs3;

        } else {
            
            s.insert({a % k, {id, b}});
            nxt = q.front().fs3;
            cand = getCandidate(nxt);
            
            iii tem = {cand.fs3, {cand.sc3, cura}};
            q.push(tem);
            cur = cand.fs3;
            
        }
        
    }
    
    while (q.size()) {
        
        int a = q.front().fs3, id = q.front().sc3; q.pop();
        ans[id] = a;
        
    }
    
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    
}

signed main() {
    
    fastIO;

    int T = 1;
    
    bool multiTest = 0;
    if (multiTest) cin >> T;
    
    while (T--) solve();
    
}
