int numJewelsInStones(char* jewels, char* stones) {
    int count = 0;
    for(int i = 0 ; jewels[i] ; i++){
        for(int j = 0 ; stones[j] ; j++){
            if(jewels[i] == stones[j]){
                count = count+1;
            }
        }
    }
    return count;
}