# include<stdio.h>
# include<math.h>


int main(void)
{
    int sum,n,i;
    sum =0;
    i=1;

    do{
        printf("please input the %d number:",i);
        scanf("%d",&n);
        if(n<=0)break;
        else if(n%2==0)sum+=n;
        i++;
    }
    while(n>0);

    printf ("the sum is %d!\n",sum);

    


    return 0;
}
