

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 


char *strcats(char *s,char *t);
int main(void)
{  
    char *s;
    char *t;
    s=(char *)malloc(100*sizeof(char));
    t=(char *)malloc(100*sizeof(char));
    printf("input string 1:");
    scanf("%s",s);
    printf("input string 2:");
    scanf("%s",t);  
    printf("the res is :'%s'\n",strcats(s,t));
    return 0;
}

char *strcats(char *s,char *t)
{
    char *res;
    char  *temp;
    int s_num,t_num;
    int new_size;
    int i,j;
    // 确定申请空间的大小；
    s_num=strlen(s);
    t_num=strlen(t);
    new_size =(s_num+t_num)*sizeof(char);
    // 申请新的空间
    res=(char *)malloc(new_size); 
    // s的内容复制到res中
    for(i=0;s[i]!=0;i++)
    {
         res[i]=s[i];
    }
    for(j=0;t[j]!=0;j++,i++)
    {
        res[i]=t[j];
    }
    return res;
}



