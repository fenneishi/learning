# include<stdio.h>
# include<math.h>


int main(void)
{
    int i,a,n;
    double sum,item;
    printf("please input n : ");
    scanf("%d",&n);
    printf("please input a : ");
    scanf("%d",&a);


    sum =  0;
    for(i=1;i<=n;i++){
        item =pow(a,i);
        sum=sum+item;
    }


    printf("the sum is %.0f\n",sum);

    return 0;
}
