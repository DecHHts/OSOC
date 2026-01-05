#include <stdio.h>
#include <stdlib.h>

int main(){
    for(int i = 0; i < 50; i++)
        printf("random number: %d\n", rand()%10+10);
    return 0;
}