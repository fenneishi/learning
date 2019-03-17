// 分别用数组和指针来计算10个整数的和

# include<stdio.h>
# include<math.h>


void bubble(int a[],int n);


int main(void)
{
    int i,a[10],*p;
    long sum=0;

    printf("please input 10 numbers:");
    for(i=0;i<10;i++)scanf("%d",&a[i]);

    for(i=0;i<10;i++)sum+=a[i];
    printf("the sum by array is %ld\n",sum);

    sum=0;
    for(p=a;p<=a+9;p++)sum+=*p;
    printf("the sum by pointer is %ld\n",sum);


    return 0;
}


