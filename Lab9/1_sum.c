#include<stdio.h>
#include<pthread.h>

typedef struct data {
    int size;
    int *arr;
    int sum;
} DATA;

void* first_half(void* arg) {
    DATA* data = (DATA*) arg;

    for(int i=0; i<data->size/2; i++)
        data->sum += data->arr[i];

    pthread_exit(0);
}

void* last_half(void* arg) {
    DATA* data = (DATA*) arg;

    for(int i=data->size/2; i<data->size; i++)
        data->sum += data->arr[i];

    pthread_exit(0);
}

int main() {

    int arr[10] = { 9, 1, 3, 6, 3, 7, 9, 3, 6, 12 };

    DATA d1, d2;

    d1.arr = arr;
    d1.size = 10;
    d1.sum = 0;

    d2.arr = arr;
    d2.size = 10;
    d2.sum = 0;

    pthread_t tid_first, tid_last;

    pthread_create(&tid_first, NULL, first_half, &d1);
    pthread_create(&tid_last, NULL, last_half, &d2);

    pthread_join(tid_first, NULL);
    pthread_join(tid_last, NULL);

    printf("\nFirst half sum:\t%d\n", d1.sum);
    printf("\nLast half sum:\t%d\n", d2.sum);

    printf("\nTotal sum:\t%d\n", d1.sum+d2.sum);

    return 0;
}