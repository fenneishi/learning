

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 


#define s(a,b,c) ((a)+(b)+(c))/2
#define area(s,a,b,c) pow((s)*((s)-(a))*((s)-(b))*((s)-(c)),1/2.0)
int main(void)
{  
    int a,b,c,s;
    printf("please input a,b,c:");
    scanf("%d,%d,%d",&a,&b,&c);
    printf("the area is %.3f\n",area(s(a,b,c),a,b,c));
    return 0;
}

