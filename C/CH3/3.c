#include <stdio.h>
//无法改变i和j的值

void increment(int x)
{
    x = x + 1;
}

int main(){
    int i = 1, j = 2;
    increment(i);
    increment(j);
    printf("i = %d, j = %d\n", i, j);
    return 0;
}
//编译器按默认情况编译了printf，并将其视作int型，与实际不符