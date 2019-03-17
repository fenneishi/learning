# include<stdio.h>
# include<math.h>


int main(void)
{
    int num[10];
    int i,n;
    int sum=0,average;

    printf("please intput n:");
    scanf("%d",&n);
    printf("please intput the numbers:");
    for(i=0;i<n;i++){scanf("%d",&num[i]);}

    for(i=n-1;i>=0;i--){printf("%d ",num[i]);}

    printf("\n");
    
    return 0;
}

