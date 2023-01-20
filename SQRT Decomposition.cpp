int n;

const int BLOCK_SIZE = 400;

int blockRes[N / BLOCK_SIZE + 10];
int arr[N];

void preprocess() {
    
    for (int i = 1; i <= n; i++)
        blockRes[i / BLOCK_SIZE] += arr[i];
    
}

int query(int l, int r) {
    
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;
    
    int sum = 0ll;
    
    if (blockL >= blockR) {
        
        for (int i = l; i <= r; i++) sum += arr[i];
        return sum;
        
    }
    
    for (int i = blockL; i < blockR; i++) {
        
        sum += blockRes[i];
    
    }
    
    for (int i = l; i < blockL * BLOCK_SIZE; i++) {
        
        sum += arr[i];
        
    }
    
    for (int i = blockR * BLOCK_SIZE; i <= r; i++) {
        
        sum += arr[i];
        
    }
    
    return sum;
    
}
