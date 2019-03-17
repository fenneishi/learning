# include<stdio.h>
# include<math.h>

int main(void)
{
    int i,n,m;
    double power;

    printf("Enter n:");
    scanf("%d",&n);
    
    
    
    for(i=1;i<=n;i++){
        power = pow(2,i);
        printf("pow(3,%d)=%.0f\n",i,power);
    }
    

    return 0;
}