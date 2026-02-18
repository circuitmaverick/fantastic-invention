#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct process {
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    bool completed;
} PROCESS;

void push(PROCESS *readyQ[], PROCESS *p, int *front, int *rear) {

}


int main() {
    // input
    int count = 0;
    printf("Enter number of processes: ");
    scanf("%d", &count);
    PROCESS p[count];
    printf("Enter the arrival time and burst time respectively for the processes according to their PIDs---\n");
    for(int i=0; i<count; i++) {
        p[i].pid = i+1;
        printf("Process PID%d\t>\t", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = false;
    }

    // initiate ready queue
    int front = -1, rear = -1;
    PROCESS *readyQ[count];

    // initiate completed count
    int completed = 0;

    // initiate current time and time quantum
    int ct = 0, tq;
    printf("Enter time quantum: "); scanf("%d", &tq);

    while(completed != count) {
        // check arrived processes and copy to ready queue
        for(int i=0; i<count; i++) {
            if(p[i].at <= ct && !p[i].completed) {
                // push the process into ready queue
                rear = (rear+1)%count;
                if(rear==front) { printf("\nQUEUE IS FULL\n"); exit(0); }
                if(front == -1) front++;

                // check if more than one process exists in the ready queue of the same arrival time,
                // then sort those according to less remaining time
                if(front != rear) {
                    if(p[rear])
                }
            }
        }
    }

    // display
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < count; i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
}