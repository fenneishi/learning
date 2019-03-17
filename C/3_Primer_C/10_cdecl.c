
/*
0 vs ('\0'and'')  vs NULL 
0 vs 0L vs 0.0 vs 0.0L
*/

#include <stdio.h>

int main(void)
{
    int a=1;
    
    int *p1=0;
    int *p2=NULL;
    int *p3=&a;
    printf("p1=%p,p2=%p，p3=%p,\n",p1,p2,p3);//p1=0x0,p2=0x7ffeecba69bc

    //字符型字面量，C语言中实际上标识的是一个int型的DataObject，但是字符串则是一个字符型数组，而不是int型数组
    char ch1='\0';//这里发生了类型转换，从int型转换成char型，因为前面3个字节都是0，所以斩断只取低位，不会发生数据损失
    char ch2=0;//这里发生了类型转换，从int型转换成char型，因为前面3个字节都是0，所以斩断只取低位，不会发生数据损失
    printf("ch1=%c,ch2=%c,\n",ch1,ch2);
    printf("size of (ch1) is %zd,size of(ch2) is %zd\n",sizeof(ch1),sizeof(ch2));//size of (ch1) is 1,size of(ch2) is 1
    printf("size of ('\\0') is %zd,size of (0) is %zd\n",sizeof('\0'),sizeof(0));//size of ('\0') is 4,size of (0) is 4



    // char ch3=NULL;//incompatible pointer to integer conversion initializing 'char' with an expression of type 'void *'

   // char ch4='';//warning: empty character constant [-Winvalid-pp-token]。error: expected expression
    return 0;
}
/*
0 vs ('\0'and'')  vs NULL 研究：

相同点：
1、都是常量，只不过NULL是符号常量，而0,'\0',是字面常量。
2、都标识一个DataObject。
3、大部分情况下，三者从人类视角来看的数值都是零，如果计算机的存储方案时源码二进制，那么计算机内存中存储的也是00000000.....只不过存储长度不一样而已。

不同点：
1、数据类型不同，或者说标识的DataObject的类型归属不同。
    1、NULL是指针型，或者说叫地址型。
    2、0和'\0'其实是一样的，都是int型。
    3、按理说'\0'应该是char型，但是和所有字符型常量一样，其实际的存储类型均为int型。
    4、语义上，当你要去表达一个
2、用0去替代NULL或者是‘\0’:
    1.用0去替代NULL一般编译器会给出warning，
        1、因为C标准里并没有明确规定NULL的值一定是0，NULL并非总是和0等同，
        2、NULL仅仅代表空值，也就是指向一个不被使用的地址，
        3、在大多数系统中，都将0作为不被使用的地址，所以就有了类似这样的定义。
        4、可能就是通过一个这样的define操作实现的：#define NULL 0
        5、也有些系统不将0地址作为NULL，而是用其他的地址
        6、所以说，千万别将NULL和0等价起来，特别是在一些跨平台的代码中，这更是将给你带来灾难。
    2.尽量不要用0去替代‘\0’，尽管编译和执行的角度没有任何问题：
        1、‘\0’从代码阅读者角度，含义更加明确，更加能够清楚这是一个ASCII码为0的字符。
        2、对于字符串的结尾，使用'\0'，让人一看就知道这是字符串的结尾，不是指针，也不是普通的数值
        3、总之就是语义上更加明确，让人一目了然。

*/