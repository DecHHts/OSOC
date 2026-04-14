#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16];

void inst_cycle()
{
    uint8_t inst = *(uint8_t *)&M[PC];
    if(((inst >> 6) & 0x3) == 0)//add
    {
        R[(inst >> 4) & 0x3] = R[(inst >> 2) & 0x3] + R[inst & 0x3];
    } else if(((inst >> 6) & 0x3) == 1)// out rs
    {
        printf("R[%d]=%d\n",((inst >> 4) & 0x3), R[((inst >> 4) & 0x3)]);
    } else if(((inst >> 6) & 0x3) == 2)//li
    {
        R[(inst >> 4) & 0x3] = inst & 0xf;
    } else if(((inst >> 6) & 0x3) == 3)//bner0
    {
        if(R[0] != R[inst & 0x3])
        {
            PC = (inst >> 2) & 0xf;
            return;
        }
    } else
    {
        printf("Unsupported instruction\n");
    }
    PC += 1;
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    fread(M, 1, 16, fp);
    fclose(fp);
    if(argc >=3){
        printf("Max Number is set to %d\n", atoi(argv[2]));
        R[0] = atoi(argv[2]);
        PC = 1;
    } else
    {
        printf("Max Number is default 10\n");
    }
    for(int i = 0; i < 100; i++)
    {
        inst_cycle();
    }
    printf("r2 = %d\n", R[2]);
    return 0;
}
