vector<int> adj[N];
int phi[N];

void preprocess() {
    
    iota(phi + 1, phi + N, 1);
    
    for (int i = 2; i < N; i++) {
        
        if (phi[i] == i) {
            
            for (int j = i; j < N; j+=i) phi[j] -= phi[j] / i;
            
        }
        
    }
    
}

int modTetra(int a, int b, int m) {
    
    if (a % m == 0) return 0;
    if (b == 1) return a;
    return binPow(a, phi[m] + modTetra(a, b - 1, phi[m]), m);
    
}
