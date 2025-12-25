int addDigits(int num) {
    while(num >=  10){
        int sum = 0,a;
    while(num > 0){
        a = num % 10;
        sum = sum + a;
        num = num / 10;
    }
    num = sum;
    }
    return num;
}
