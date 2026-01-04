#include <stdio.h>

int GCD(int a, int b){
    if(b == 0){
        return a;
    } else if(a % b == 0)
    {
        return b;
    } else{
        return GCD(b, a % b);
    }
}
int Fibonacci(int n){
    if(n == 0){
        return 0;
    } else if(n == 1){
        return 1;
    } else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
int main(){
    int a = 56;
    int b = 98;
    printf("The GCD of %d and %d is %d\n", a, b, GCD(a, b));
    a = 101;
    b = -10;
    printf("The GCD of %d and %d is %d\n", a, b, GCD(a, b));
    
    int n = 10;
    printf("The %dth Fibonacci number is %d\n", n, Fibonacci(n));
    n = 20;
    printf("The %dth Fibonacci number is %d\n", n, Fibonacci(n));
    return 0;
}