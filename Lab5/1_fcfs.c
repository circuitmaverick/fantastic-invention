#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnaroundTime;
    struct process* next;
} PROCESS;

PROCESS* getProcesses(PROCESS *head, int *count) {
    while(true) {
        PROCESS *new = (PROCESS*)malloc(sizeof(PROCESS));   // create process
        if(!new) { printf("\n\nINSUFFICIENT MEMORY\n\n"); return head; }    // check if process is created
        printf("Enter arrival time and burst time for process %d:", ++*count); scanf("%d %d", &new->arrivalTime, &new->burstTime);    // take input of process execution times
        new->pid = *count;  // set process id
        new->next = NULL;   // make this process the last one
        char c; getchar();  // initiate choice input character variable
        // add process to the linked list
        if(head) {
            PROCESS *temp = head;
            while(temp->next) temp=temp->next;
            temp->next = new;
        } else head=new;
        printf("Add process? (Y/n): "); scanf("%c", &c);
        if (c=='n' || c=='N') return head;
    }
}

int main() {
    int count = 0;  // initiate count
    int currentTime = 0;    // initiate current time
    int totalWaitTime = 0;  // inititate total wait time
    int totalTurnAroundTime = 0;    // initiate total turn around time
    PROCESS *processes = getProcesses(NULL, &count);    // take processes input in an empty linked list

    // execute the processes according to sjf algorithm
    PROCESS *temp = processes;
    while(temp) {
        // fix current time if no process has arrived in this current time
        if(currentTime < temp->arrivalTime) currentTime=temp->arrivalTime;

        // calculate the wait time for this process
        temp->waitTime = currentTime - temp->arrivalTime;

        // execute the current process till it's burst time
        printf("Executing process (PID:%d)\n", temp->pid);
        currentTime+=temp->burstTime;

        // calculate the turn around time for this process
        temp->turnaroundTime = temp->waitTime + temp->burstTime;

        // add to total wait time and total turn around time
        totalWaitTime += temp->waitTime;
        totalTurnAroundTime += temp->turnaroundTime;

        // move to next process
        temp=temp->next;
    }

    // display the table
    temp=processes;
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    while(temp) {
        printf("%d\t%d\t%d\t%d\t%d\n", temp->pid, temp->arrivalTime, temp->burstTime, temp->waitTime, temp->turnaroundTime);
        temp=temp->next;
    }
    printf("Average wait time: %.2fms\nAverage turnaround time: %.2fms\n", (float)totalWaitTime/count, (float)totalTurnAroundTime/count);
    return 0;
}