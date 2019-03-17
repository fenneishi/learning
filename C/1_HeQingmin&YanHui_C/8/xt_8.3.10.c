
/*
统计各种字符各有多少
*/

#include <stdio.h>
#include <string.h> 



int strcomp(char a[],char b[]);
int main(void)
{

    char a[100],b[100];


   
    printf("input stings a:");
    gets(a);
    printf("input stings b:");
    gets(b);
    
    switch(strcomp(a,b))
    {
        case 1: printf("a>b");break;
        case 0: printf("a=b");break;
        case -1:printf("a<b");break;
    }



    return 0;
}





int strcomp(char a[],char b[])
{
    int res;
    int i;
    int na=strlen(a),nb=strlen(b);

    i=0;
    do
    {
        if(a[i]>b[i]) res=1;
        if(a[i]==b[i])res=0;
        if(a[i]<b[i]) res=-1;
        i++;if(a[i]==0&&b[i]==0)break;
        
    }
    while(res==0);

    

    return res;
}
