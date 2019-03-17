# include<stdio.h>
# include<math.h>

// 输入两个正整数，m和n,求其最大公约数和最小公倍数。

int main(void)
{
    int m,n,r,res_m,x;

    printf("please input M:");
    scanf("%d",&m);
    printf("please input N:");
    scanf("%d",&n);

    res_m=m;
    do{
        r = m%n;
        m=n;
        n=r;
    }
    while(r!=0);
    r=m;
    x=r*res_m;

    printf("最大公约数为：%d\n",r);
    printf("最小公倍数为：%d\n",x);


    return 0;
}

