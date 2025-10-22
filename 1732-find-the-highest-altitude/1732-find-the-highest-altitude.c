int largestAltitude(int* gain, int gainSize) {
    int sum = 0, final = 0;
    for(int i = 0 ; i < gainSize ; i++){
        sum = sum + gain[i];
        if(sum > final){
            final = sum;
        }
    }
    return final;
}
   