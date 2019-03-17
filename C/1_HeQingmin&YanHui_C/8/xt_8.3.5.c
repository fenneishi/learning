
/*
从第m个字符开始的，全部字符复制到另一个数组中，并输出。
*/

#include <stdio.h> 


void mcopy(char *,char *,int );
int main(void)
{

    char a[100];
    char b[100];
    int m;

    printf("input m:");
    scanf("%d",&m);

    printf("input stings:");
    scanf("%s",a);

    mcopy(a,b,m);

    printf("%s",b);


    return 0;
}


void mcopy(char *a,char *b,int m )
{
    int i;
    for(i=m-1;a[i]!=0;i++)
    {
        b[i-(m-1)]=a[i];
    }
}

