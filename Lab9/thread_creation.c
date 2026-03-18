#include<stdio.h>
#include<pthread.h>

void *print_message(void *arg) {
    printf("Hello from thread\n");
}

int main() {
    pthread_t tid;

    pthread_create(&tid,NULL, print_message, NULL);

    pthread_join(tid, NULL);

    printf("Thread execution successful!\n");

    return 0;
}