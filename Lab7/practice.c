#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid = fork();

    if(pid == 0) printf("CHILD PROCESS\n");
    else if (pid > 0) {
        wait(NULL);
        printf("PARENT PROCESS\n");
    }
    else printf("CHILD PROCESS FAILED\n");

    return 0;
}