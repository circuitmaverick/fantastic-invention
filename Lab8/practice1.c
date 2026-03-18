#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if(pid == 0) {
        // child process task
        close(fd[1]);
        char buffer[50];
        read(fd[0], buffer, sizeof(buffer));
        printf("Read message: %s\n", buffer);
    } else {
        // parent process task
        close(fd[0]);
        char msg[] = "Hello World!";
        write(fd[1], msg, strlen(msg)+1);
    }
}