#define MOD 1000000007

int countPermutations(int* complexity, int n) {
    int root = complexity[0];

    for (int i = 1; i < n; i++) {
        if (complexity[i] <= root) {
            return 0;
        }
    }

    long long ans = 1;
    for (int i = 1; i <= n - 1; i++) {
        ans = (ans * i) % MOD;
    }

    return (int)ans;
}
