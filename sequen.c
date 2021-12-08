#include<stdio.h>
#include<stdlib.h>
int ch,i,s,n,file[30];
void main()
{
    printf("files alocted are  :\n ");
    for(i=0;i<30;i++)
    {
        file[i]=0;
    }
    seq();
    
}
void seq()
{
    int flag=0;
    printf("Enter the starting block : ");
    scanf("%d",&s);
    printf("Enter the length of the file : ");
    scanf("%d",&n);
    
    for(i=s;i<(s+n);i++)
    {
        if(file[i]==0)
        {
            flag++;
        }
    }
    if(flag==n)
    {
        for(i=s;i<(s+n);i++)
        {
            if(file[i]==0)
            {
                file[i]=1;
                printf("file alocate %d \t %d \n",i,file[i]);
            }
        }
    }
    else
    {
        printf("do not allocate this \n");
    }
    printf("Do you want to enter more files : \n");
    printf("press 1 for yes , 0 for No \n");
    scanf("%d",&ch);
    if(ch==1)
    {
        seq();
    }
    else
    {
        exit(0);
    }

}