#include <stdio.h>

void print_last_two_digits(int x)
{
    int last_digit = x % 10;
    int second_last_digit = (x / 10) % 10;
    printf("The last digit of %d is %d\n", x, last_digit);
    printf("The second last digit of %d is %d\n", x, second_last_digit);
}

int main(){
    int x = 893;
    int y = 634;
    int a = 893 % 10;
    printf("The last digit of %d is %d\n", x, a);
    int b = (x / 10) % 10;
    printf("The second last digit of %d is %d\n", x, b);

    print_last_two_digits(y);
    return 0;
}