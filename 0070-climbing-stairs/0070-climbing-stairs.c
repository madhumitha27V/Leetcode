
    int climbStairs(int n) {

    int a = 0 , b  = 1, sum;

    if(n == 1 || n == 2 || n == 3)
        return n; 

    for(int i = 0 ; i < n ; i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    
    return sum;

}

