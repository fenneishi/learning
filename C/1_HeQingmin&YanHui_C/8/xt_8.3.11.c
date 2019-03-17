
/*
统计各种字符各有多少
*/

#include <stdio.h>
#include <stdlib.h> 




int main(void)
{

    int n;
    int *a;
    int i;
    int sum,ave;
    int max,min;

    printf("input the count of students:");
    scanf("%d",&n);
    
    a=(int *)malloc(sizeof(int)*n);
    

    
    for(i=0;i<n;i++)
    {
        printf("please input the %d student grade:",i+1);
        scanf("%d",a+i);
    }
    
    sum=0;
    max=min=*(a);
    for(i=0;i<n;i++)
    {
        sum+=*(a+i);
        if(*(a+i)>max)max=*(a+i);
        if(*(a+i)<min)min=*(a+i);
    }
    printf("the average is :%f\n",sum*1.0/n);
    printf("the max is :%d\nthe min is :%0.2d\n",max,min);



    return 0;
}

