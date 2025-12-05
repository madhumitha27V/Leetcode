class Solution {
    public int[] replaceElements(int[] arr) {
        int arrSize = arr.length;
        int[] sum = new int[arrSize];

        for (int i = 0; i < arrSize - 1; i++) {
            int max = arr[i + 1];

            for (int j = i + 1; j < arrSize; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                }
            }
            sum[i] = max;
        }

        sum[arrSize - 1] = -1;   

        return sum;
    }
}
