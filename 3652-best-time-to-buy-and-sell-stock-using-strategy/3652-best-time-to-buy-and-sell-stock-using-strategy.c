long long maxProfit(int* prices, int n, int* strategy, int strategySize, int k) {

    long long baseProfit = 0;
    for (int i = 0; i < n; i++) {
        baseProfit += (long long)strategy[i] * prices[i];
    }

    long long maxProfit = baseProfit;

    long long oldSum = 0;   // old strategy contribution
    long long sellSum = 0;  // prices of forced sell part

    // initial window [0 .. k-1]
    for (int i = 0; i < k; i++) {
        oldSum += (long long)strategy[i] * prices[i];
        if (i >= k / 2) {
            sellSum += prices[i];
        }
    }

    maxProfit = baseProfit - oldSum + sellSum;

    // slide window
    for (int l = 1; l + k - 1 < n; l++) {
        int prev = l - 1;
        int enterSell = l + k/2 - 1;
        int exitSell = l + k - 1;

        // remove old left
        oldSum -= (long long)strategy[prev] * prices[prev];

        // add new right
        oldSum += (long long)strategy[exitSell] * prices[exitSell];

        // update sellSum
        sellSum -= prices[enterSell];
        sellSum += prices[exitSell];

        long long curr = baseProfit - oldSum + sellSum;
        if (curr > maxProfit) {
            maxProfit = curr;
        }
    }

    return maxProfit;
}
