#include<stdio.h>
#define S 3*2
#define Si 3 * 2

int a=4;
int __a=5;s




int main(void)
{
    int a;
    a=S;
    printf("%d\n",a);
    // a=Si;
    // printf("%d\n",a);
    return 0;
}



// 宏的研究

/*
预编译结果：
int main(void)
{
    int a;
    a=3*2;
    printf("%d\n",a);
    // a=3 * 2;
    // printf("%d\n",a);
    return 0;
}
*/
