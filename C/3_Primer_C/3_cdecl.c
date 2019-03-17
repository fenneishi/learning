#include <stdio.h>
// #include <stdlib.h>
#include <float.h>


int main(void){
    char char_a='a';
    int int_a=32766;
    short short_a=32766;
    long long_a=32766;
    long long longlong_a=32766;
    float float_a=32766;
    double double_a=32766;
    long double LongDouble_a=32766;

    
    // 各种类型占用空间大小。
    printf("%zd is short\n",sizeof(short));
    printf("%zd is int\n",sizeof(int));
    printf("%zd is long\n",sizeof(long));
    printf("%zd is long long\n",sizeof(long long));
    printf("%zd is float\n",sizeof(float));
    printf("%zd is double\n",sizeof(double));
    printf("%zd is long double\n",sizeof(long double));
    printf("float尾数位数：%d\n",FLT_MANT_DIG);
    printf("double尾数位数：%d\n",DBL_MANT_DIG );
    printf("longDouble尾数位数：%d\n",LDBL_MANT_DIG );
    /*
    2 is short
    4 is int
    8 is long
    8 is long long
    4 is float
    8 is double
    16 is long double
    float尾数位数：24  也就是3个byte，所以float的精度不如int！！[int是31个有效位，32-1个符号位]
    double尾数位数：53  不到7个byte,所以double精度不如long_int,但是比int要强
    longDouble尾数位数：64  精度和long_int一样。
    精度排名：float<int<double<long=longlong=long_duoble
    空间排名：int=float<long=long=double<long_double
    */

    //printf的特殊处理[char、short当int]
    printf("printf short_a as int_type:%d",short_a);
    printf("printf char_a as int_type:%d",char_a);
    printf("%c is %d\n",char_a,char_a);//char变量，虽然占用一个byte，但是可以用%ds说明符输出。
    printf("%d is %c\n",char_a,char_a);//不放在末尾也行，看来是做了特殊处理。

    //printf中强制类型转换float——>double;
    printf("printf函数会强制把float装换成double:%f",float_a);
    //字符型常量存储格式为int，而非char,占用四个type
    printf("%zd is char常量\n",sizeof('a')); 
    printf("short_a=%d,short_a=%d,printf as int_Type\n",short_a,short_a);

    //大多数情况下，说明格式和参数类型不匹配，会造成错误（这里很奇怪，结果是正确的，只是给出了warning）
    // printf("short_a=%ld,short_a=%ld,printf as int_Type\n",short_a,short_a);//Warning:format specifies type 'long' but the argument has type 'short'
    // printf("int_a=%hd,int_a=%hd,printf as int_Type\n",int_a,int_a);//warning: format specifies type 'short' but the argument has type 'int' [-Wformat]
    // printf("int_a=%d,int_a=%d,printf as int_Type\n",long_a,long_a);//warning: format specifies type 'int' but the argument has type 'long' [-Wformat]
    // printf("LongDouble_a=%f,LongDouble_a=%f,printf as int_Type\n",LongDouble_a,LongDouble_a);//warning: format specifies type 'double' but the argument has type 'long double' [-Wformat]
    // printf("double_a=%Lf,double_a=%Lf,printf as int_Type\n",double_a,double_a);//warning: format specifies type 'long double' but the argument has type 'double' [-Wformat]
    
    //常量的存储格式是由其样子编译器自动决定的
    //发生强制类型转换时候，可能会造成错误。
    // short short_a=32768;//implicit conversion from 'int' to 'short' changes value from 32768 to -32768
    
    
    return 0;
    
}


/*
常量的数值类型是什么？
变量的数值类型是什么？
各种数值类型的存储空间大小？
类型转换的情况？（赋值(包含参数传递)、表达式、强制、printf类型不定长参数中float转成double）
printf中各种组合的意义？
printf机制（参数传递+格式化读取内存+强制类型转换、特殊处理[char、short当int]、buffer机制）

*/

