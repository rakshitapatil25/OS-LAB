
#include <stdio.h>

int main() {
    int n, i, time = 0, tq;
    int bt[20], rt[20], wt[20], tat[20];
    int remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;


    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    i = 0;


    while(remain > 0) {
        if(rt[i] > 0 && rt[i] <= tq) {
            time += rt[i];
            rt[i] = 0;
            remain--;

            tat[i] = time;
            wt[i] = tat[i] - bt[i];
        }
        else if(rt[i] > tq) {
            rt[i] -= tq;
            time += tq;
        }


        if(i == n - 1)
            i = 0;
        else
            i++;
    }


    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

