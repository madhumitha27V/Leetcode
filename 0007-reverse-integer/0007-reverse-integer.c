#include<limits.h>
int reverse(int x){
    int a=0;
    long rev = 0;
    while(x != 0){
        a = x % 10;
        rev = rev * 10 + a;
        x = x / 10;

    }

    if(rev < INT_MIN || rev > INT_MAX){
        return 0;
    }
   return rev;
}