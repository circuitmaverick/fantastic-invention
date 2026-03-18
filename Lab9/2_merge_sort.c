#include <stdio.h>
#include <pthread.h>

#define MAX 10

int arr[MAX] = {38,27,43,3,9,82,10,5,6,11};

typedef struct {
    int left;
    int right;
} Range;

void merge(int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid+1, k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = temp[i];
}

void* merge_sort(void* arg) {
    Range *range = (Range*)arg;

    if(range->left < range->right) {
        int mid = (range->left + range->right)/2;

        Range left_part = {range->left, mid};
        Range right_part = {mid+1, range->right};

        pthread_t t1, t2;

        pthread_create(&t1, NULL, merge_sort, &left_part);
        pthread_create(&t2, NULL, merge_sort, &right_part);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        merge(range->left, mid, range->right);
    }

    pthread_exit(0);
}

int main() {
    Range range = {0, MAX-1};

    pthread_t thread;

    pthread_create(&thread, NULL, merge_sort, &range);
    pthread_join(thread, NULL);

    printf("Sorted array:\n");

    for(int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}