// 明文加密：每个字母，按照ASCII变成后一个字母。

# include<stdio.h>
# include<string.h>
# define MAXLINE 100

void encrypt(char *);

int main(void)
{
    char line[MAXLINE];

    printf("input the string:");
    gets(line);
    
    encrypt(line);

    printf("the res is: %s\n",line);
    return 0;
}


void encrypt(char *s)
{
    for(;*s!=0;s++)
    {
        if(*s=='z') *s='a';
        else *s=*s+1;
    }
    
}