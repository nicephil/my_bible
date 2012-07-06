#include <sys/ptrace.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define INJECT_PID 834

int main (int argc, char *argv[])
{
    long a = 0;
    int status = 0;
    int pid = 0;
    long err = 0;
    long data = 0;
    long addr = 0;
    err = ptrace (PTRACE_ATTACH, INJECT_PID, NULL, NULL);
    if (-1 == err) {
        printf ("attach\n");
        exit (-1);
    }
    
    printf ("before waitpid 1\n");
    pid = waitpid (INJECT_PID, &status, __WALL);
    printf ("after waitpid 1\n");
#if 1
    {
        addr = 0x0804841c;
        err = ptrace (PTRACE_PEEKTEXT, INJECT_PID, addr, NULL);
        if (-1 == err) {
            printf ("cont\n");
            exit (-2);
        }
        printf ("0x%08x\n", err);
    }

    printf ("before waitpid 2\n");
    pid = waitpid (INJECT_PID, &status, __WALL);
    printf ("after waitpid 2\n");
#endif

    err = ptrace (PTRACE_DETACH, INJECT_PID, NULL, NULL);
    if (-1 == err) {
        printf ("detach\n");
        exit (-3);
    }

    return 0;
}

