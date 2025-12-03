/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int *sum = (int*) malloc(numsSize * sizeof(int));   // heap memory
    int k = 0;
    int s = 0;
    for(int i = 0 ; i < numsSize ; i++){
        s = s + nums[i];
        sum[k] = s;
        k++;
    }
    *returnSize = numsSize;
    return sum;
}

//pointer = (type*) malloc(size_in_bytes);


    
