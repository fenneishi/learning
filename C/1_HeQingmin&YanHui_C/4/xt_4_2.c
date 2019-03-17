# include<stdio.h>
# include<math.h>


int main(void)
{
    int fact(int n);
    int i;
    double x,item;
    double sum(double x);

    printf("please input x:");
    scanf("%lf",&x);
    printf("the result of function(x) is :%.2f\n",sum(x));
    

    return 0;
}




int fact(int n){
    int res,i;
    res=1;
    for(i=1;i<=n;i++){
        res=res*i;
    }
    return res;
}


double sum(double x){
    int fact(int n);
    int i;
    double item,s;

    s =0;
    item = x;
    i=2;

    while(item>=0.00001){
        s = s +item;
        item = pow(x,i)/fact(i);   //可以正常调用fact，说明只要在main函数中声明fact后，这里也可以直接调用。
        i++;
    }
    return s;
}