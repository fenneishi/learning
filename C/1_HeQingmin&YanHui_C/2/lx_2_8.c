# include<stdio.h>

int main(void)
{
    int c,f;
    printf("please input fahr:");
    scanf("%d",&f);

    c = 5*(f-32)/9;

    printf("fahr=%d,celsius=%d\n",f,c);

    return 0;
}