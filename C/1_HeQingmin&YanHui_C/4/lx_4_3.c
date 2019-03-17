# include<stdio.h>
# include<math.h>



int main(void)
{
    int flag,denominator;
    double eps,item,s;



    printf("Enter eps:");
    scanf("%lf",&eps);

    s=0;
    item =1;
    flag =1;
    denominator=1;

    while(fabs(item)>=eps){                            /*题目要求是最后一项值小于eps,所以flag=-flag;denominator=denominator+3;这两条语句一定会被多执行一次*/
       item = flag*1.0/denominator;
       s=s+item;
       flag=-flag;
       denominator=denominator+3;
    }

    printf("eps is %f\n",eps);
    printf("s is %f\nitem is is %f=%d/%d\n",s,item,-flag,denominator-3);

    return 0;
}

