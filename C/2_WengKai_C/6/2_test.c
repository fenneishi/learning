#include<stdio.h>

// scanf和printf函数功能和细节测试



int main(){
    //读入格式是字符串，但是shell给的是普通字符，会怎么样？
    int a;
    scanf("%d",&a);
    printf("a=%d\n",a);
    printf("====================================\n");

    // 字符串数组的0与0/
    // 每个字符只占8位，重点想清楚那一个字节到底放的是什么，你不用管到底怎么做到的(无非就是一些用代码写的固定逻辑)
    // 例如你写的是单引号，就查表得到一个字节的值，如果int数字，就直接取出倒数8个位（一个字节）就好了,如果是浮点，稍微复杂点。

    char b[5]={97,98.0,0};      //正确：98.0 应该会被当成整数处理。
    char c[5]={'a','b','\0'};   //正确：
    char d[5]={'a','b',};       //正确：数组为显性初始化的部分，自动初始化为0
    char e[]={'a','b',};        //错误：没有截止符\0
    char f[]="ab";              //正确：编译器会把“ab”自动变成{'a','b','\0'}
    char f2[10]="ab";           //正确：编译器会把“ab”自动变成{'a','b','\0'}，数组为显性初始化的部分，自动初始化为
    const char  *g="ab";               //正确：但是无法通过指针g修改字符串
    //char const  * g="ab";    
    //char  * g="ab";    
    //char *h={'a','b','\0'};     //不正确：会给出warnings，运行会出现Segmentation fault。
    


    printf("b=%s\n",b);
    printf("c=%s\n",c);   
    printf("d=%s\n",d);   
    printf("e=%s\n",e);         // 非正常输出
    printf("f=%s\n",f);
    printf("f=%s\n",f);  
    printf("f2=%s\n",f);  
    printf("g=%s\n",g); 
    //printf("h=%s\n",h); 

    printf("====================================\n");
    

    return 0;
}