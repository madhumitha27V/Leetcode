/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
int* result = (int*)malloc(arrSize * sizeof(int));
*returnSize = arrSize;

    int maxRight = -1; 
    for (int i = arrSize - 1; i >= 0; i--) {
        result[i] = maxRight;       
        if (arr[i] > maxRight) {
            maxRight = arr[i];       
        }
    }

    return result;
}
