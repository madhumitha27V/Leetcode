/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findThePrefixCommonArray(int* A, int ASize,
                              int* B, int BSize,
                              int* returnSize) {

    int *ans = (int*) malloc(ASize * sizeof(int));

    int freq[51] = {0};

    int common = 0;

    for(int i = 0; i < ASize; i++) {

        freq[A[i]]++;

        if(freq[A[i]] == 2) {
            common++;
        }

        freq[B[i]]++;

        if(freq[B[i]] == 2) {
            common++;
        }

        ans[i] = common;
    }

    *returnSize = ASize;

    return ans;
}