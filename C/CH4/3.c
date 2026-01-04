#include <stdio.h>

int main() {
    //(1)
    int x = 10;
    if (x<=0||x>=10){
        printf("x is out of range\n");
    }

    //(2)
    int y = 5;
    if(x<=0 && y<=0){
        printf("Test is Failed!\n");
    }
    else{
        printf("Test is OK!\n");
    }

    //(3)
    //x=1 || y=1

    //(4)
    //if(x>=3 && y>=3) can be deleted
    return 0;
}