class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 1;
        for(int i = 0 ; i < nums.length-2 ; i++){
            if(nums[i] != nums[i+1]){
                nums[k++] = nums[i];
            }

        }
        //nums[k+1] = nums[nums.length-1];
        return k;
    }
}

