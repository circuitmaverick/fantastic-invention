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
    bool inQueue;
} PROCESS;

#define MAX 100


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
        p[i].completed = p[i].inQueue = false;
    }

    // initiate ready queue
    int front = 0, rear = 0;
    int queue[MAX];

    #define ENQUEUE(x) queue[rear++] = x
    #define DEQUEUE(x) queue[front++]

    // initiate completed count
    int completed = 0;

    // initiate current time and time quantum
    int ct = 0, tq;
    printf("Enter time quantum: "); scanf("%d", &tq);

    // add all the processes arrived at time 0 to the queue
    for(int i=0; i<count; i++)
        if(p[i].at == 0) {
            ENQUEUE(i);
            p[i].inQueue = true;
        }

    while(completed < count) {

        /* CPU IDLE */
        // if no process is in queue, increase current time and check any processes arrives then
        if(front == rear) {
            ct++;
            for(int i=0; i<count; i++)
                if(p[i].at <= ct && !p[i].completed && !p[i].inQueue) {
                    ENQUEUE(i);
                    p[i].inQueue = true;
                }
            continue;
        }

        /* EXECUTION */
        // get the first process is queue to execute
        int idx = DEQUEUE();

        // execute the process
        printf("EXECUTING PID%d\n", p[idx].pid);
        int execTime = (p[idx].rt > tq) ? tq : p[idx].rt;   // calculate execution time
        p[idx].rt -= execTime;
        ct += execTime;

        /* POST EXECUTION */

        // check arrived processes and also add those into the queue
        for(int i=0; i<count; i++)
            if(p[i].at <= ct && !p[i].completed && !p[i].inQueue) {
                ENQUEUE(i);
                p[i].inQueue = true;
            }

        // check if the process is executed completely
        if(p[idx].rt == 0) {    // if executed completely then calculate required properties
            p[idx].completed = true;
            p[idx].tat = ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        } else    // if not executed completely then insert it into the queue again
            ENQUEUE(idx);
    }

    // display
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < count; i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
}