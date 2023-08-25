int mu[N], cnt[N];
 
void preCompute() {
    
    mu[1] = 1;
    
    forlr(i, 1, N - 1) {
        
        for (int j = 2 * i; j < N; j += i) mu[j] -= mu[i];
        
    }

}
