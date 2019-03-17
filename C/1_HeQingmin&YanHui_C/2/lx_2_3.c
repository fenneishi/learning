# include<stdio.h>

int main(void)
{
    int m=1;
    int n=4;
    int i=1;
    while(m<=4){
        for(i=1;i<=n;i++)printf("*");
        printf("\n");
        n--;
        m++;
        }
    return 0;
}