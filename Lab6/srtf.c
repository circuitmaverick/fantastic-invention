#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int pid;
    int at;      // Arrival Time
    int bt;      // Burst Time
    int rt;      // Remaining Time
    int wt;      // Waiting Time
    int tat;     // Turnaround Time
    bool completed;
} PROCESS;

/* Get process with minimum remaining time at current time */
PROCESS* getNextProcess(PROCESS p[], int n, int ct) {
    PROCESS *shortest = NULL;
    int minRT = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(p[i].at <= ct && !p[i].completed && p[i].rt < minRT) {
            minRT = p[i].rt;
            shortest = &p[i];
        }
    }
    return shortest;
}

/* Get next arrival time after current time */
int getNextArrivalTime(PROCESS p[], int n, int ct) {
    int nextAT = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(p[i].at > ct && !p[i].completed && p[i].at < nextAT)
            nextAT = p[i].at;
    }

    return (nextAT == INT_MAX) ? -1 : nextAT;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    PROCESS p[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = false;
    }

    int ct = 0;            // Current time
    int completed = 0;

    while(completed < n) {
        PROCESS *cur = getNextProcess(p, n, ct);

        /* CPU idle */
        if(cur == NULL) {
            ct++;
            continue;
        }

        int nextAT = getNextArrivalTime(p, n, ct);

        /* No future arrival → execute fully */
        if(nextAT == -1 || ct + cur->rt <= nextAT) {
            ct += cur->rt;
            cur->rt = 0;
            cur->completed = true;
            completed++;

            cur->tat = ct - cur->at;
            cur->wt  = cur->tat - cur->bt;
        }
        /* Preemption occurs */
        else {
            int execTime = nextAT - ct;
            cur->rt -= execTime;
            ct = nextAT;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    return 0;
}
