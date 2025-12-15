long long getDescentPeriods(int* prices, int pricesSize) {
    long long ans = 0;
    long long len = 1;  

    for (int i = 0; i < pricesSize; i++) {
        if (i > 0 && prices[i - 1] - prices[i] == 1) {
            len++;  
        } else {
            len = 1;
        }
        ans += len;  
    }

    return ans;
}
