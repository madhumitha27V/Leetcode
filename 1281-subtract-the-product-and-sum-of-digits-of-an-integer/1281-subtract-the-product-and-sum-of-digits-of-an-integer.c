int subtractProductAndSum(int n) {
    int sum = 0 , pr = 1, a;
    while(n != 0){
        a = n % 10;
        sum = sum + a;
        pr = pr * a;
        n = n / 10;
    }
    return pr - sum;
}