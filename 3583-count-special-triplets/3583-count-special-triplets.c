#define MOD 1000000007

int specialTriplets(int* nums, int numsSize) {
    long long count = 0;

    for (int j = 1; j < numsSize - 1; j++) {

        long long left = 0, right = 0;

        // count valid i
        for (int i = 0; i < j; i++) {
            if (nums[i] == 2 * nums[j])
                left++;
        }

        // count valid k
        for (int k = j + 1; k < numsSize; k++) {
            if (nums[k] == 2 * nums[j])
                right++;
        }

        count = (count + left * right) % MOD;
    }

    return count;
}
