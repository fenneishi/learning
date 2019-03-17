

#include <stdio.h>
#include <stdlib.h> 




int f(int n);
int g(int m);
int main(void)
{   
    int n;
    printf("input n:");
    scanf("%d",&n);
    printf("the count is %d\n",f(n));

    return 0;
}

int f(int n)
{
    int cout=0,i;
    for(i=11;(i*i)<=n;i++)
    {
        if(g(i*i))
        {
            cout++;
            printf("pow(%d)=%d\n",i,i*i);
        }
    };
    return cout;
}

int g(int m)
{
    int i,j,k;
    i=m/100;
    j=m%100/10;
    k=m%100%10/1;

    if(i==k) return 1;
    if(i==j) return 1;
    if(j==k) return 1;
    return 0;
}