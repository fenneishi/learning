

#include <stdio.h>
#include <stdlib.h> 




int ack(int m,int n);
int main(void)
{   
    int m;
    int n;
    printf("please input the m :");
    scanf("%d",&m);
    printf("please input the n :");
    scanf("%d",&n);
    printf("===================================\n");
    printf("the result is %d:\n",ack(m,n));
    return 0;
}

int ack(int m,int n)
{
    int res;
    int team1;

    if(m==0)
    {
        res=n+1;
        printf("ack(%d,%d)=%d \n",m,n,res);
    }
    if(n==0&&m>0)
    {
        printf("ack(%d,%d)=ack(%d-1,1) \n",m,n,m);
        res=ack(m-1,1);
        printf("ack(%d,%d)=ack(%d-1,1)=%d \n",m,n,m,res);
    }
    if(m>0&&n>0)
    {
        printf("ack(%d,%d)=ack(%d-1,ack(%d,%d-1)) \n",m,n,m,m,n);
        team1=ack(m,n-1);
        res=ack(m-1,team1);
        printf("ack(%d,%d)=ack(%d-1,ack(%d,%d-1))=ack(%d-1,%d)=%d \n",m,n,m,m,n,m,team1,res);
    }
    
    return res;
}

