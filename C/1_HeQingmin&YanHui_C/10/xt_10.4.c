

#include <stdio.h>
#include <stdlib.h> 




int fb(int n);
int fb2(int n);
int main(void)
{  
    int n,i;
    printf("please input the n :");
    scanf("%d",&n);
    printf("===================================\n");
    printf("the result is %d:\n",fb(n));
    for(i=0;i<=n;i++)printf("%d,",fb2(i));
    printf("\n");
    return 0;
}

int fb(int n)
{
    int res;
    int team1;
    int team2;

    if(n==0||n==1)
    {
        res=1;
        printf("fb(%d)=%d \n",n,res);
    }
    else 
    {
        printf("fb(%d)=fb(%d-1)+fb(%d-2) \n",n,n,n);
        team1=fb(n-1);
        team2=fb(n-2);
        res=team1+team2;
        printf("fb(%d)=fb(%d-1)+fb(%d-2)=%d+%d=%d \n",n,n,n,team1,team2,res);
    }
    
    return res;
}

int fb2(int n)
{
    int res;
    int team1;
    int team2;

    if(n==0||n==1)
    {
        res=1;
    }
    else 
    {
        team1=fb2(n-1);
        team2=fb2(n-2);
        res=team1+team2;
    }
    
    return res;
}