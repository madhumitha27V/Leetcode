#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int used[1000] = {0};   
    int freq[1000];
    int freqSize = 0;

    for (int i = 0; i < arrSize; i++) {
        if (used[i]) continue;

        int count = 0;
        for (int j = i; j < arrSize; j++) {
            if (arr[i] == arr[j]) {
                count++;
                used[j] = 1;
            }
        }

        for (int k = 0; k < freqSize; k++) {
            if (freq[k] == count)
                return false;
        }

        freq[freqSize++] = count;
    }

    return true;
}
