
/*
输入输出研究
*/

#include <stdio.h>



int main(void){
    
    char ch;
    //ch=128;
    // ch=-129;
    ch=-128;
    ch=127;
    /*
    char的取值范围是-128~0~127，即本系统中的char是有符号的。
    */

    printf("size of Char is:%zd\n",sizeof(char));
    printf("size of Int is:%zd\n",sizeof(int));
    printf("size of getchar() is:%zd\n",sizeof(getchar()));
    /*
    size of Char is:1
    size of Int is:4
    size of getchar() is:4
    */
   /*
   putchar的定义式：
   int
     putchar(int c);
   */
}




