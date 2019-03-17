// 通过函数调用来交换变量值的实例程序；

# include<stdio.h>
# include<math.h>

void swap1(int a,int b);
void swap2(int *a,int *b);
void swap3(int *a,int *b);



int main(void)
{
    int a=1,b=2;
    int *pa=&a,*pb=&b;

    swap1(a,b);
    printf("after calling swap1:a=%d,b=%d\n",a,b);

    a=1;
    b=2;
    swap2(pa,pb);
    printf("after calling swap2:a=%d,b=%d\n",a,b);

    a=1;
    b=2;
    swap3(pa,pb);
    printf("after calling swap3:a=%d,b=%d\n",a,b);

    return 0;
}

void swap1(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swap2(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap3(int *a, int *b)
{
    int *temp;
    temp=a;
    a=b;
    b=temp;
}