
/*
写出下列程序的执行结果
0 0
1 2 
2 4
0 0 
2 3 
4 6
*/

#include <stdio.h> 
int main(void)
{
    int a[10], b[10], *pa, *pb, i;
    pa = a;
    pb = b;
    for (i = 0; i < 3; i++, pa++, pb++)
    {
        *pa = i;
        *pb = 2 * i;
        printf("%d\t%d\n", *pa, *pb);
    }
    pa = &a[0];
    pb = &b[0];
    for (i = 0; i < 3; i++)
    {
        *pa = *pa + i;
        *pb = *pb + i;
        printf("%d\t%d\n", *pa++, *pb++);
    }
    return 0;
}