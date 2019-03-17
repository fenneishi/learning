#include <stdio.h>
#include <stdlib.h>

static char S;
char *P="abcde";
char A;
char R[5]="abcde";

extern int hh;
int main(void){
    static char s;
    char  *p="abcd";
    extern int hh;
    // int hh;
    // *p ='a';
    int a;
    char r[5]="abcde";
    char *m=(char*)malloc(sizeof(char)*3);
    printf("S__location=%p\n",&S);
    printf("P->location=%p\n",P);
    printf("P__location=%p\n",&P);
    printf("A__location=%p\n",&A);
    printf("R->location=%p\n",R);
    printf("R__location=%p\n",&R);
    printf("s__location=%p\n",&s);
    printf("p->location=%p\n",p);
    printf("p__location=%p\n",&p);
    printf("a__location=%p\n",&a);
    printf("r->location=%p\n",r);
    printf("r__location=%p\n",&r);
    printf("m->location=%p\n",m);
    // printf("h->location=%p\n",&hh);
    return 0;
}
/*
不能用一个单个字符初始化。
可以不初始化，完了之后用单个字符进行赋值。这时候指针指向是stack区。
如果不初始化，然后赋值又用字符串，是不行的，人间是char *不是字符串。
初始化可以用NULL；
如果用字符串初始化，然后再尝试用但个字符进行重新赋值，也是不行的，会出现bus error

*/
