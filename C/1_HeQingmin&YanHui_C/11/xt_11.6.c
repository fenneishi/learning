

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 


char *match(char *s,char ch1,char ch2);
void print_str(char *s,char end);
int main(void)
{  
    char *s,ch1,ch2,*res;
    char temp;
    s=(char *)malloc(100*sizeof(char));

    printf("input string :");
    scanf("%s",s); 
    printf("input start char:");
    scanf("%c",&temp);  // 先把多余的回车消耗掉
    scanf("%c",&ch1);
    printf("input end char:");
    scanf("%c",&temp); 
    scanf("%c",&ch2);
    
    res=match(s,ch1,ch2);
    switch((int)res)
    {
        case 0:printf("can not find !");break;
        default:print_str(res,ch2);break;
    }
    return 0;
}

char *match(char *s,char ch1,char ch2)
{
    char *res=NULL;
    int s_len;
    int i,j;
    s_len=strlen(s);
    for(i=0;i<=(s_len-2);i++)
    {
        if(s[i]==ch1)
        {
            for(j=i+1;j<=(s_len-1);j++)
            {
                if(s[j]==ch2) 
                {
                    res=s+i;
                    break;
                }
            }
        }
    }
    return res;
}


void print_str(char *s,char end)
{
    int i;
    for(i=0;s[i]!=end&&s[i]!=0;i++)
    {
        printf("%c",s[i]);
    }
    printf("%c\n",s[i]);
}
