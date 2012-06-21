#include <stdio.h>


#define PRELOG(a0, a1, a2, a3, a4, a5, a6, a7)\
    asm volatile (\
            "move $4, %[aa0]\n"\
            "move $5, %[aa1]\n"\
            "move $6, %[aa2]\n"\
            "move $7, %[aa3]\n"\
            "move $8, %[aa4]\n"\
            "move $9, %[aa5]\n"\
            "move $10, %[aa6]\n"\
            "move $11, %[aa7]\n"\
            :\
            :[aa0] "d" (a0), [aa1] "d" (a1), [aa2] "d" (a2),\
             [aa3] "d" (a3), [aa4] "d" (a4), [aa5] "d" (a5),\
             [aa6] "d" (a6), [aa7] "d" (a7)\
            );

#define PRELOG1(a0) PRELOG(a0,0,0,0,0,0,0,0)
#define PRELOG2(a0,a1) PRELOG(a0,a1,0,0,0,0,0,0)
#define PRELOG3(a0,a1,a2) PRELOG(a0,a1,a2,0,0,0,0,0)
#define PRELOG4(a0,a1,a2,a3) PRELOG(a0,a1,a2,a3,0,0,0,0)
#define PRELOG5(a0,a1,a2,a3,a4) PRELOG(a0,a1,a2,a3,a4,0,0,0)
#define PRELOG6(a0,a1,a2,a3,a4,a5) PRELOG(a0,a1,a2,a3,a4,a5,0,0)
#define PRELOG7(a0,a1,a2,a3,a4,a5,a6) PRELOG(a0,a1,a2,a3,a4,a5,a6,0)
#define PRELOG8(a0,a1,a2,a3,a4,a5,a6,a7) PRELOG(a0,a1,a2,a3,a4,a5,a6,a7)

int main (int argc, char *argv[])
{
    unsigned long value1 = (unsigned long)argv[1];
    unsigned long value2 = (unsigned long)argv[2];
    unsigned long value3 = (unsigned long)argv[3];
    PRELOG1(value1);
    PRELOG2(value1,value2);
    PRELOG3(value1,value2,value3);
    return 0;
}
