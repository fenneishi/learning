
/*
统计各种字符各有多少
*/

#include <stdio.h> 



void bubble_strings(char a[],int size);
int main(void)
{

    char a[100];

    int num=0,big=0,sma=0,ret=0,spa=0;

    int i,j;

   
    printf("input stings:");
    gets(a);

    for(i=0;a[i]!=0;i++)
    {
        if(a[i]>'a'&&a[i]<'z')sma++;
        if(a[i]>'A'&&a[i]<'Z')big++;
        if(a[i]>'0'&&a[i]<'9')num++;
        switch (a[i])
        {
            case '\n':ret++;
            case ' ': spa++;
        }
    }

    printf("num=%d\n",num);
    printf("big=%d\n",big);
    printf("sma=%d\n",sma);
    printf("ret=%d\n",ret);
    printf("spa=%d\n",spa);





    return 0;
}






