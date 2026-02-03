bool isTrionic(int* nums, int numsSize) {

    int count_inc = 0, count_dec = 0;
    for(int i = 1 ; i < numsSize ; i++){

        if(nums[i] > nums[i-1]){
            count_inc = count_inc + 1;
        }
        else{
            count_dec = count_dec + 1;
        }
    }

    int sum = count_inc + count_dec;
    
    if(sum == 3){
        return true;
    }
        return false;
}