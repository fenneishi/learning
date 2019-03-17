# include<stdio.h>
# include<math.h>



int main(void)
{
    int i;
    int print(int i);
    for(i=1;i<=4;i++)print(i);
    for(i=4;i>=1;i--)print(i);
    return 0;
}

int print(int i){
    int j;
    for(j=1;j<=(4-i);j++)printf(" ");
    for(j=1;j<=(2*i-1);j++)printf("*");
    for(j=1;j<=(4-i);j++)printf(" ");
    printf("\n");
    return 0;
}