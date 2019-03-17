# include<stdio.h>
# include<math.h>


long long int fn(int n,int a);

int main(void)
{
    int a,n;
    int i;
    long double sum;

    printf("please input a:");
    scanf("%d",&a);
    printf("please input n:");
    scanf("%d",&n);

    sum = 0;
    for(i=1;i<=n;i++){
        sum+=fn(i,a);
        printf("%20lld\n",fn(i,a));
    }
    
    printf(" the sum is :%.0LF\n",sum);

    return 0;
}

long long int fn(int n,int a){     
    int i;
    long long int res;
    res = a;
    for(i=2;i<=n;i++){
        res=res*10+a;
    }
    return res;
}
