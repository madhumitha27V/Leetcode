int mirrorDistance(int n) {
    while (n != 0) {
        remainder = n % 10;           
        reverse = reverse * 10 + remainder; 
        n /= 10;                      
    }

    return n - reverse;
}