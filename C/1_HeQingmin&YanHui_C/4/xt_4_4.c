# include<stdio.h>
# include<math.h>


int main(void)
{
    int i,n;
    double son,moth,change,item,sum;
    printf("please input the count : ");
    scanf("%d",&n);


    moth =1;
    son =2;
    item =son/moth;
    sum = sum+item;
    for(i=2;i<=n;i++){
        change =moth;
        moth = son;
        son = change+son;
        item =son/moth;
        sum = sum+item;
    }

    printf("the sum is %.2f\n",sum);

    return 0;
}
