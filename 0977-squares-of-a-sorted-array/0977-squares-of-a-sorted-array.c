/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
      int* result = (int*)malloc(numsSize * sizeof(int)); 
      *returnSize = numsSize;
      for(int i = 0 ; i < numsSize ; i++){
        result[i] = nums[i] * nums[i];
      }
    
     for (int i = 1 ; i < numsSize ;i++){
        int key = result[i];
        int j = i - 1;
        while(j >= 0 && result[j] > key){
            result[j+1] = result[j];
            j--;
            
        }
        result[j+1] = key;
    }
    return result;
}