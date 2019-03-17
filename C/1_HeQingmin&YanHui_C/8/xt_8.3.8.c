
/*
编程判断字符串是否是回文。
*/

#include <stdio.h>
#include <string.h>




int palindromes(char a[]);
int main(void)
{

    char a[6];

   
    printf("input stings:");
    scanf("%s",a);

    switch(palindromes(a))
    {
        case 1:printf("is palindromes\n");break;
        case 0:printf("not palindromes\n");break;
    }  
    
   

    return 0;
}


int palindromes(char a[])
{
    int i;
    int j;
    int res=1;
    int n=strlen(a);
    
    for(i=0,j=n-1;i<j;i++,j--)
    {
        if(a[i]!=a[j])res=0;
    }
    
    return res;
}



