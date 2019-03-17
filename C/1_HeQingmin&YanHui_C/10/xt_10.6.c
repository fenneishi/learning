

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 




int inver(int n);
int count=0;
int main(void)
{  
    int n,i;
    printf("please input the n :");
    scanf("%d",&n);
    printf("===================================\n");
    printf("res is %d \n",inver(n));
    return 0;
}



int inver(int n)
{
    int res;
    if(n==0)
    {
        res = 0;
        count =0;
    }
    else
    {
        res=inver(n/10)+(n%10)*pow(10,count);
        count++;
    }
    return res;
}