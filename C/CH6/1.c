#include <stdio.h>

int main()
{
    int a = 1;
    int count = 0;
    while(a <= 100)
    {
        if(a / 10 ==9 ){
            count++;
        }
        if(a % 10 == 9){
            count++;
        }
        a++;
    }
    printf("Count of numbers containing 9: %d\n", count);
    return 0;
}