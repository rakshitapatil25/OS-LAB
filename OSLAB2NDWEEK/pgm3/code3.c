#include <stdio.h>

int main()
{
    int n,i,time=0,smallest,count=0;
    int at[20],bt[20],rt[20],ct[20],wt[20],tat[20],res[20];
    int flag[20]={0};
    float avgwt=0,avgtat=0,avgrt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d: ",i+1);
        scanf("%d",&at[i]);
    }

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    while(count<n)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        if(flag[smallest]==0)
        {
            res[smallest]=time-at[smallest];
            flag[smallest]=1;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0)
        {
            count++;
            ct[smallest]=time;

            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
        }
    }

    printf("\nProcess AT BT CT WT TAT RT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i],res[i]);

        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=res[i];
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Response Time = %.2f\n",avgrt/n);

    return 0;
}
