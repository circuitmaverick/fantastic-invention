#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int main() {
    int n = 4;
    int pipes[n][2];
    char msg[100] = "Token";
    int i;

    // Create pipes
    for(i = 0; i < n; i++) {
        pipe(pipes[i]);
    }

    // Create processes
    for(i = 0; i < n; i++) {
        if(fork() == 0) {
            int id = i;

            // Read from previous pipe
            read(pipes[id][0], msg, sizeof(msg));
            printf("Process %d received: %s\n", id, msg);

            strcat(msg, "->P");

            // Write to next pipe (ring)
            write(pipes[(id+1)%n][1], msg, strlen(msg)+1);

            return 0;
        }
    }

    // Initial message
    write(pipes[0][1], msg, strlen(msg)+1);

    for(i = 0; i < n; i++) wait(NULL);

    return 0;
}