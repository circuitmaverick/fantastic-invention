#include<stdio.h>
#include<unistd.h>

int main() {
    fork();
    fork();
    printf("Hello from process %d\n", getpid());
    return 0;
}