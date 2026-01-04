#include <stdio.h>
#include <math.h>

int is_leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

double myround(double x){
    int f = floor(x);
    int c = ceil(x);
    if((x - f) < (c - x)){
        return f;
    } else {
        return c;
    }
}

int main(){
    int year = 2025;
    if(is_leap_year(year)){
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    year = 2024;
    if(is_leap_year(year)){
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    double num = 3.6;
    printf("The rounded value of %.2f is %.2f\n", num, myround(num));
    num = 2.3;
    printf("The rounded value of %.2f is %.2f\n", num, myround(num));
    num = 4.5;
    printf("The rounded value of %.2f is %.2f\n", num, myround(num));
    return 0;
}