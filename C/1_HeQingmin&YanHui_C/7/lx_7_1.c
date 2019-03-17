# include<stdio.h>
# include<math.h>


int main(void)
{
    int num[10];
    int i,n;
    int sum=0,average;

    printf("please intput n:");
    scanf("%d",&n);
    printf("please intput the nums:");
    for(i=0;i<n;i++){scanf("%d",&num[i]);}

    for(i=0;i<n;i++){sum+=num[i];}
    printf("the average of these number is :%.2f\n",(1.0*sum/n));
    return 0;
}

