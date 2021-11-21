#include<stdio.h>
int p[30],bt[30],wt[30],tat[30],n,tot_tat=0,tot_wt=0,FCFS_tat=0,FCFS_wt=0,i;
void main()
{
    printf("Enter the number of process :");
    scanf("%d",&n);
    printf("Enter the burst time of process \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
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
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else
        {
            tat[i]=tat[i-1]+bt[i];
            tot_tat=tot_tat+tat[i];
        }
    }
    *a=tot_tat;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
            wt[i]=wt[i-1]+bt[i-1];
            tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    printf("Process \tBurst time\tTurn around time\tWaiting Time\n");
    for(i=0;i<n;i++)
    {
        printf("process[%d]\t\t%d\t\t%d\t\t%d\n",i,bt[i],tat[i],wt[i]);
    }

}
