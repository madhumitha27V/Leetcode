/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    int k = 0;
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] % 2 == 0){
        arr[k] = nums[i];
        k++;
        }
    }
    for(int j = 0 ; j < numsSize; j++){
        if(nums[j] % 2 != 0){
            arr[k] = nums[j];
            k++;
        }
    }
    *returnSize = numsSize;
    return arr;
}

