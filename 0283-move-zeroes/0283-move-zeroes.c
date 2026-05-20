void moveZeroes(int* nums, int numsSize) {
    int count = 0, k = 0;
    int new[numsSize];
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] != 0){
            new[k] = nums[i];
            k++;
        }
    }
    for(int i = 0 ; i < k-numsSize ; i++){
        new[k] = 0;
    }
    return new[k];
}