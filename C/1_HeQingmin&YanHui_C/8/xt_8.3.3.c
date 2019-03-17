
/*
前面个数顺序向后移动m个位置
*/

#include <stdio.h> 


void adjust(int a[],int b[],int );


int main(void)
{
    int a[10],b[10];
    int i;
    int m;
    printf("input m");
    scanf("%d",&m);
    printf("input 10 number");
    for(i=0;i<10;i++)scanf("%d",&a[i]);
    adjust(a,b,m);
    for(i=0;i<10;i++)printf("%-3d",b[i]);
    return 0;
}


void adjust(int a[],int b[],int m)
{
    int i;
    for(i=0;i<10;i++)
    {
        b[(i+m)%10]=a[i];
    }
}

