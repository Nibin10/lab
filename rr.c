#include<stdio.h>
void main()
{
    int i,n,bt[30],rem_bt[30],qt,count=0,temp=0,sq=0,wt[30],tat[30],tot_tat=0,tot_wt=0;
    printf("Enter the number of process : \n");
    scanf("%d",&n);
    printf("Enter the burst time of the process : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter the quantum time :\n");
    scanf("%d",&qt);
    while(1)
    {
        count=0;
        for(i=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
            {
                rem_bt[i]=rem_bt[i]-qt;
            }
            else
            {
                if(rem_bt[i]>=0)
                {
                    temp=rem_bt[i];
                    rem_bt[i]=0;
                }
            }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count)
        {
            break;
        }
    }
    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        tot_wt+=wt[i];
        tot_tat+=tat[i];
        printf("\n%d\t%d\t\t%d\t\t%d",i+1,bt[i],tat[i],wt[i]);
    }
    printf("\n");
    printf("Average waiting time %d\n",tot_wt/n);
    printf("Average turn around time %d\n",tot_tat/n);
}