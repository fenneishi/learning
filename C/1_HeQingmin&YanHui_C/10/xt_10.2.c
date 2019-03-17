

#include <stdio.h>
#include <stdlib.h> 




int f(int x,int n);
int pows(int y,int m);
int main(void)
{
    int x;
    int n;
    printf("please input the x :");
    scanf("%d", &x);
    printf("please input the n :");
    scanf("%d", &n);
    printf("===================================\n");
    printf("the result is %d:\n", f(x, n));
    return 0;
}

int f(int x,int n)
{
    int sum;
    int team1;
    int team2;
    if(n==1){sum=x;printf("f(%d, 1)=%d \n",x,x);}
    else 
    {
        printf("f(%d,%2d)=f(%d,%2d)+(-1)^%2d*(%d^%2d)\n",x,n,x,n-1,n-1,x,n);
        team1=f(x,n-1);
        team2=pows(-1,n-1)*pows(x,n);
        sum=team1+team2;  
        printf("f(%d,%2d)=%5d+%5d=%d\n",x,n,team1,team2,sum);
    }
    return sum;
}

int pows(int y,int m)
{
    int i;
    int res=1;
    for(i=1;i<=m;i++)
    {
        res=res*y;
    }
    return res;
}

