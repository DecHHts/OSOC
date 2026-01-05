#include <stdio.h>

int diamond(int n){
    if(n % 2 == 0){
        printf("Number must be odd!\n");
        return 1;
    }
    int gap = 0;
    for(int i = 1; i <= n; i++){
        if(i <= (n/2+1)){
            gap = (n/2+1) - i;
        }
        else{
            gap = i - (n/2+1);
        }
        for(int j = 1; j <= n; j++){
            if(j <= gap || j > n - gap){
                printf(" \t");
            }
            else{
                printf("*\t");
            }
        }
        printf("\n");
    }
    return 0;
}

int main(){
    for(int i = 1; i<= 9; i++)
    {
        for(int j = 1; j <= i; j++){
            printf("%d*%d=%d \t", j, i, i*j);
        }
        printf("\n");
    }
    int n = 8;
    int m = 9;
    diamond(n);
    printf("\n");
    diamond(m);
    return 0;
}