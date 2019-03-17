# include<stdio.h>
# include<math.h>



int main(void)
{
    int max,min;
    double sum(int max,int min);
    double res;

    printf("please input the max:");
    scanf("%d",&max);
    printf("please input the min:");
    scanf("%d",&min);

    res=sum(max,min);

    printf("the sum is : %.0f\n",res);

    return 0;
}

double sum(int max,int min){
        int i;
        double sum;
        sum = 0;
        for(i=min;i<=max;i++){
            sum=sum+i;
        }
        return sum;
}
