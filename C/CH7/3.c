#include <stdio.h>

enum coordinate_type {RECTANGULAR = 1, POLAR};

int main(){
    int RECTANGULAR;
    printf("%d %d\n", RECTANGULAR, POLAR);
    return 0;
}
//enum与变量共用同一个命名空间