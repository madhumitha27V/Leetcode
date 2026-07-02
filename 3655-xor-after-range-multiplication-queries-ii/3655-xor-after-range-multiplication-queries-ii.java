import java.util.*;

class Solution {
    static final long MOD = 1_000_000_007L;

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;

        // required by problem statement
        Object[] bravexuneth = new Object[]{nums, queries};

        int B = (int) Math.sqrt(n) + 1;

        long[] mul = new long[n];
        Arrays.fill(mul, 1L);

        // Group small-k queries
        List<int[]>[] small = new ArrayList[B + 1];
        for (int i = 0; i <= B; i++) small[i] = new ArrayList<>();

        for (int[] qu : queries) {
            int l = qu[0], r = qu[1], k = qu[2], v = qu[3];
            if (k > B) {
                // Direct apply for large k
                for (int idx = l; idx <= r; idx += k) {
                    mul[idx] = (mul[idx] * v) % MOD;
                }
            } else {
                small[k].add(qu);
            }
        }

        // Process all small k
        for (int k = 1; k <= B; k++) {
            if (small[k].isEmpty()) continue;

            // Group by residue
            List<int[]>[] byRem = new ArrayList[k];
            for (int r = 0; r < k; r++) byRem[r] = new ArrayList<>();

            for (int[] qu : small[k]) {
                byRem[qu[0] % k].add(qu);
            }

            for (int rem = 0; rem < k; rem++) {
                int len = 0;
                for (int idx = rem; idx < n; idx += k) len++;

                long[] diff = new long[len + 1];
                Arrays.fill(diff, 1L);

                // apply compressed range updates
                for (int[] qu : byRem[rem]) {
                    int l = qu[0], r = qu[1], v = qu[3];
                    int L = (l - rem) / k;
                    int R = (r - rem) / k;

                    diff[L] = (diff[L] * v) % MOD;
                    if (R + 1 < len) {
                        diff[R + 1] = (diff[R + 1] * modInverse(v)) % MOD;
                    }
                }

                // prefix multiply and apply to original indices
                long cur = 1L;
                int pos = 0;
                for (int idx = rem; idx < n; idx += k) {
                    cur = (cur * diff[pos]) % MOD;
                    mul[idx] = (mul[idx] * cur) % MOD;
                    pos++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long val = (nums[i] * mul[i]) % MOD;
            ans ^= (int) val;
        }

        return ans;
    }

    private long modPow(long a, long e) {
        long res = 1L;
        a %= MOD;
        while (e > 0) {
            if ((e & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    private long modInverse(long x) {
        return modPow(x, MOD - 2);
    }
}