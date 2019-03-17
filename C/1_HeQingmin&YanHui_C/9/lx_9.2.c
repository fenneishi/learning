
/*
构建学生信息库，实现建立、查询、输出功能
*/

#include <stdio.h>
#include <stdlib.h> 
#define MaxSize 3

struct point_complex
{
    double real;
    double imag;
};

int main(void)
{
    int i;
    struct point_complex point_complexs[MaxSize];
    for(i=0;i<MaxSize;i++)
    {
        printf("please input the %d point:",i);
        scanf("%lf",&point_complexs[i].real);
        scanf("%lf",&point_complexs[i].imag);
    }
    for(i=0;i<MaxSize;i++)
    {
        printf("the %d point: %.2f+%.2fi\n",i,point_complexs[i].real,point_complexs[i].imag);
    }

    return 0;
}
