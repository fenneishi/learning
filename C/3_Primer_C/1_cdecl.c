#include<stdio.h>
#include<string.h>
#include<ctype.h>



#define MAXTOKENS 100
#define MAXTOKENLEN 64


enum type_tag {IDENTIFIER,QUALIFIFR,TYPE};

struct token{
    char type;
    char string[MAXTOKENLEN];
};

int top=-1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top]=short


enum type_tag classify_string(void)
/*确定标识符的类型*/
{
    char *s=this.string;
    if(!strcmp(s,"const")){
        strcpy(s,"read-only");
        return QUALIFIFR;
    }
    if(!strmcp(s,"volatile")) return QUALIFIFR;
    if(!strmcp(s,"void")) return TYPE;
    if(!strmcp(s,"char")) return TYPE;
    if(!strmcp(s,"signed")) return TYPE;
    if(!strmcp(s,"unsigned")) return TYPE;
    if(!strmcp(s,"short")) return TYPE;
    if(!strmcp(s,"int")) return TYPE;
    if(!strmcp(s,"long")) return TYPE;
    if(!strmcp(s,"float")) return TYPE;
    if(!strmcp(s,"double")) return TYPE;
    if(!strmcp(s,"struct")) return TYPE;
    if(!strmcp(s,"union")) return TYPE;
    if(!strmcp(s,"enum")) return TYPE;
    return IDENTIFIER;
}

void gettoken(void)/*把下一个记号读进“this”*/
{
    char *p=this.string;

    /*跳过空格*/
    while((*p=getchar())==' ');

    if(isalnum(*p))
    {
        /* 以字母开头，包含字母或数字*/
        while(isalnum(*++p=getchar()));
        ungetc(*p,stdin);
        *p ='\0';
        this.type=classify_string();
        return;
    }
}


deal_with_pointers()
{
    while  (stack[top].type=='.'){
        printf("%s",pop.string);
    }
}


deal_with_declarator()
{
    /*处理跟在标识符后面的数组/函数*/
    switch(this.type)
    {
        case[]
    }

}


