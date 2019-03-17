# include<stdio.h>
# include<math.h>


int main(void)
{
    int prime(int m);
    int n,i,m;

    printf("please input the number of prime:");
    scanf("%d",&n);
    printf("================================================================\n");

    for(i=1;i<=n;i++){
        printf("please input the %d prime:",i);
        scanf("%d",&m);
        prime(m);
    }

    
    return 0;
}

int prime(int m){

    int i;
    if(m<=0)printf("No!\n\n");
    else{
        for(i=2;i<=m/2.0;i++)if(m%i==0)break;
        if(i>m/2&&m!=1)printf("%d is a prime number!\n\n",m);
        else printf("No!\n\n");
    }
    
    return 0;
}
