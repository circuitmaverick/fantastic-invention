#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct prc {
    int pid, at, bt, rt, wt, tat;
    bool completed;
    struct prc* next;
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
    scanf("%d %d", &new->at, &new->bt);
    new->completed = false; getchar();
    new->next = getProcesses(count);
    return new;
}

PROCESS *getNextProcess(PROCESS *process, int ct) {
    int minRT = INT_MAX;
    PROCESS *shortest = NULL;

    while(process) {
        if (process->at <= 0 && process->rt < minRT && !process->completed) shortest = process;
        process = process->next;
    }

    return shortest;
}

int getNextArrivalTime(PROCESS *process, int ct) {
    int nextAT = INT_MAX;

    while(process) {
        if(process->at >= ct && process->at < nextAT && !process->completed) nextAT = process->at;
        process = process->next;
    }

    return (nextAT == INT_MAX) ? -1 : nextAT;
}

void display(PROCESS *processes, int count) {
    int Ttat = 0, Twt = 0;
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    while(processes) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes->pid, processes->at, processes->bt, processes->wt, processes->tat);
        Ttat += processes->tat;
        Twt += processes->wt;
    }

    printf("Performance:\n\tAvg. Wait Time:\t%.2f\n\tAvg. Turnaround Time:\t%.2f", (float)Twt/count, (float)Ttat/count);
}

void srtf(PROCESS *processes, int count) {
    int ct =0, completed = 0;

    while(completed < count) {
        // get next process to execute
        PROCESS *exec = getNextProcess(processes, ct);

        // get next process arrival time
        int nextAT = getNextArrivalTime(processes, ct);

        // calculate how much time to execute the current process
        int execTime = (nextAT == -1) ? exec->rt : nextAT - ct;

        // execute the process
        ct+=execTime;
        exec->rt -= execTime;
        if(exec->rt == 0) {
            exec->completed = true;
            completed++;
            exec->tat = ct - exec->at;
            exec->wt = exec->tat - exec->bt;
        }
    }
}

int main() {
    // initializations
    PROCESS *processes; int count = 0;

    // input
    processes = getProcesses(&count);

    // execution in srtf
    srtf(processes, count);

    // display
    display(processes, count);
}