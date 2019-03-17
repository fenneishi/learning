# include<stdio.h>
# include<math.h>



int main(void)
{
    int a,b,c,p;
    double area,per;

    printf("please input a:");
    scanf("%d",&a);
    printf("please input b:");
    scanf("%d",&b);
    printf("please input c:");
    scanf("%d",&c);

    if ((a+b)<c||((a-b)>c)||((b-a)>c))
        printf("not right a、b、c\n");
    else{
        p=(a+b+c)/2;
        per=2*p;
        area = pow(p*(p-a)*(p-b)*(p-c),0.5);
        printf("the area is %.2f\nthe perimeter is %.2f\n",area,per);
    }

    return 0;
}

