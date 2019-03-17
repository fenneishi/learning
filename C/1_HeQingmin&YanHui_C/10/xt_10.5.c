

#include <stdio.h>
#include <stdlib.h> 




int bit_out(int n);
int main(void)
{  
    int n,i;
    printf("please input the n :");
    scanf("%d",&n);
    printf("===================================\n");
    bit_out(n);
    printf("\n");
    return 0;
}



int bit_out(int n)
{
    if(n<10)printf("%d,",n%10);
    else
    {
        bit_out(n/10);
        printf("%d,",n%10);
    }
    return 0;
}