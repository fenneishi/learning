
/*

*/

#include <stdio.h> 


void delchar(char a[],char ch);
int main(void)
{

    char a[100];
    char ch;

    printf("input ch:");
    scanf("%c",&ch);
    printf("input stings:");
    scanf("%s",a);

    delchar(a,ch);

    printf("%s\n",a);
    return 0;
}


void delchar(char a[],char ch)
{
    int i;
    int j;
    int temp;
    for(i=0;a[i]!= 0;i++)
    {
    printf("befor a=%s\n",a);
       if(ch==a[i])
       {
           for(j=i;a[j]!=0;j++)
           {
               a[j]=a[j+1];
           }
           i--;                 // 这一步非常有必要，注意真正模拟计算机计算过程在脑子里，尽量把问题考虑完整。
       }
    printf("after a=%s\n",a);
    printf("========\n");
    }
}



