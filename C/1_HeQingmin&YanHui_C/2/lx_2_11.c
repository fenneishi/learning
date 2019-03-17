# include<stdio.h>
# include<math.h>

int main(void)
{
    double x,y;
    printf("please input x:\n");
    scanf("%lf",&x);

    if(x>=0){y=pow(x,1/2.0);}    
    else{y=pow(x,5)+2*x+1/x;}

    printf("y=f(%f)=%.2f\n",x,y);

    return 0;
}