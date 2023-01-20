int n;

const int N = 2e5;
const int BLOCK_SIZE = 400;
//2e5 : 400
//1e5 : 300

int blockRes[N / BLOCK_SIZE + 10];
int arr[N];

void preprocess() {
    
    for (int i = 1; i <= n; i++)
        blockRes[i / BLOCK_SIZE] += arr[i];
    
}

void update(int u, int val) {
    
    int block = u / BLOCK_SIZE;
    blockRes[block] -= arr[u];
    arr[u] = val;
    blockRes[block] += arr[u];
    
}

int query(int l, int r) {
    
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;
    
    int ans = 0;
    
    if (blockL >= blockR) {
        
        for (int i = l; i <= r; i++) ans += arr[i];
        return ans;
        
    }
    
    for (int i = blockL; i < blockR; i++) {
        
        ans += blockRes[i];
    
    }
    
    for (int i = l; i < blockL * BLOCK_SIZE; i++) {
        
        ans += arr[i];
        
    }
    
    for (int i = blockR * BLOCK_SIZE; i <= r; i++) {
        
        ans += arr[i];
        
    }
    
    return ans;
    
}
