
/*
对字符串进行排序
*/

#include <stdio.h> 



void bubble_strings(char a[],int size);
int main(void)
{

    char a[6];

   
    printf("input stings:");
    scanf("%s",a);

    bubble_strings(a,5);  // 这里要传递字符串的实际大小，而不能是加上\0的。

    printf("%s\n",a);

    return 0;
}


void bubble_strings(char a[],int size)
{
    int i;
    int j;
    char temp;
    for(i=1;i<=size-1;i++)
    {
        for(j=0;j<=size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}



