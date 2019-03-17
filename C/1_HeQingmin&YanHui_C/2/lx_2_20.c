# include<stdio.h>
# include<math.h>

double fact(int n);

int main(void)
{
    int i,n,m;

    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter m:");
    scanf("%d",&m);
    
    
    
    printf("result=%.0f\n",(1.0*fact(n))/(fact(m)*fact(n-m)));   /*函数fact返回值类型即为double*/
   
    

    return 0;
}

double fact(int n){
    int i;
    double pro;

    pro=1;
    for(i=1;i<=n;i++){pro=pro*i;}

    return pro;
}