bool hasAlternatingBits(int n) {
    int prev = n % 2;
    n = n >> 1;
    int cu;
    while(n>0) {  
    cu = n % 2;
    if(cu == prev){
        return false;
    }  
    prev = cu;
    n >>=1;
}
return true;
}