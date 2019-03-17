

#include <stdio.h>
#include <stdlib.h> 



struct date
{
    int real,image;
}a,b,c;


int main(void)
{   
    a.real=3;
    a.image=4;
    b.real=5;
    b.image=6;

    c.real=a.real*b.real-a.image*b.image;
    c.image=a.real*b.image+a.image*b.real;

    printf("c=%d+%di\n",c.real,c.image);

    
    return 0;
}
