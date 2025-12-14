#define MOD 1000000007

int numberOfWays(char* corridor) {
    long long ways = 1;
    int seats = 0;
    int plants = 0;

    for (int i = 0; corridor[i]; i++) {
        if (corridor[i] == 'S') seats++;
    }

    if (seats == 0 || seats % 2 != 0) return 0;

    int seatCount = 0;

    for (int i = 0; corridor[i]; i++) {
        if (corridor[i] == 'S') {
            seatCount++;

            if (seatCount == 2) {
                seatCount = 0;

                plants = 0;
                int j = i + 1;
                while (corridor[j] && corridor[j] == 'P') {
                    plants++;
                    j++;
                }

                if (corridor[j]) {
                    ways = (ways * (plants + 1)) % MOD;
                }
            }
        }
    }

    return (int)ways;
}
