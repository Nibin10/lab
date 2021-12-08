#include<stdio.h>
#include<stdlib.h>
void main()
{
    int f[30],i,in[30],b,n,count,ch;
    for(i=0;i<30;i++)
    {
        f[i]=0;
        in[i]=0;
    }
    x:printf("Enter the index block : \n");
    scanf("%d",&b);
    if(f[b]==0)
    {
        printf("Enter the number of blocks needed and no: of files for the index %d on the disk :",b);
        scanf("%d",&n);
    }
    else
    {
        printf("already allocated");
        goto x;
    }
    y:count=0;
    f[b]=1;
    printf("Enter the index ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
        if(f[in[i]]==0)
        {
            count++;
        }
    }
    if(count==n)
    {
        printf("alocated \n");
        printf("file indexed \n");
        for(i=0;i<n;i++)
        {
            f[in[i]]=1;
            printf("%d------%d:%d\n",b,in[i],f[in[i]]);
        }
        printf("do you want to enter more files :(yes =1)(no =0)\n");
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
        printf("already alocated \n");
        printf("Enter another file indexed \n");
        goto y;
    }

}