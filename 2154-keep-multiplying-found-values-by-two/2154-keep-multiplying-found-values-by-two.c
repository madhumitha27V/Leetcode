int findFinalValue(int* nums, int numsSize, int original) {
    int flag = 1;
    while(flag){
        flag = 0;
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] == original){
            original = 2 * original;
            flag = 1;
            break;
        }
    }
}
return original;
}