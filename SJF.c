#include<stdio.h>
int p[30],bt[30],tot_tat=0,wt[30],ct[30],at[30],n,tot_wt=0,tat[30],SJF_wt=0,SJF_tat=0,i,j,t;
void main()
{
    printf("\nEnter the no.of processes \n");
    scanf("%d",&n);
    printf("\nEnter the arrival time of each process :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter burst time for each process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i] = i;
    }
    sort();
    for(i=0;i<n;i++)

    {
        if(i==0)
        {
            ct[i]=bt[i];
        }
        else
        {
            ct[i]=ct[i-1]+bt[i];
        }
    }
    WT_TAT(&SJF_tat,&SJF_wt);
    printf("\n\nTotal Turn around Time:%d",SJF_tat);
    printf("\nAverage Turn around Time :%d ", SJF_tat/n);
    printf("\nTotal Waiting Time:%d",SJF_wt);
    printf("\nTotal avg. Waiting Time:%d",SJF_wt/n);
}

void sort()
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(&bt[j],&bt[i]);
                swap(&p[j],&p[i]);
                swap(&at[j],&at[i]);
            }
        }
    }
}
void swap(int *a, int *b)
{
    t = *a;
    *a = *b;
    *b = t;
}
int WT_TAT(int *a, int *b)
{
    int i;
    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        tot_tat=tot_tat+tat[i];
    }
    *a = tot_tat;
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        tot_wt = tot_wt+wt[i];
    }
    *b = tot_wt;
    printf("Process \tArrival time \tBurst time\tCompletion time \tTurn around time\tWaiting Time\n");
    for(i=0;i<n;i++)
    {
        printf("process[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

}
