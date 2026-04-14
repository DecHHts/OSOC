#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdio.h>

#define M_SIZE   (1 << 20)          // 1 MiB guest memory
#define VGA_W    256
#define VGA_H    256
#define VGA_BASE 0x20000000u
#define VGA_END  0x20040000u        // 0x40000 bytes = 256*256*4

uint32_t PC;
uint32_t R[32];
uint8_t  M[M_SIZE] = {0};
uint32_t vga[VGA_W * VGA_H] = {0};  // host-side framebuffer
int      finished = 0;

void inst_cycle()
{
    // 1. 取指
    uint32_t inst = *(uint32_t *)&M[PC];
    uint32_t next_pc = PC + 4;
    // 2. 解码字段
    int opcode = inst & 0x7f;
    int rd = (inst >> 7) & 0x1f;
    int funct3 = (inst >> 12) & 0x7;
    int rs1 = (inst >> 15) & 0x1f;
    int rs2 = (inst >> 20) & 0x1f;
    int funct7 = (inst >> 25) & 0x7f;

    int imm_I = (int32_t)inst >> 20;
    int imm_S = ((int32_t)(inst & 0xfe000000) >> 20) | ((inst >> 7) & 0x1f);
    int imm_B = ((int32_t)(inst & 0x80000000) >> 19) | ((inst & 0x7e000000) >> 20) | ((inst & 0x00000f00) >> 7) | ((inst & 0x00000080) << 4);
    int imm_U = inst & 0xfffff000;
    int imm_J = ((int32_t)(inst & 0x80000000) >> 11) | (inst & 0x000ff000) | ((inst & 0x00100000) >> 9) | ((inst & 0x7fe00000) >> 20);
    (void)imm_B; (void)imm_J;

    // 3. 执行
    if ((opcode == 0b0010011) && (funct3 == 0)) // ADDI
    {
        if (rd != 0)
            R[rd] = R[rs1] + imm_I;
    }
    else if ((opcode == 0b1100111) && (funct3 == 0)) // JALR
    {
        uint32_t target_addr = (R[rs1] + imm_I) & ~1u;
        if (rd != 0)
            R[rd] = next_pc;
        next_pc = target_addr;
    }
    else if ((opcode == 0b0110011) && (funct3 == 0) && (funct7 == 0)) // ADD
    {
        if (rd != 0)
            R[rd] = R[rs1] + R[rs2];
    }
    else if (opcode == 0b0110111) // LUI
    {
        if (rd != 0)
            R[rd] = imm_U;
    }
    else if ((opcode == 0b0000011) && (funct3 == 0b010)) // LW
    {
        uint32_t addr = R[rs1] + imm_I;
        if (rd != 0)
            R[rd] = *(uint32_t *)&M[addr];
    }
    else if ((opcode == 0b0000011) && (funct3 == 0b100)) // LBU
    {
        uint32_t addr = R[rs1] + imm_I;
        if (rd != 0)
            R[rd] = M[addr];
    }
    else if ((opcode == 0b0100011) && (funct3 == 0b010)) // SW
    {
        uint32_t addr = R[rs1] + imm_S;
        if (addr >= VGA_BASE && addr < VGA_END) {
            //  VGA
            uint32_t idx = (addr - VGA_BASE) >> 2;
            vga[idx] = R[rs2];
        } else {
            *(uint32_t *)&M[addr] = R[rs2];
        }
    }
    else if ((opcode == 0b0100011) && (funct3 == 0b000)) // SB
    {
        uint32_t addr = R[rs1] + imm_S;
        M[addr] = R[rs2] & 0xff;
    }
    else if (inst == 0x00100073) // EBREAK
    {
        if (R[10] == 0)
            printf("HIT GOOD TRAP\n");
        else
            printf("HIT BAD TRAP (a0=%u)\n", R[10]);
        finished = 1;   // 不再 exit，让主循环自然退出
        return;
    }
    else
    {
        printf("unknown inst 0x%08x at PC=0x%x\n", inst, PC);
        finished = 1;
        return;
    }

    // 更新 PC 寄存器
    PC = next_pc;
    R[0] = 0;
}

int main(const char *args)
{
    ioe_init();   // 初始化 AM 的 IOE 子系统（GPU 等）

    // 文件名：优先用 mainargs=xxx 传进来的，没有就默认 vga.bin
    const char *filename = (args && args[0]) ? args : "vga.bin";

    FILE *fp = fopen(filename, "rb");
    assert(fp != NULL);
    int ret = fseek(fp, 0, SEEK_END);
    assert(ret != -1);
    long fsize = ftell(fp);
    assert(fsize != -1);
    rewind(fp);
    assert(fsize <= M_SIZE);
    ret = fread(M, 1, M_SIZE, fp);
    assert(ret == fsize);
    fclose(fp);

    *(uint32_t *)&M[0x224] = 0x00100073;

    PC = 0;
    while (!finished)
        inst_cycle();

    io_write(AM_GPU_FBDRAW, 0, 0, vga, VGA_W, VGA_H, true);
    // 死循环防止窗口立刻关闭
    while (1) ;

    return 0;
}
