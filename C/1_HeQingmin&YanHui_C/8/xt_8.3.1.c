
/*
数字排序
*/

#include <stdio.h> 

void bubble(int a[],int n);

int main(void)
{
    int a[10];
    int i=0;
    char ch,trash;

    printf("input 10 numbers :");
    
    for(i=0;i<=9;i++)scanf("%d",&a[i]);

    bubble(a,10);

    // 将多余的字符消耗掉
    do{scanf("%c",&trash);}while(trash!='\n');
    
    do
    {
        printf("please input A or D :");
        scanf("%c",&ch);
        do{scanf("%c",&trash);}while(trash!='\n');  // 将多余的字符消耗掉
    }
    while(ch!='A'&&ch!='D');




    if (ch == 'A')
    {
        for (i = 0; i <= 9; i++)
            printf("%-3d", a[i]);
    }
    else
    {
        for (i = 9; i >= 0; i--)
            printf("%-3d", a[i]);
    }


    printf("\n");

    return 0;
}


void bubble(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

}