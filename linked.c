#include<stdio.h>
#include<stdlib.h>
int file[30],i,n,st,in[30],count=0,ch;
void main()
{
    for(i=0;i<30;i++)
    {
        file[i]=0;
        in[i]=0;
    }
    link();
}
void link()
{
    x:printf("Enter the index of starting block :");
    scanf("%d",&st);
    printf("Enter the number of index block :");
    scanf("%d",&n);
    count=0;
    if(file[st]==0)
    {
        printf("Enter the index :\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&in[i]);
            if(file[in[i]]==0)
            {
                count++;
            }
        }
        if(count==n)
        {
            file[st]=1;
            printf("Allocated are :\n");
            printf("%d",st);
            for(i=0;i<n;i++)
            {
                file[in[i]]=1;
                printf("-------%d",in[i]);
            }
            printf("\n");
            printf("do you want to enter more files :(yes =1):(no=0)");
            scanf("%d",&ch);
            if(ch==1)
            {
                goto x;
            }
            else
            {
                exit(0);
            }                                                         
        }
        else
        {
            printf("already allocated");
            goto x;
        }
    }
    else
    {
        printf("Already alocated \n");
        goto x;
    }

}