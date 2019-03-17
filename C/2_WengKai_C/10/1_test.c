
#include<stdio.h>
#include<string.h>
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main(void){
    char s[100];
    int i;
    
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i])); 
    // putchar(('a'<=(s[++i])&&(s[++i])<='z'?(s[++i])-'a'+'A':(s[++i])));
    // 实际上进行了4次++i运算。
    putchar('\n');
    return 0;
}

