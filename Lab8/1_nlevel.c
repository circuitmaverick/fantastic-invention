#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int n = 4; // number of levels
    int i;
    int fd[2];
    char msg[100] = "Start";

    for(i = 0; i < n; i++) {
        pipe(fd);

        if(fork() == 0) {
            // Child process
            close(fd[1]);

            read(fd[0], msg, sizeof(msg));
            printf("Child %d received: %s\n", i+1, msg);

            strcat(msg, "->C");
        } else {
            // Parent process
            close(fd[0]);

            strcat(msg, "->P");
            write(fd[1], msg, strlen(msg)+1);

            wait(NULL);
            break;
        }
    }
    return 0;
}