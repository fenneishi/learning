#include<stdio.h>


// 数据类型探究；


int main(){
    long z1;	
    int	z2;
    short z3;
    unsigned long	z4;
    unsigned z5;	
    unsigned short	z6;
    float Z1;
    float Z2;
    
    z4 = 12l;
    z4 = 12L;


    char c;
    c ='a';             // 翻译准则为:ASCII码
    printf("a=%c\n",c);   // 翻译准则为:ASCII码
    printf("a=%d\n",c);   // 翻译准则为:二进制补码—————有符号整型变量(十进制)
    printf("---------------------------------------------------------\n");

    char d;
    d = -1;             // 翻译准则为有符号整型变量(十进制)——————二进制补码
    printf("a=%c\n",d);   // 翻译准则为:ASCII码
    printf("a=%u\n",d);   // 翻译准则为:二进制补码—————有符号整型变量(十进制)
    printf("---------------------------------------------------------\n");

    unsigned char e;
    e = 'a';            // 翻译准则仍然为ASCII码
    printf("a=%c\n",e);   // 翻译准则为:ASCII码
    printf("a=%d\n",e);   // 翻译准则为:无符号二进制—————无符号整型变量(十进制)
    printf("---------------------------------------------------------\n");

    unsigned char a;
    a = -1;             // 翻译准则为:无符号整型变量(十进制)——————无符号二进制
    printf("a=%c\n",a);   // 翻译准则为:ASCII码
    printf("a=%d\n",a);   // 翻译准则为:二进制补码—————有符号整型变量(十进制)
    printf("---------------------------------------------------------\n");

    
    return 0;
}