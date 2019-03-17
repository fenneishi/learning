
/*
函数声明vs函数原型
*/

#include <stdio.h>

// void f1(void);
void f2();//函数声明，兼容过去的C标准

int main(void){
    void f1(void);//函数原型,放在main函数里面也行，只要在调用的前面.
    f1();
    float f=3.1;
    char ch='a';
    f2(ch,f);
    f2();
    //wrong
    // f1(ch);
}
void f3()
{
printf("ddd\n");
void f3();//放在哪里都可以，只要在调用的前面就行.
}



void f1(void)
{
    f3();
    printf("f1 is void!\n");
}

void f2(int a,double b)
{
    int aa;
    double bb;
    printf("a=%d,b=%f\n",a,b);
    printf("aa=%d,bb=%f\n",aa,bb);
}

/*
//wrong
void f1(int a,double b)
{
    printf("f1 is void!");
}
*/



