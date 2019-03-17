
/*
数组
*/

#include <stdio.h>

int sum(int[],int(*)[]);

int main(void){
    int ar[2]={1,2};
    int a=ar[2];//正常情况下，如果数组越界了，智能编译器会有提示
    int *app=ar;
    int arr[]={};
    sum(ar,&ar);

}

//充分可见ar就是一个指针了，根本就不是什么新东西，也不是数组名。
//但是编译器害怕新手误以为这是一个数组，所以当sizeof(ar)时候，会发出warning，告诉你这个ar不是数组名，是指针名。
int sum(int ar[1],int (*pp)[2])
{
    printf("ar[1]=%d",ar[1]);//如果是数组，已经越界了都没有提示,说明不是
    printf("location of ar is %p\n",&ar);
    printf("location of ar is %p\n",ar);
    printf("size of ar is %zd\n",sizeof(ar));//warning: sizeof on array function parameter will return size of 'int *' instead of 'int []' [-Wsizeof-array-argument]
    printf("size of *ar is %zd\n",sizeof(*ar));
    printf("size of *pp is %zd\n",sizeof(*pp));

    return 0;
}



/*
当一个表达式能够标识一个DataObject后，出过一些特殊情况，那么就能够用“以这个表达式为子表达式”的表达式
1、重写这个DataObject的值。
2、获得这个DataObject的值。
3、获得这个ataObject的位置（初始位置）
4、获得这个ataObject的长度（多少个字节）
以上叫做通过此标识去操控这个DataObject。

注：
一个DataObject的三要素是：
1、值
2、初始位置
3、空间占用长度

特殊情况是：
1、如果这个DataObject是一个复合数据类型(不是基础数据类型),那么C语言标准里这个DataObject的值本身就无法重写(初始化除外)，通过任何表达式（可以标识DataObject的）都不行。
    1、例如数组这个整体DataObject。
    2、例如结构这个整体DataObject。
2、如果这个DataObject本身可被重写，但是某个标识这个DataObject的表达式被const修饰了，那么便无法通过这个表达式去修改这个DataObject。
    1、例如int const *p;[const 修饰的是*p，这个可以标识一个int型DataObject的表达式]
    2、例如int * const p;[const 修饰的是p，这个可以标识一个地址型DataObject的表达式]
    2、例如int const A[10];[const 修饰的是A[i]，这个可以标识一个int型DataObject的表达式]


常见的DataObject类型
1、基础数据类型：int double char
2、地址数据类型：指针
3、复合数据类型：数组、指针
注释：
1、基础数据类型可以游离存在（单独定义一个普通变量），也可以成为复合数据类型的一份子。
2、地址数据类型可以游离存在（单独定义一个指针变量），也可以成为复合数据类型的一份子。
3、复合数据类型可以游离存在（单独定义一个指针变量），也可以成为复合数据类型的一份子。

常见的这类表达式（能够标识一个DataObject）
1、普通变量
2、指针本身
3、复合变量本身
4、指针表达式
5、数组表达式
6、结构表达式


新的审视代码的角度：
1、创建一个个的DataObject。
2、创建一个个的能够做标识的表达式。
3、根据需要，用这些表达式去标识这些DataObject。
4、通过这些表达式（已经标识了DataObject）去操控这些DataObject。




基于以上理解模型，解释C标准里的一些疑惑：
1、数组名（ArrayName）、指针名（PointName）的关系。
2、数组名（ArrayName）、地址常量(&ArrayName[0])关系。
3、数组名到底是什么？
4、左值、右值、可修改左值、可修改右值、DataObject、变量、常量、变量名、常量名
5、初始化到底是什么？与赋值的关系。



三个值传递过程的不同
赋值
初始化：
1、数组初始化：只能固定形式，例如大括号，字符串
2、指针初始化：必须是地址值，另外，地址归属的DataObject的类型必须一致。换句话说，必须是和指针同类型的DataObject的地址才行。
3、参数传递：主要两个问题：放和取的步调要一致，函数内部代码能够准确翻译。
    1、函数定义中的参数类型：主要牵扯到编译函数内部代码时，提供必须的，准确的，无人类理解二义性的信息。
    2、函数原型中的参数类型：主要牵扯调用函数，将必要数据入栈的过程前，检查数据类型。
    3、两个参数类型必须一致：否则放和取过程不能步调一致，就会出现问题。
参数传递
总结:
1、共同点：都是往一个DataObject里面写入值。
2、区别：各式各，三者有不同的逻辑，实现过程，语法要求，虽然很多时候很相似，但是不要混为一谈，把赋值的逻辑照搬到参数传递里。
    1、初始化：简单，固定的几种方式。
    2、赋值：关键点在于理解表达式（可以标识DataObject的）和DataObject关系，赋值号右边通过父表达式取出DataObject的某些属性值并进行运算，左边通过父表达式（通常为本身）重写DataObject的值。
    3、参数传递：检查（检查类型是否匹配，主要是大小）——>数据入栈——>根据需要从栈中取数据。




int *p 解读：
1、int * 
    1、是变量p存储数据的类型，或者说是表达式p标识DataObject的类型
    2、这个DataObject有自己的首地址、长度、数值。
    3、这种DataObject类型，有属于自己的在各种场景下的运算方式。
2、int 
    1、是*p存储的数据的类型，或者说是表达式*p标识DataObject的类型，
    2、这个DataObject有自己的首地址、长度、数值。
    3、这种DataObject类型，有属于自己的在各种场景下的运算方式。


size_t s 解读
1、size_t 
    1、是变量s存储数据的类型，或者说是表达式s标识DataObject的类型
    2、这个DataObject有自己的首地址、长度、数值。
    3、这种DataObject类型，有属于自己的在各种场景下的运算方式。

int （*p)[]解读

int a[]解读

&Vname解读

sizeof(Vname)解读


DataObject的解读：
1、每一个DataObject都有自己的类型归属
    1、每一个类型都配套着运算方式（从运算符角度来说是重载）
    2、每一个类型都配套着视角转换方案：人类理解视角和机器理解视角。
    3、每一个类型都有自己的特殊性，例如只能初始化，不能再次重写
2、每一个DataObject都有三个基本要素：
    1、位置
    2、大小
    3、数值
3、每一个DataObject都在代码中有相应的标识者（一个特殊的表达式），程序通过这些这些标识者操控这些DataObject。
    1、常量表达式：操控能力：均能取得DataObject的三个要素数值，均能够初始化DataObject的数值，均不能改写DataObject的数值。
    2、变量表达式：操控能力：均能取得DataObject的三个要素数值，均能够初始化DataObject的数值，部分能改写DataObject的数值。(注释：只要一个表达式中有变量，我们就认为这是一个变量表达式)
        1，每一个变量表达式都要自己的属性：const、
        2、每一个变量表达式的核心都是一个变量。
        3、每一个变量都有唯一的名字来标识这个变量（C++中引用除外）
        4、每一个变量名都有自己特殊的属性：scope、链接、
4、每一个DataObject都有由上面三个基本方面衍生出的特征：
    1、存储周期：有
    2、只能初始化、无法改写：
5、每一个DataObject都有由上面三个基本方面所带来的某些场景下的特殊对待：
    1、printf、scanf
        
*/


