#include<stdio.h>

extern int a;




int main(void)
{
    printf("a=%d",a);
   
    return 0;
}


int a=19;
//int b=a;//initializer element is not a compile-time constant


/*

探寻a的初始化是否在main函数之前执行。

*/