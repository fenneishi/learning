# include<stdio.h>
# include<math.h>

int main(void)
{
    int i,n,m,pro_n,pro_m,sum;
    pro_n=1 ;  
    pro_m=1 ;                
    sum = 0;

    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter m:");
    scanf("%d",&m);
    
    printf("n!=");
    for(i=1;i<=n;i++){
        pro_n=pro_n*i;
    }
    printf("%d\n",pro_n);

    printf("m!=");
    for(i=1;i<=m;i++){
        pro_m=pro_m*i;
    }
    printf("%d\n",pro_m);

    printf("n!+m!=%d\n",pro_n+pro_m);  

    return 0;
}