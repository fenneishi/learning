#include<stdio.h>

// 结构功能测试


typedef struct{
        int x;
        int y;
    } Array;

typedef char* Strings[10];

int main(void){
   Strings a;
   a[1]="aaa";
   printf("%s\n",a[1]);


    return 0;
}



