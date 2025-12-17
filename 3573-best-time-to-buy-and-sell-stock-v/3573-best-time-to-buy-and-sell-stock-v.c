#define NEG_INF (-1000000000000000000LL)

long long maximumProfit(int* prices, int n, int k) {
    long long dp[k + 1][3];

    for (int t = 0; t <= k; t++) {
        dp[t][0] = 0;
        dp[t][1] = NEG_INF;
        dp[t][2] = NEG_INF;
    }

    for (int i = 0; i < n; i++) {
        for (int t = k; t >= 1; t--) {

            if (dp[t][1] != NEG_INF) {
                long long val = dp[t][1] + prices[i];
                if (val > dp[t][0]) dp[t][0] = val;
            }

            if (dp[t][2] != NEG_INF) {
                long long val = dp[t][2] - prices[i];
                if (val > dp[t][0]) dp[t][0] = val;
            }

            long long buy = dp[t - 1][0] - prices[i];
            if (buy > dp[t][1]) dp[t][1] = buy;

            long long shortSell = dp[t - 1][0] + prices[i];
            if (shortSell > dp[t][2]) dp[t][2] = shortSell;
        }
    }

    return dp[k][0];
}
