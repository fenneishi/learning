#include<stdio.h>

// putchar 与 getchar 



int main(){
    // putchar返回一个int,为输出字符的ASCII码
    // int a;
    // a=putchar(256);
    // printf("\n");
    // printf("%d",putchar(256));
    // printf("\n");
    // printf("%d",a);
    // printf("\n");
    // return 0;
    char a;
    while((a=getchar())!=-1){
        printf("%c",a);
    }
    printf("a=%d\n",(int)a);
}



