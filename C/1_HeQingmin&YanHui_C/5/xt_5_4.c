# include<stdio.h>
# include<math.h>


int prime(int n);

int main(void)
{
    int m,n;
    int count,i;
    float sum;

    printf("please input m:");
    scanf("%d",&m);
    printf("please input n:");
    scanf("%d",&n);

    sum = 0;
    count = 0;
    for(i=n;i<=m;i++){
        if(prime(i)==1){
            count++;
            sum+=i;
        }
    }
    
    printf("between n and m ,the count of prime is :%d the sum of these prime is :%.0f\n",count,sum);

    return 0;
}

int prime(int n){     
    int i;
    if(n<2)return 0;
    for(i=2;i<n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
