#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnaroundTime;
    bool completed;
    struct process *next, *prev;
} PROCESS;

PROCESS* getProcesses(int *count) {
    printf("Add more process? (Y/n): ");
    char c;
    scanf("%c", &c);
    if(c == 'n' || c == 'N') return NULL;
    PROCESS *new = (PROCESS*)malloc(sizeof(PROCESS));
    if(!new) { printf("\nINSUFFICIENT MEMORY\n");  return NULL; }
    // take input from the user about the process
    new->pid = ++*count;
    printf("Enter arrival time and burst time for process %d: ", *count);
    scanf("%d %d", &new->arrivalTime, &new->burstTime);
    new->completed = false; getchar();
    if(new->pid == 1) new->prev = NULL;
    new->next = getProcesses(count);
    if(new->next) new->next->prev = new;
    return new;
}

void displayProcesses(PROCESS *head) {
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    while(head) {
        printf("%d\t%d\t%d\t%d\t%d\n", head->pid, head->arrivalTime, head->burstTime, head->waitTime, head->turnaroundTime);
        head = head->next;
    }
}

void sortProcesses(PROCESS **head) {
    PROCESS *curr = *head;
    while(curr->next) {
        PROCESS *temp = curr->next;
        while(temp) {
            if(curr->arrivalTime > temp->arrivalTime) {
                PROCESS dummy = *temp;
                temp->pid = curr->pid;
                temp->arrivalTime = curr->arrivalTime;
                temp->burstTime = curr->burstTime;
                curr->pid = dummy.pid;
                curr->arrivalTime = dummy.arrivalTime;
                curr->burstTime = dummy.burstTime;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

PROCESS* getNextProcessToExecute(PROCESS *head, int currentTime) {
    PROCESS *shortest = NULL;
    while(head) {
        if(head->arrivalTime <= currentTime && !head->completed) {
            if(shortest && (shortest->burstTime > head->burstTime)) shortest = head;
            else shortest = head;
        }
        head = head->next;
    }
    return shortest;
}

int main() {
    int count = 0, completed = 0;
    PROCESS *head = getProcesses(&count);
    // set times and other attributes
    int currentTime = 0;
    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;
    while(completed<count) {
        // get the next process to execute
        PROCESS *execute = getNextProcessToExecute(head, currentTime);
        if(execute) {
            // if there exists a process in the current time, execute it
            execute->waitTime = currentTime - execute->arrivalTime;
            currentTime+=execute->burstTime;
            execute->turnaroundTime = execute->waitTime + execute->burstTime;
            totalTurnAroundTime+=execute->turnaroundTime;
            totalWaitTime += execute->waitTime;
            execute->completed = true;
            completed++;
        } else {
            // no process exists in the current time, increment current time by 1
            currentTime++;
        }
        // displayProcesses(head);
    }
    displayProcesses(head);
}
