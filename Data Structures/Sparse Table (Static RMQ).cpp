const int N = 1e5 + 100;
const int LOG = 25;

struct RMQ {
    
    int st[N][LOG];
    
    void init(int *arr, int n) {
        
        for (int i = 1; i <= n; i++) st[i][0] = arr[i];
        
        for (int i = 1; i < LOG; i++)
            for (int j = 1; j + (1 << i) - 1 <= n; j++)
                st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        
    }
    
    int get(int l, int r) {
        
        if (l > r) return -INF;
        int lg = __lg(r - l + 1);
        return max(st[l][lg], st[r - (1 << lg) + 1][lg]);
        
    }
    
};

