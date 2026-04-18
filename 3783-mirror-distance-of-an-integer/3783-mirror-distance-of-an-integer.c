int mirrorDistance(int n) {
    int org = n;
    int rem=0, rev=0;
    while (n != 0) {
        rem = n % 10;           
        rev = rev * 10 + rem; 
        n /= 10;                      
    }
    int sub = org - rev;
    return abs(sub);
}