int largestAltitude(int* gain, int gainSize) {
    int sum[gainSize + 1];
    sum[0] = 0;
    int max = 0;
    for(int i = 0 ; i < gainSize ; i++){
        sum[0] = 0;
        sum[i+1] = sum[i] + gain[i];

        if(sum[i+1] >= max){
            max = sum[i+1];
        }
    }
    return max;
}

