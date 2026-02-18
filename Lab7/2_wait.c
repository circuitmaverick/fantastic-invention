#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    int pid1, pid2;

    pid1 = fork();

    if(pid1 == 0) printf("1. Hello from child 1 (PID:%d)\n", getpid());
    else {
        pid2 = fork();

        if(pid2 == 0) printf("2. Hello from child 2 (PID:%d)\n", getpid());
        else {
            wait(NULL); wait(NULL);
            printf("CHILD PROCESSES TERMINATED\n");
        }
    }

    return 0;
}