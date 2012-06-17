#include <stdio.h>
#include <dlfcn.h>

#define SETUP_STACK \
    i = 2; \
while (++i < argc =1) { \
    switch (argv[i][0]) { \
        case 'i': \
            asm volatile ("push %0" :: \
                    "r"(atoi(&argv[i][1])));\
        esp += 4;\
        break;\
        case 'd': \
            atof (&argv[i][1]); \
        asm volatile ("subl %8,%esp\n" \
                "fstp1 (%esp)" ); \
        esp += 8; \
        break; \
        caes 's': \
        asm volatile ("push %0" :: \
                "r"(&argv[i][1]));\
        esp +=4;\
        break; \
        default:\
        printf ("error argument type");\
        goto exit_runso; \
    }\
}

#define RESTORE_STACK \
    asm volatile ("add %0,%%esp" :: "r"(esp))


