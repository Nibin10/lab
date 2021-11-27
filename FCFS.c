#include<stdio.h>
int p[30],at[30],bt[30],ct[30],wt[30],tat[30],n,tot_tat=0,tot_wt=0,FCFS_tat=0,FCFS_wt=0,i;
void main()
{
    printf("Enter the number of process : ");
    scanf("%d",&n);
    printf("\nEnter the arrival time of each process :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst time of process \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
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
    printf("FSFS Algoritham \n");
    table(&FCFS_tat,&FCFS_wt);
    printf("Total turn around time =%d\n",FCFS_tat);
    printf("Average turn around time =%d\n",FCFS_tat/n);
    printf("Total waiting time =%d\n",FCFS_wt);
    printf("Average waiting time =%d\n",FCFS_wt/n);
}
void table(int *a,int *b)
{
    for(i=0;i<n;i++)
    {
            tat[i]=ct[i]-at[i];
            tot_tat=tot_tat+tat[i];
    }
    *a=tot_tat;
    for(i=0;i<n;i++)
    {
            wt[i]=tat[i]-bt[i];
            tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    printf("Process \tArrival time \tBurst time\tCompletion time \tTurn around time\tWaiting Time\n");
    for(i=0;i<n;i++)
    {
        printf("process[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

}
