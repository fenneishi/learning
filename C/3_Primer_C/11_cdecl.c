
/*
‘a’vs"a"vs{'a'}
*/

#include <stdio.h>

int main(void)
{   
    char A[]={'a'};
    char B[]={3,4,0};// 我猜测无论是A还是B，初始化赋值时，可能都发生了强制类型转换，把
    const char *p={};
    A[0]='a';
    printf("size of A[0] is %zd ",sizeof(A[0]));
    return 0;
}
/*

不同点：
1、'a'标识的是一个int型DataObject。
2、“a”标识的是一个元素个数为2的字符数组型DataObject，里面有2个元素，即为{'a','\0'}
3、{'a'}标识的是一个元素个数为1的字符数组型DataObject，里面有1个元素.
4、以上都是常量，但是A[0]是一个变量，另外，A[0]的类型是char,但是‘a’的类型是int.

至于为什么C标准要把‘a’这种字符型常量的存储类型搞成int,我也不知道，可能是另有深意或为了一些其他目的。

*/