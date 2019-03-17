

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 


char *search_substr(char *s,char *t);
int main(void)
{  
    char *s;
    char *t;
    char *res;
    s=(char *)malloc(100*sizeof(char));
    t=(char *)malloc(100*sizeof(char));
    printf("input string 1:");
    scanf("%s",s);
    printf("input string 2:");
    scanf("%s",t);  
    res=search_substr(s,t);
    switch((int)res)
    {
        case 0:printf("can not find !");break;
        default:printf("the res is :'%p'\n",res);break;
    }
    return 0;
}

char *search_substr(char *s,char *t)
{
    char *res=NULL;
    char *temp;
    int s_num,t_num;
    int i,j;
    s_num=strlen(s);
    t_num=strlen(t);
    for(i=0;i<=(s_num-t_num);i++)
    {
        if(s[i]==t[0])
        {
            for(j=0;j<=(t_num-1);j++)
            {
                if(s[i+j]!=t[j]) break;
            }
            if(j==t_num)
            {
                res=s+i;
                break;
            }
        }
    }
    return res;
}



