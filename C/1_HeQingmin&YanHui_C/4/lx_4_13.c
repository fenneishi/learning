# include<stdio.h>
# include<math.h>


int main(void)
{
    int x1,x2;
    int i,x; 

    x1=x2=1;
    printf("%10d%10d",x1,x2);

    for(i=2;i<=10;i++){
        x=x1+x2;
        printf("%10d",x);
        x1=x2;
        x2=x;
    }
    
    printf("\n");


    return 0;
}
