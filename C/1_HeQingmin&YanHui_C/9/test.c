

#include <stdio.h>
#include <stdlib.h> 





int main(void)
{   
    int array[3]={0,1,2};
    int *a;
    a=array;
    printf("int a = %d\n",*a);
    printf("int a = %d\n",*(a+1));
    printf("int a = %d\n",*(a+2));
    printf("int a = %d\n",*(a+3));
    printf("int a = %d\n",*(a+4));
    a=a+3;
    printf("int a = %d\n",*a);
    return 0;
}