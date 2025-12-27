int reverse(int x) {
    int rev = 0;
    int a;
    while (x != 0) {
        a = x % 10;
        rev = rev * 10 + a;
        x = x / 10;
    }
    if(rev < INT_MIN || rev > INT_MAX){
        return 0;
    }
    return rev;

}
