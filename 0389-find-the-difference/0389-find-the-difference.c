char findTheDifference(char* s, char* t) {
    int sum1 = 0 ,sum2 = 0 ,mnum; 
    for(int i = 0 ; s[i] != '\0' ; i++){
        sum1 = sum1 + s[i];
    }
    for(int i = 0 ; t[i] != '\0' ; i++){
        sum2 = sum2 + t[i];
    }
    mnum = (char)(sum2 - sum1);
    
    return mnum;
}
