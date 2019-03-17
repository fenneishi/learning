/*
1、front and end is where?
*/


#include  <stdio.h>
#include <stdlib.h> 
#include <string.h>




int main(void)
{
    int a;
    a=111;
    a=(int)malloc(10*sizeof(int));
    printf("a=%d",a);
    malloc(sizeof(double));
    return 0;
}

