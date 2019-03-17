// 冒泡排序法，

# include<stdio.h>
# include<math.h>


// 计算两数字的和与差，并输出；

void sum_diff(double op1,double op2,double *psum,double *pdiff);

int main(void)
{   
    double op1,op2;
    double *psum,*pdiff;

    printf("the location of op1:%p\n",&op1);
    printf("the location of op2:%p\n",&op2);
    printf("the location of *psum:%p\n",psum);
    printf("the location of *pdiff:%p\n",pdiff);


    // printf("input op1 and op2:");
    // scanf("%lf%lf",&op1,&op2);

    // printf("befor sum_diff\n ");

    // sum_diff(op1,op2,psum,pdiff);

    // printf("the sum is %f\n",*psum);
    // printf("the diff is %f\n",*pdiff);

    // printf(" befor return 0 ");

    return 0;
}

void sum_diff(double op1,double op2,double *psum,double *pdiff)
{
    printf("befor firstline of sum_diff\n ");
    
    *psum = op1+op2;
    printf("befor op1-op2 in sum_diff\n ");
    *pdiff =op1-op2;

    printf("befor deadline of sum_diff\n ");
}