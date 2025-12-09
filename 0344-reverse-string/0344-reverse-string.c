void reverseString(char* s, int sSize) {
    int result[sSize];
    int k = 0;
    for(int i = sSize - 1; i >= 0 ; i--){
        result[k] = s[i];
        k++;
    }
    for(int i = 0 ; i < sSize ; i++){
        s[i] = result[i];
    }
}


