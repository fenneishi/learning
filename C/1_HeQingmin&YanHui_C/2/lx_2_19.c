# include<stdio.h>
# include<math.h>

double fact(int n);

int main(void)
{
    int i,n;
    double pro;

    printf("Enter n:");
    scanf("%d",&n);
    
    
    
    for(i=1;i<=n;i++){
        pro= fact(i);
        printf("%d!=%.0f\n",i,pro);
    }
    

    return 0;
}

double fact(int n){
    int i;
    double pro;

    pro=1;
    for(i=1;i<=n;i++){pro=pro*i;}

    return pro;
}